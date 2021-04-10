#include "specific.h"
#include "../assoc.h"


/*ripped from your lecture*/
int _hash(int cap, void *s);

void _insert(assoc* a, void* key, void* data);

void _chek_resize(assoc* a);

void _resize(assoc* a);

int _next_prime(int a);

bool _is_prime(int b);

void _rehash(assoc* a, pair* tmp, int oldcap);

void* _lookup(assoc* a, void* key);

void _print_hash(assoc *a);

void _insert_int(assoc* a, void* key, void* data);

bool _repeats(assoc *a, void *key);

bool _repeats_str(assoc *a, void *key);

bool _repeats_else(assoc *a, void *key);
/*
   Initialise the Associative arr
   keysize : number of bytes (or 0 => string)
   This is important when comparing keys since
   we'll need to use either memcmp() or strcmp()
*/
assoc* assoc_init(int keysize){
  assoc *f;
  if(keysize < 0){
    on_error("Invalid keysize at Initialise");
  }
  f = ncalloc(1, sizeof(struct assoc));
  f -> arr = ncalloc(ARRAYSIZE, sizeof(struct pair));
  f -> size = INITSIZE;
  f -> cap = ARRAYSIZE;
  f -> keysize = keysize;
  return f;
}
/*
   Insert key/data pair
   - may cause resize, therefore 'a' might
   be changed due to a realloc() etc.
*/
void assoc_insert(assoc** a, void* key, void* data){
   assoc *b = *a;
   if(key == NULL){
     on_error("key passed to assoc_insert is NULL");
   }
   if(b == NULL){
     on_error("value passed to assoc_insert\
               has been corrupted");
   }
  _chek_resize(b);
  _insert(b, key, data);
}
/*
   Returns the number of key/data pairs
   currently stored in the table
*/
unsigned int assoc_count(assoc* a){
  if(a == NULL){
    on_error("Struct is uninitialized");
  }
  return(a -> size);
}
/*
   Returns a pointer to the data, given a key
   NULL => not found
*/
void* assoc_lookup(assoc* a, void* key){
  void* i;
  if(key == NULL){
    on_error("key passed to lookup is NULL");
  }
  if(a == NULL){
    on_error("Struct passed to lookup has been NULL");
  }
  i = _lookup(a, key);
  return(i);
}
/* Free up all allocated space from 'a' */
void assoc_free(assoc* a){
  int i;
  if(a == NULL){
    on_error("Struct sent to assoc_free\
              is already free!\n");
  }
  for(i = 0; i < a -> cap; i++){
    a -> arr[i] . key = NULL;
    a -> arr[i] . data = NULL;
  }
  free(a -> arr);
  a -> size = 0;
  a -> cap = 0;
  a -> keysize = 0;
  free(a);
}
               /* AUX FUNCTIONS*/
void _insert(assoc* a, void* key, void* data){
  int hash = 0;
  int i;
  hash = _hash(a -> cap, key);
  /*checks for dups*/
  if(!_repeats(a, key)){
    if(a -> arr[hash] . key == NULL){
      a -> arr[hash] . key = key;
      a -> arr[hash] . data = data;
      a -> size = a -> size + 1;
    }
    /*this probe is increimenting by i*/
    else{
      for(i = 0; i < a -> cap; i++){
        hash += i;
        if(a -> arr[hash % a -> cap] . key == NULL){
          a -> arr[hash % a -> cap] . key = key;
          a -> arr[hash % a -> cap] . data = data;
          /*exits loop when free cell is found*/
          i = a -> cap;
          a -> size = a -> size + 1;
        }
      }
    }
  }
}

bool _repeats(assoc *a, void *key){
  if(a -> keysize == 0){
    return(_repeats_str(a, key));
  }
  else{
    return(_repeats_else(a, key));
  }
  return(false);
}

bool _repeats_else(assoc *a, void *key){
  int i;
  int hash = _hash(a -> cap, key);
  for(i = 0; i < a -> cap; i++){
    hash += i;
    if(a -> arr[hash % a -> cap] . key == NULL){
      return(false);
    }
    if(a -> arr[hash % a -> cap] . key != NULL){
      if(memcmp(key, a ->arr[hash % a -> cap] . key,\
         a -> keysize) == 0){
        return(true);
      }
    }
  }
  return(false);
}

bool _repeats_str(assoc *a, void *key){
  int i, hash = _hash(a -> cap, key);
  for(i = 0; i < a -> cap; i++){
    hash += i;
    if(a -> arr[hash % a -> cap] . key == NULL){
      return(false);
    }
    if(a ->arr[hash % a -> cap] . key != NULL){
      if(strcmp(key, a ->arr[hash % a -> cap] . key) == 0){
        return(true);
      }
    }
  }
  return(false);
}

void _chek_resize(assoc* a){
  if(a == NULL){
    on_error("A has become corrupted.\n\
              error from _chek_resize");
  }
  if(a -> size > (a -> cap) * SIX0PERCENT){
    _resize(a);
  }
}

void _resize(assoc* a){
  pair *tmp;
  int oldcap = a -> cap;
  /*find next prime*/
  a -> cap = _next_prime(a -> cap);
  tmp = ncalloc(a -> cap, sizeof(struct pair));
  /*this is over wrighting arr data that is being pointed\
    to by tmp*/
  _rehash(a, tmp, oldcap);
  free(a -> arr);
  a -> arr = tmp;
}
/*rehash tmp into a*/
void _rehash(assoc* a, pair* tmp, int oldcap){
  int hash, i, j;
  for(i = 0; i < oldcap; i++){
    if(a -> arr[i] . key != NULL){
      hash = _hash(a -> cap, a -> arr[i] . key);
      if(tmp[hash] . key == NULL){
        tmp[hash] . key = a -> arr[i] . key;
        tmp[hash] . data = a -> arr[i] . data;
      }
      /*this probe is increimenting by i*/
      else{
        for(j = 0; j < a -> cap; j++){
          hash += j;
          if(tmp[hash % a -> cap] . key == NULL){
            tmp[hash % a -> cap] . key = a -> arr[i] . key;
            tmp[hash % a -> cap] . data = a-> arr[i] . data;
            /*exits loop when free cell is found*/
            j = a -> cap;
          }
        }
      }
    }
  }
}

int _next_prime(int a){
  a *= FACTOR;
  do{
    if(_is_prime(a)){
      return(a);
    }
    else{
      a += 1;
    }
  }while(!_is_prime(a));
  return(a);
}

bool _is_prime(int b){
    int f_count = 0, i;

    for(i = 2; i<= b; i++){
        if(b % i ==0){
            f_count++;
        }
    }
    if(f_count == 1){
        return true;
    }
    else{
        return false;
    }
}

int _hash(int cap, void *s){
  unsigned long hash = 5381;
  int c;
  char* i = (char*)s;
  while((c = (*i++))){
    hash = 33 * hash ^ c;
  }
  return((int) (hash%cap));
}

void* _lookup(assoc* a, void* key){
  unsigned long hash = 0;
  int i;

  hash = _hash(a -> cap, key);
  if(a -> arr[hash] . key == NULL){
    return(NULL);
  }
  if(key == NULL){
      return(NULL);
  }
  if(strcmp((char*)a -> arr[hash] . key, (char*)key) == 0){
    return(a -> arr[hash] . data);
  }
  /*this probe is increimenting by i*/
  else{
    for(i = 0; i < a -> cap; i++){
      hash += i;
      if(a -> arr[hash] . key == NULL){
        return(NULL);
      }
      if(strcmp(a -> arr[hash] . key, key) == 0){
        return(a -> arr[hash % a -> cap] . data);
        /*exits loop when free cell is found*/
        i = a -> cap;
      }
    }
  }
  return(NULL);
}

void _print_hash(assoc *a){
  int i = 0, cnt = 0;
  while(i < a ->cap){
    printf("%s\n", (char*)a -> arr[i] . key);
    if(a -> arr[i] . key != NULL){
      cnt++;
    }
    i++;
  }
  printf("num of elements: %d\n", cnt);
}

/*testing seemed to be covered by your testassoc file\
so I have done litle testing*/
void _test(void){
  assoc *a;
  int b = 0, hash;
  char *key = "string";

  a = assoc_init(b);
  assert(a -> arr != NULL);
  assert(a -> arr -> key == NULL);
  assert(a -> size == INITSIZE);
  assert(a -> cap == ARRAYSIZE);
  assert(a -> keysize == b);
  hash = _hash(a -> cap, key);
  _insert(a, key, NULL);
  assert(assoc_count(a) == 1);
  assert(strcmp(a -> arr[hash] . key, "string") == 0);
  assoc_free(a);

}

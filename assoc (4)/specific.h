#include "../../../ADTs/General/bool.h"


#define ARRAYSIZE 17
#define INITSIZE 0
#define SIX0PERCENT 0.6
#define FACTOR 2
typedef struct pair{
  void* key;
  void* data;
}pair;

typedef struct assoc{
  struct pair* arr;
  int size;
  int cap;
  int keysize;
}assoc;

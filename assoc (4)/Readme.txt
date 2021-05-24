Here we write an implementation of a polymorphic associative array using
hashing, see assoc.h. Both the key & data to be used by the hash function are of unknown
types, so we will simply store void pointers to both of these, and the user of the associative
array (and not the ADT itself) will be responsible for creating and maintaining such memory,
and also ensuring it doesn’t change when in use by the associative array. In the testassoc.c
file we show two uses for such a type : a simple string example (to find the longest word in
English that is also a valid (but different) word when spelled backwards), and a simple integer
example where we keep a record of how many unique random numbers in a range are chosen.
Since we do not know what the type of the key is, we need to be careful when comparing
or copying keys. Therefore, in the assoc_init(int keysize) function, the user has to
pass the size of the key used (e.g. sizeof(int)) or in the case or strings, the special value 0.
Now we can use memcmp() and memcpy(), or in the case of strings, strcmp() and strcpy()
for dealing with the keys. In the case of data, the ADT only ever needs to return a pointer to
the data (not process it) via assoc_lookup(), so its size is not important.
Your hash table used to implement the ADT should be resizeable, and you may use openaddressing/double-hashing or separate chaining to deal with collisions. Make no assumptions
about the maximum size of the array, and make the initial size of the array small e.g. 16 or 17
(a prime is useful if you’re double hashing).. You can use any hash function you wish, but if
it’s off the internet (etc.) cite the source in a comment..
Submit a single assoc.zip file containing your code. Your standard submission will
contain the directory structure, including the two files:
Realloc/specific.h and Realloc/realloc.c. I will use my assoc.mk Makefile to
compile your code, so check that it works correctly.

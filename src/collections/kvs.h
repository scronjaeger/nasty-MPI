#ifndef __KVS_H
#define __KVS_H

#include <stdlib.h>

typedef struct KVentry
{
  char *key;
  void *value;
} *KVentry;

typedef void (*kvs_value_free_fn) (void *data);

#define DEFAULT_EXPAND_RATE 10

typedef struct KVstore
{
  KVentry *pairs;
  int size;
  int capacity;
  size_t expand_rate;
  kvs_value_free_fn value_free_fn;
} *KVstore;

KVstore kvs_create(size_t initial_capacity, size_t expand_rate, kvs_value_free_fn value_free_fn);

void kvs_clear(KVstore store);
void kvs_destroy(KVstore store);
void kvs_clear_destroy(KVstore store);

int kvs_put(KVstore store, char *key, void *value);

void* kvs_remove(KVstore store, char *key);

void *kvs_get(KVstore store, char *key);

#define kvs_last(A) ((A)->contents[(A)->size - 1])
#define kvs_first(A) ((A)->contents[0])
#define kvs_end(A) ((A)->size)
#define kvs_count(A) DArray_end(A)
#define kvs_capacity(A) ((A)->capacity)

#endif /* #define __KVS_H__ */

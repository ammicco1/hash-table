#include <stdlib.h>
#include <string.h>

#define HASHMAP_LENGHT 256

struct hashmap_element{
    int key; 
    void *value;
};

struct hashmap{
    struct hashmap_element **buckets;
};

int hash_function(int key);

struct hashmap *hashmap_initialize(int key, void *value, size_t value_len);

struct hashmap_element *hashmap_search(struct hashmap *map, int key);

int hashmap_insert(struct hashmap *map, int key, void *value, size_t value_len);

int hashmap_delete(struct hashmap *map, int key);
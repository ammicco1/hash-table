#include "hashmap.h"
#include <string.h>

int hash_function(int key){
    return key % HASHMAP_LENGHT;
}

struct hashmap *hashmap_initialize(int key, void *value, size_t value_len){
    int i;
    struct hashmap *hm = malloc(sizeof(struct hashmap));

    hm -> buckets = (struct hashmap_element **) malloc(sizeof(struct hashmap_element *) * HASHMAP_LENGHT);

    for(i = 0; i < HASHMAP_LENGHT; i++){
        hm -> buckets[i] = (struct hashmap_element *) malloc(sizeof(struct hashmap_element));
    }
 
    i = hash_function(key);

    hm -> buckets[i] -> key = key;

    hm -> buckets[i] -> value = malloc(value_len);
    memcpy(hm -> buckets[i] -> value, value, value_len);

    return hm;
}

struct hashmap_element *hashmap_search(struct hashmap *map, int key){
    return map -> buckets[hash_function(key)];
}

int hashmap_insert(struct hashmap *map, int key, void *value, size_t value_len){
    int i = hash_function(key);

    map -> buckets[i] -> key = key;

    map -> buckets[i] -> value = malloc(value_len);
    memcpy(map -> buckets[i] -> value, value, value_len);

    return 0;
}

int hashmap_delete(struct hashmap *map, int key){
    int i = hash_function(key);

    if(map -> buckets[i] -> value){
        free(map -> buckets[i] -> value);

        return 0;
    }

    return 1;
}
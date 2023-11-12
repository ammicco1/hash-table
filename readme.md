# Hashmap

Simple C implementation of a hashmap.
The hashmap is defined with two structs of the type: 
```c
struct hashmap_element{
    int key; 
    void *value;
};

struct hashmap{
    struct hashmap_element **buckets;
};
```

Where:
 - hashmap_element contains: 
   - key is an integer value
   - value can be everything. In main.c it can be a string  
 - hasmap contains:
   - an array of hashmap_element

The hashmap size is defined in the **HASHMAP_LENGHT** const.

The hash function is: 
```c
int hash_function(int key){
    return key % HASHMAP_LENGHT;
}
```

There are 4 basic operation: 
 - initialize, that create the hashmap
 - insert, to insert a new value
 - delete, to delete a value by key
 - search, to search a value by key 

In this example you can not insert different nodes with the same key. 

Try it with: 
```bash
$ make 
$ ./main
```

Or include it in your projects. 

Enjoy :) 
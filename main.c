#include "hashmap.h"
#include <stdio.h>

int main(int argc, char **argv){
    struct hashmap *my_map; 
    struct hashmap_element *tmp;
    int choice = 0;
    int key; 
    char *buff = (char *) malloc(sizeof(char) * 256);

    printf("HASHMAP TESTING\n--------------------------\nInitilize the List. First key: ");
    scanf(" %d", &key);  
    printf("First value (str): ");
    scanf(" %s", buff);

    my_map = hashmap_initialize(key, buff, sizeof(char) * strlen(buff) + 1);

    while(1){
        printf("\nSelect an action:\n - 1: Insert a value\n - 2: Delete a value\n - 3: Search a value\n\n");
        scanf(" %d", &choice);

        switch(choice){
            case 1: 
                printf("Key: "); 
                scanf(" %d", &key); 
                
                printf("Value (str): "); 
                scanf(" %s", buff); 

                if(hashmap_search(my_map, key) -> value){
                    fprintf(stderr, "\nInsert error - already used key\n");
                    break;
                }
                
                if(hashmap_insert(my_map, key, buff, sizeof(char) * strlen(buff) + 1) == 0){
                    printf("\nInsert ok\n");
                }else{
                    fprintf(stderr, "\nInsert error\n");
                }
                
                break;
            case 2: 
                printf("Key: ");
                scanf(" %d", &key);

                if(!hashmap_search(my_map, key)){
                    fprintf(stderr, "\nDelete error - no node with this key\n");
                    break;
                }

                if(hashmap_delete(my_map, key) == 0){
                    printf("\nDelete ok\n");
                }else{
                    fprintf(stderr, "\nDelete error\n");
                }

                break;
            case 3:
                printf("Key: ");
                scanf(" %d", &key);

                tmp = hashmap_search(my_map, key);

                if(tmp){
                    printf("\n%d -> %s\n", tmp -> key, (char *) tmp -> value);
                }else{
                    fprintf(stderr, "\nSearch error\n");
                }

                break;
        }
    }

}
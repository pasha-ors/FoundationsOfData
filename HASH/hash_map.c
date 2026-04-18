#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

typedef struct HashMap {
    Node** buckets;
    int size;
} HashMap;

HashMap* create_hashmap(int size){
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));

    if (map == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    map->size = size;
    map->buckets = (Node**)malloc(sizeof(Node*) * size);

    if (map->buckets == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        map->buckets[i] = NULL;
    }

    return map;
}

void put(HashMap* map, const char* key, int value){
    unsigned int index = hash(key, map->size);

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = map->buckets[index];
    map->buckets[index] = new_node;
}

int get(HashMap* map, const char* key) {
    unsigned int index = hash(key, map->size);
    Node* node = map->buckets[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0)
            return node->value;
        node = node->next;
    }
    return -1;
}

void delete(HashMap* map, const char* key){
    unsigned int index = hash(key, map->size);
    Node* node = map->buckets[index];
    Node* prev = NULL;

    while(node != NULL){
        if (strcmp(node->key, key) == 0){
            if(prev == NULL){
                map->buckets[index] = node->next;
            }else{
                prev->next = node->next;
            }

            free(node->key);
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

void free_hashmap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        Node* node = map->buckets[i];
        while (node != NULL) {
            Node* tmp = node;
            node = node->next;
            free(tmp->key);
            free(tmp);
        }
    }
    free(map->buckets);
    free(map);
}

int main() {
    HashMap* map = create_hashmap(10);

    put(map, "apple", 5);
    put(map, "banana", 10);
    put(map, "orange", 7);

    printf("apple = %d\n", get(map, "apple"));
    printf("banana = %d\n", get(map, "banana"));
    printf("orange = %d\n", get(map, "orange"));

    delete(map, "banana");
    printf("banana = %d\n", get(map, "banana"));

    free_hashmap(map);
    return 0;
}


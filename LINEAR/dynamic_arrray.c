#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createArray(int initial_capacity){

    DynamicArray* array = malloc(sizeof(DynamicArray));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    array->data = malloc(initial_capacity * sizeof(int));
    if (array->data == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    array->size = 0;
    array->capacity = initial_capacity;

    return array;
}

void append(DynamicArray *arr, int value){
    if(arr->size == arr->capacity){
        // Resize
        arr->capacity *= 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
        if (arr->data == NULL) {
            printf("Re-allocation failed!\n");
            exit(1);
        }
    }
    arr->data[arr->size] = value; // or arr->data[arr->size++] = value;
    arr->size += 1;
}

void deleteAt(DynamicArray *arr, int index){
    if(index < 0 || index >= arr->size){
        return;
    }

    for(int i = index; i < arr->size - 1; i++){
        arr->data[i] = arr->data[i+1];
    }

    arr->size--;
}

void printArray(DynamicArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void freeArray(DynamicArray *arr){
    free(arr->data);
    free(arr);
}

int main() {
    DynamicArray *arr = createArray(2);

    append(arr, 10);
    append(arr, 20);
    append(arr, 30);
    append(arr, 40);

    printArray(arr); // 10 20 30 40

    deleteAt(arr, 1);
    printArray(arr); // 10 30 40

    freeArray(arr);
    return 0;
}
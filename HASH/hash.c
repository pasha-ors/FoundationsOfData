#include "hash.h"

unsigned int hash(const char* key, int size) {
    unsigned long int hash = 0;
    int i = 0;
    while (key[i] != '\0') {
        hash = hash * 31 + key[i];
        i++;
    }
    return hash % size;
}
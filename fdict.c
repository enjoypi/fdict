#include "fdict.h"

typedef struct fdict
{

size_t bucket_amount;
size_t bucket_size;

size_t key_size;
size_t max_key_amount;
size_t value_size;
size_t max_key_amount;

void* data;
} fdict;

size_t fdict_capacity(size_t key_size, size_t max_key_amount, size_t value_size, size_t max_value_amount) {
    return key_size * max_key_amount + value_size * max_value_amount + sizeof(fdict);
}

fdict* fdict_new(size_t key_size, size_t max_key_amount, size_t value_size, size_t max_value_amount, void* mem, size_t mem_capacity) {
    size_t capacity = fdict_capacity(key_size, max_key_amount, value_size, max_key_amount);
    if (capacity != mem_capacity) {
        return NULL;
    }

    memset(mem, 0, mem_capacity);
    fdict* dict = (fdict*) mem;
    dict->data = mem + sizeof(fdict);
    dict->bucket_size = 8;
    dict->bucket_amount = max_key_amount / dict->bucket_size;
}

void* fdict_find(fdict*, void* key, size_t key_size);

void* fdict_set(fdict*, void* key, size_t key_size, size_t value_size, size_t max_value);

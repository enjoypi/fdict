#ifndef FDICT_H
#define FDICT_H

#include <stddef.h>

typedef struct fdict fdict;

size_t fdict_usage(size_t key_size, size_t max_key, size_t value_size, size_t max_value);

fdict* fdict_new(size_t key_size, size_t max_key, size_t value_size, size_t max_value, void* mem);

void* fdict_find(fdict*, void* key, size_t key_size);


#endif

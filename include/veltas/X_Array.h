#ifndef VELTAS_X_ARRAY_H_INCLUDED
#define VELTAS_X_ARRAY_H_INCLUDED

#include <stddef.h>

void * X_Array_alloc(size_t element_size);

size_t X_Array_size(void *x_array);

void * X_Array_expand(void *x_array, size_t expand_amount);

void * X_Array_clear(void *x_array);

void X_Array_free(void *x_array);

int X_Array_empty(void *x_array);

/* VELTAS_XARRAY_H_INCLUDED */
#endif

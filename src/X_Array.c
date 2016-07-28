#include <veltas/X_Array.h>

#include <stdlib.h>
#include <stdnoreturn.h>
#include <stdalign.h>
#include <stdio.h>

#define S_(x) #x
#define S(x) S_(x)
#define ERROR(msg) array_error(__FILE__ ":" S(__LINE__) ": " msg)
#define GET_INTERNALS(ptr) \
	((struct array_internals *)( \
		(unsigned char *)(ptr) - offsetof(struct array_internals, array) \
	))

static noreturn void array_error(const char *const msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	fflush(stderr);
	abort();
}

struct array_internals {
	size_t element_size,
	       capacity,
	       length;
	alignas(max_align_t) unsigned char array[];
};

void * X_Array_alloc(const size_t element_size)
{
	struct array_internals *const internals = malloc(sizeof *internals);
	if (!internals) ERROR("Failed to allocate X_Array");
	*internals = (struct array_internals) {
		.element_size = element_size,
		.capacity     = 0,
		.length       = 0
	};
	return &internals->array;
}

size_t X_Array_size(void *const x_array)
{
	return GET_INTERNALS(x_array)->length;
}

void * X_Array_expand(void *const x_array, const size_t expand_amount)
{
	struct array_internals *internals = GET_INTERNALS(x_array);
	if (expand_amount > internals->capacity - internals->length) {
		const size_t cap_expand = expand_amount + internals->length - internals->capacity;
		const size_t current_cap = internals->capacity;
		if (current_cap + cap_expand > 2 * current_cap) {
			internals = realloc(
				internals,
				sizeof *internals + (current_cap + cap_expand) * internals->element_size
			);
			if (!internals) ERROR("Failed to reallocate X_Array contents");
			internals->capacity = current_cap + expand_amount;
		} else {
			internals = realloc(
				internals,
				sizeof *internals + 2 * current_cap * internals->element_size
			);
			if (!internals) ERROR("Failed to reallocate X_Array contents");
			internals->capacity = 2 * current_cap;
		}
	}
	internals->length += expand_amount;
	return &internals->array;
}

void * X_Array_clear(void *const x_array)
{
	const size_t element_size = GET_INTERNALS(x_array)->element_size;
	X_Array_free(x_array);
	return X_Array_alloc(element_size);
}

void X_Array_free(void *const x_array)
{
	free(GET_INTERNALS(x_array));
}

int X_Array_empty(void *const x_array)
{
	return GET_INTERNALS(x_array)->length == 0;
}

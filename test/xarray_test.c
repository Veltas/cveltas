#include <veltas/X_Array.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(void)
{
	int *stuff;
	size_t i, current;

	puts("allocation");
	stuff = X_Array_alloc(sizeof *stuff);

	puts("expand 1");
	stuff = X_Array_expand(stuff, 1);

	puts("expand 10000");
	stuff = X_Array_expand(stuff, 10000);

	puts("expand 1");
	stuff = X_Array_expand(stuff, 1);

	puts("assign to array");
	current = X_Array_size(stuff);
	for (i = 0; i < current; ++i) {
		stuff[i] = 555;
	}

	puts("size");
	assert(X_Array_size(stuff) == 10002);

	puts("clear");
	stuff = X_Array_clear(stuff);

	puts("expand 1");
	stuff = X_Array_expand(stuff, 1);

	puts("expand 100000");
	stuff = X_Array_expand(stuff, 100000);

	puts("expand 90000");
	stuff = X_Array_expand(stuff, 90000);

	puts("assign to array");
	current = X_Array_size(stuff);
	for (i = 0; i < current; ++i) {
		stuff[i] = 555;
	}

	puts("size");
	assert(X_Array_size(stuff) == 190001);

	puts("free");
	X_Array_free(stuff);

	return 0;
}

#include <veltas/io.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

int main(void)
{
	FILE *input;
	char read_buf[12];

	puts("Check file io_test.dat");
	input = fopen("io_test.dat", "r");
	assert(input);

	assert(!read_prompt(read_buf, sizeof read_buf, input));
	assert(!strcmp(read_buf, "====="));

	assert(!read_prompt(read_buf, sizeof read_buf, input));
	assert(!strcmp(read_buf, "=========="));

	assert(read_prompt(read_buf, sizeof read_buf, input) == read_prompt_overflow);

	assert(!read_prompt(read_buf, sizeof read_buf, input));
	assert(!strcmp(read_buf, "====="));

	assert(!read_prompt(read_buf, sizeof read_buf, input));
	assert(!strcmp(read_buf, "=========="));

	assert(read_prompt(read_buf, sizeof read_buf, input) == read_prompt_eof);

	fclose(input);

	puts("Check file io_test2.dat");
	input = fopen("io_test2.dat", "r");
	assert(input);

	assert(read_prompt(read_buf, sizeof read_buf, input) == read_prompt_eof);

	puts("Check file io_test3.dat");
	input = fopen("io_test3.dat", "r");
	assert(input);

	assert(!read_prompt(read_buf, sizeof read_buf, input));
	assert(!strcmp(read_buf, "====="));

	assert(read_prompt(read_buf, sizeof read_buf, input) == read_prompt_eof);

	return 0;
}

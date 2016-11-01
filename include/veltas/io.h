#ifndef VELTAS_IO_H_INCLUDED
#define VELTAS_IO_H_INCLUDED

#include <stddef.h>
#include <stdio.h>

int ignore_to_chr(char chr, FILE *in_file);

int ignore_until_chr(char chr, FILE *in_file);

enum {
	read_prompt_success = 0,
	read_prompt_eof,
	read_prompt_overflow
};

int read_prompt(char *read_buf, size_t buf_size, FILE *in_file);

#endif /* VELTAS_IO_H_INCLUDED */

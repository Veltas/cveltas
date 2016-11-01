#include <veltas/io.h>

#include <stdio.h>
#include <string.h>

int ignore_to_chr(const char chr, FILE *const in_file)
{
	int read_value;
	do {
		read_value = fgetc(in_file);
		if (read_value == EOF) return 1;
	} while (read_value != chr);
	return 0;
}

int ignore_until_chr(const char chr, FILE *const in_file)
{
	if (!ignore_to_chr(chr, in_file)) {
		ungetc(chr, in_file);
		return 0;
	}
	return 1;
}

int read_prompt(char *read_buf, const size_t buf_size, FILE *const in_file)
{
	read_buf = fgets(read_buf, buf_size, in_file);
	if (!read_buf) return read_prompt_eof;
	char *const newline_ptr = strchr(read_buf, '\n');
	if (newline_ptr) {
		*newline_ptr = 0;
	} else {
		if (ignore_to_chr('\n', in_file)) return read_prompt_eof;
		else return read_prompt_overflow;
	}
	return 0;
}

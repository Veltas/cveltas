#include <veltas/error.h>

#include <stdlib.h>
#include <stdio.h>

void veltas_error(const char *const error_message)
{
	fputs(error_message, stderr);
	fputc('\n', stderr);
	fflush(stderr);
	abort();
}

#ifndef VELTAS_ERROR_H_INCLUDED
#define VELTAS_ERROR_H_INCLUDED

#include "defs.h"

#ifndef ERROR
#define ERROR(msg) veltas_error(__FILE__ ":" SLING(__LINE__) ": " msg)
#endif

#ifndef ASSERT
#define ASSERT(test) { if (!(test)) ERROR("Assert failed ... " #test); }
#endif

void veltas_error(const char *error_message);

#endif /* VELTAS_ERROR_H_INCLUDED */

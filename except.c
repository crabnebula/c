#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "except.h"

#define T Except_T

Except_Frame *Except_stack = NULL;

void Except_raise(const T *e, const char *file, int line) {
	Except_Frame *p = Excpet_stack;
	assert(e);
	if (p == NULL)
		fprintf(stderr, "Uncaught exception");	
	if (e->reason)
		fprintf(stderr, " %s", e->reason);
	else
		fprintf(stderr, " raised at %s:%d\n", file, line);
	fprintf(stderr, "aborting...\n");
	fflush(stderr);
	abort();
}

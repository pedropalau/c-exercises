#ifndef C_MEMORY

#define C_MEMORY

#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

/*@out@*/ /*@notnull@*/ void *memory_alloc(size_t size)
{
	void *alloc = (void *) malloc(size);
	if (alloc == NULL)
	{
		fprintf(stderr,
		        "Fatal: not possible to allocate requested memory size"
		        "of %lu bytes).\n",
		        (long unsigned int) size);
		exit(EXIT_FAILURE);
	}
	return alloc;
}

/*@out@*/ /*@notnull@*/ void *memory_alloc_z(size_t size)
{
	void *alloc = memory_alloc(size);
	memset(alloc, 0, size);
	return alloc;
}

#endif

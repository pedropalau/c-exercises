#ifndef C_MEMORY_H

#define C_MEMORY_H

extern /*@unused@*/ /*@out@*/ /*@notnull@*/ void *memory_alloc(size_t size);

extern /*@unused@*/ /*@out@*/ /*@notnull@*/ void *memory_alloc_z(size_t size);

extern /*@unused@*/ /*@out@*/ /*@notnull@*/ void *
memory_realloc(/*@in@*/ /*@only@*/ void *pointer, size_t new_size);

#endif

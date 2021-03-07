/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "vector.h"

/* Define what our struct is */
struct vector_t {
    size_t size;
    int *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new vector */
vector_t *bad_vector_new() {
    /* Create the vector and a pointer to it */
    vector_t *retval, v;
    retval = &v;

    /* Initialize attributes */
    retval->size = 1;
    retval->data = malloc(sizeof(int));
    if (retval->data == NULL) {
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}

/* Another suboptimal way of creating a vector */
vector_t also_bad_vector_new() {
    /* Create the vector */
    vector_t v;

    /* Initialize attributes */
    v.size = 1;
    v.data = malloc(sizeof(int));
    if (v.data == NULL) {
        allocation_failed();
    }
    v.data[0] = 0;
    return v;
}

/* Create a new vector with a size (length) of 1
   and set its single component to zero... the
   RIGHT WAY */
vector_t *vector_new() {
    /* Declare what this function will return */
    vector_t *retval;

    /* First, we need to allocate memory on the heap for the struct */
    retval =  (struct vector_t*) malloc(sizeof(struct vector_t));

    /* Check our return value to make sure we got memory */
    if (retval==NULL) {
        allocation_failed();
    }

    /* Now we need to initialize our data.
       Since retval->data should be able to dynamically grow,
       what do you need to do? */
    retval->size = 1;
    retval->data =(int*) malloc(sizeof(int));;

    /* Check the data attribute of our vector to make sure we got memory */
    if (retval->data==NULL) {
        free(retval);				//Why is this line necessary?_it's dynamically allocated, it won't disappear unless we free it
        allocation_failed();
    }

    /* Complete the initialization by setting the single component to zero */
    retval->data[0] = 0;

    /* and return... */
    return retval;
}

/* Return the value at the specified location/component "loc" of the vector */
int vector_get(vector_t *v, size_t loc) {

    /* If we are passed a NULL pointer for our vector, complain about it and exit. */
    if(v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    /* If the requested location is higher than we have allocated, return 0.
     * Otherwise, return what is in the passed location.
     */
    if (loc < v->size) {
        return v->data[loc];
    } else {
        return 0;
    }
}

/* Free up the memory allocated for the passed vector.
   Remember, you need to free up ALL the memory that was allocated. */
void vector_delete(vector_t *v) {
    /* YOUR SOLUTION HERE */
    free(v->data);
    free(v);
}

/* Set a value in the vector. If the extra memory allocation fails, call
   allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
    /* What do you need to do if the location is greater than the size we have
     * allocated?  Remember that unset locations should contain a value of 0.
     */

    /* YOUR SOLUTION HERE */
    //like vector_get
    if(v == NULL) 
    {
        fprintf(stderr, "vector_set: passed a NULL vector.\n");
        abort();
    }

    // Resize
    if (loc >= v->size)
    {
        int size_new = loc+1;

        v->data = (int*) realloc(v->data, size_new*sizeof(int));
        for (int i = v->size; i < size_new; i++)
        {
            v->data[i] = 0;
        } 
        v->size = size_new;
        v->data[loc] = value;
    }
    else
    {
        v->data[loc] = value;
    }
}

//Test Output
/*
adonis@ubuntu:~/Desktop/lab2$ make vector-memcheck
valgrind --tool=memcheck --leak-check=full --track-origins=yes ./vector-test
==4205== Memcheck, a memory error detector
==4205== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4205== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==4205== Command: ./vector-test
==4205== 
Calling vector_new()
Calling vector_delete()
vector_new() again
These should all return 0 (vector_get()): 0 0 0
Doing a bunch of vector_set()s
These should be equal:
98 = 98
15 = 15
65 = 65
-123 = -123
21 = 21
43 = 43
0 = 0
0 = 0
0 = 0
3 = 3
Test complete.
==4205== 
==4205== HEAP SUMMARY:
==4205==     in use at exit: 0 bytes in 0 blocks
==4205==   total heap usage: 9 allocs, 9 frees, 3,280 bytes allocated
==4205== 
==4205== All heap blocks were freed -- no leaks are possible
==4205== 
==4205== For lists of detected and suppressed errors, rerun with: -s
==4205== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/
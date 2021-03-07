//
// Created by ethan on 2021/3/7.
//
#include <stdlib.h>
#include <stdio.h>

#include "vector.h"


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

int* test()
{
    int tt[10];
    for (int i = 0; i < 10; ++i) {
        tt[i] = i;
    }
    int* tt1 = &tt[0];
    return tt1;
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


int main()
{
    vector_t v;

    printf("Calling bad_vector_new()\n");
    v = bad_vector_new();
/*    int* temp = v->data;
    int temp1 = *v->data;
    int temp2 = v->size;
*/

    printf("YES!\n");

    /*int* tt_main = test();

    printf("%d", *tt_main);*/
    printf("Calling also_bad_vector_new()\n");
    v = also_bad_vector_new();


    int* temp = v.data;

    printf("YES!\n");
}


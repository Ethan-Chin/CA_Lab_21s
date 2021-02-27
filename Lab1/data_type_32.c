#include <stdio.h>
#include <stdint.h>
#include <time.h>
#define GET_SIZE(data_type) printf("Size of "#data_type": %d\n", sizeof(data_type))



int main() {
    GET_SIZE(char);
    GET_SIZE(short);
    GET_SIZE(short int);
    GET_SIZE(int);
    GET_SIZE(long int);
    GET_SIZE(unsigned int);
    GET_SIZE(void*);
    GET_SIZE(size_t);
    GET_SIZE(float);
    GET_SIZE(double);
    GET_SIZE(int8_t);
    GET_SIZE(int16_t);
    GET_SIZE(int32_t);
    GET_SIZE(int64_t);
    GET_SIZE(time_t);
    GET_SIZE(clock_t);
    GET_SIZE(struct tm);
    GET_SIZE(NULL);

    return 0;
}

#include "communication.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* producer1(void* arg) {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int num = (rand() % 100) * 2 + 1;  // Genera números impares
        produce_data((void*)&num, PRODUCER1);  // Casting a void*
    }
    return NULL;
}

#include "communication.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* producer3(void* arg) {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        float num = ((float)rand() / RAND_MAX) * 100;  // Genera números flotantes
        produce_data((void*)&num, PRODUCER3);  // Casting a void*
    }
    return NULL;
}

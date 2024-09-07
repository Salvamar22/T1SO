#include "communication.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* producer2(void* arg) {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int num = (rand() % 100) * 2;  // Genera números pares
        produce_data((void*)&num, PRODUCER2);  // Casting a void*
    }
    return NULL;
}

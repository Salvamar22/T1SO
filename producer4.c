#include "communication.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* producer4(void* arg) {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        char ch = 'A' + (rand() % 26);  // Genera caracteres aleatorios
        produce_data((void*)&ch, PRODUCER4);  // Casting a void*
    }
    return NULL;
}

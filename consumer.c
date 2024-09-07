#include "communication.h"
#include <stdio.h>

void* consumer(void* arg) {
    for (int i = 0; i < 400; i++) {  // Lee 400 datos en total (100 por cada productor)
        void* data = consume_data();

        // Dependiendo del tipo de productor, el dato puede ser int, float o char.
        if (i < 100) {  // Datos del producer1 (impares)
            int* num = (int*)data;
            printf("Consumiendo dato: %d (Impar)\n", *num);
        } else if (i < 200) {  // Datos del producer2 (pares)
            int* num = (int*)data;
            printf("Consumiendo dato: %d (Par)\n", *num);
        } else if (i < 300) {  // Datos del producer3 (flotantes)
            float* num = (float*)data;
            printf("Consumiendo dato: %.2f (Flotante)\n", *num);
        } else {  // Datos del producer4 (caracteres)
            char* ch = (char*)data;
            printf("Consumiendo dato: %c (Carácter)\n", *ch);
        }
    }
    return NULL;
}

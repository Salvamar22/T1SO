#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "communication.h"

void* producer1(void* arg);
void* producer2(void* arg);
void* producer3(void* arg);
void* producer4(void* arg);
void* consumer(void* arg);

int main() {
    pthread_t tid1, tid2, tid3, tid4, tid_consumer;

    init_communication();  // Inicializa la memoria compartida y los semáforos

    // Crear los hilos para cada productor
    pthread_create(&tid1, NULL, producer1, NULL);
    pthread_create(&tid2, NULL, producer2, NULL);
    pthread_create(&tid3, NULL, producer3, NULL);
    pthread_create(&tid4, NULL, producer4, NULL);
    
    // Crear el hilo para el consumidor
    pthread_create(&tid_consumer, NULL, consumer, NULL);

    // Esperar a que los hilos terminen
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    pthread_join(tid_consumer, NULL);

    destroy_communication();  // Libera memoria compartida y semáforos

    return 0;
}

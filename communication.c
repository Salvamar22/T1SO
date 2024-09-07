#include "communication.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 100

void* buffer[BUFFER_SIZE];
int count = 0;

pthread_mutex_t mutex;
pthread_cond_t cond_produce;
pthread_cond_t cond_consume;

void init_communication() {
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_produce, NULL);
    pthread_cond_init(&cond_consume, NULL);
}

void destroy_communication() {
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_produce);
    pthread_cond_destroy(&cond_consume);
}

void produce_data(void* data, int producer_id) {
    pthread_mutex_lock(&mutex);

    while (count == BUFFER_SIZE) {  // Espera si el buffer está lleno
        pthread_cond_wait(&cond_produce, &mutex);
    }

    buffer[count] = data;
    count++;

    pthread_cond_signal(&cond_consume);  // Notifica al consumidor
    pthread_mutex_unlock(&mutex);
}

void* consume_data() {
    pthread_mutex_lock(&mutex);

    while (count == 0) {  // Espera si el buffer está vacío
        pthread_cond_wait(&cond_consume, &mutex);
    }

    void* data = buffer[--count];

    pthread_cond_signal(&cond_produce);  // Notifica a los productores
    pthread_mutex_unlock(&mutex);

    return data;
}

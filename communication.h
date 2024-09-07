#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#define PRODUCER1 1
#define PRODUCER2 2
#define PRODUCER3 3
#define PRODUCER4 4

void init_communication();
void destroy_communication();
void produce_data(void* data, int producer_id);
void* consume_data();

#endif

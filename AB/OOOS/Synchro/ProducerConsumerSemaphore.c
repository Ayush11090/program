//Producer and consumer using semaphore

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define buffersize 5


sem_t empty;
sem_t full;
int in = 0, out = 0;
int buffer[buffersize];
void *producer()
{
int data, temp;
temp = rand()%3;
while(1)
{
data = rand()%100;
sleep(temp);
sem_wait(&empty);
buffer[in] = data;
printf("\n\nProducer Inserted Data %d at %d",data,in);
in = (in+1)%buffersize;
sem_post(&full);
}
}
void *consumer()
{
int temp, data;
temp = rand()%5;

while(1)
{
sleep(temp);
sem_wait(&full);
data = buffer[out];
printf("\n\nConsumer Consumed Data %d from %d",data,out);
out = rand()%buffersize;
sem_post(&empty);
}
}
int main()
{
pthread_t prod, cons;
sem_init(&empty, 0, buffersize);
sem_init(&full, 0, 0);
pthread_create(&prod, NULL, &producer, NULL);
pthread_create(&cons, NULL, &consumer, NULL);
pthread_join(prod, NULL);
pthread_join(cons, NULL);
return 0;
}

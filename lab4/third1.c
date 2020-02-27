#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define N 10     //Number of slots in buffer
typedef int semaphore;  //Semaphores ae a special kind of int
sem_t mutex; //Controls access to critical region 1
sem_t empty;  //Counts empty buffer slots N
sem_t  full;  //Counts full buffer slots 0
int count = 0; //What we're putting in 
//int buffer[N];

void producer(void) {
    sem_init(&mutex, 0, 1);
    //sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);

    while(1) { 
        sem_wait(&empty);
        sem_wait(&mutex);
        //printf("Empy: %d\n",empty);
        //printf("Mutex: %d\n",mutex);
        //printf("Both Downs Ran\n");
        //buffer = buffer + 1;
        sem_post(&mutex);
        sem_post(&full);
        //printf("Producer produced: %d\n",buffer);
    }
}

void consumer(void) {
    while(1) { 
        sem_wait(&full);
        sem_wait(&mutex);
        //item = buffer;
        sem_post(&mutex);
        sem_post(&empty);
        //printf("Consumer consumed: %d/n",item);
    }
}

void main() {

}
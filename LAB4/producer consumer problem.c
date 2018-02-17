/*
   Hardik Rana
   
   producer consumer problem
   
*/

#include<stdio.h>
#include<string.h>

// pthread support library
#include<pthread.h>
// semaphore support library
#include<semaphore.h>

// buffer size count
#define N 5

// buffer
int buffer[N];

int in = 0, out = 0;


// semaphores for producer consumer problem
sem_t mutex, full, empty;


/**
 *  initialize semaphore varilables
 */
void initSemaphores() {

    // sem_init(semaphore variable reference, 0 to share semaphore between all threads, inital value)

    // mutex (mutual exclusion) variable
    sem_init(&mutex, 0, 1);

    // full check semaphore
    sem_init(&full, 0, 1);

    // empty check semaphore
    sem_init(&empty, 0, N);
}



/**
 *  Procuder program with semaphores
 */
void *producer() {

    // run finite length
    int i;
    for (i = 0; i < 10; i++) {

        // check for full buffer
        // if buffer is full then put this process in sleep queue
        // else add a item by using mutex semaphore
        sem_wait(&empty);

        // check whether any other process is accessing buffer
        // if yes put this process to sleep
        // else add the element to the buffer
        sem_wait(&mutex);

        // produced item
        printf("Produced item is: %d\n",i);

        // add element to the buffer
        buffer[in] = i;
        in = (in + 1) % N;
        sleep(1);

        // free the mutex semaphore and and wake up a process in the sleep queue
        sem_post(&mutex);

        // increment the full semaphore indicating the addition of new element to the buffer is complete
        sem_post(&full);

    }

}



/**
 *  Consumer program with semaphores
 */
void *consumer() {

    int item;

    // run finite length
    int i;
    for (i = 0; i < 10; i++) {

        // check for empty buffer
        // if buffer is empty then put this process to sleep
        // else remove a item by using mutex semaphore
        sem_wait(&full);

        // check whether any other process is accessing buffer
        // if yes put this process to sleep
        // else add the element to the buffer
        sem_wait(&mutex);

        // remove element from the buffer
        item = buffer[out];
        // consumed item
        printf("Consumed item is: %d\n", item);
        out = (out + 1) % N;
        sleep(1);

        // free the mutex semaphore and and wake up a process in the sleep queue
        sem_post(&mutex);

        // increment the empty semaphore indicating the removal of new element to the buffer is complete
        sem_post(&empty);

    }

}




int main() {

    initSemaphores();

    // declare pthread (POSIX threads) ids
    // A thread is a single sequence stream within in a process
    pthread_t produce, consume;

    // create threads
    pthread_create(&produce ,NULL, producer, NULL);
    pthread_create(&consume, NULL, consumer, NULL);

    // join thread
    pthread_join(produce, NULL);
    pthread_join(consume, NULL);

    return 0;
}

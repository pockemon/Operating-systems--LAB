#include<stdio.h>
#include<string.h>

// pthread support library
#include<pthread.h>
// semaphore support library
#include<semaphore.h>

#define N 5

int data = 0, readerCount = 0;

// semaphores for readers, writers problem
sem_t db, mutex;


/**
 *  initialize semaphore varilables
 */
void initSemaphores() {

    // sem_init(semaphore variable reference, 0 to share semaphore between all threads, inital value)

    // mutex (mutual exclusion) variable
    sem_init(&mutex, 0, 1);

    // database access check semaphore
    sem_init(&db, 0, 1);
}



/**
 *  Writer program with semaphores
 */
void *writer(void *arg) {

    // check for access to database
    // if no access put process in sleep queue of db semaphore
    // else write to database
    sem_wait(&db);

    // write data
    printf("Data writen by the writer(%d) is %d\n",  ((int) arg), ++data);
    sleep(1);

    // free the db semaphore
    // also wake up a writer or reader from the sleep queue of the semaphore
    sem_post(&db);
}



/**
 *  Reader program with semaphores
 */
void *reader(void *arg) {

    // let only 1 reader increment reader count and get access to database
    // if not allowed put that reader in sleep queue of the mutex semaphore
    sem_wait(&mutex);

    // update reader count
    readerCount++;
    // get access to db if first reader is trying to access it
    if (readerCount == 1) {
        // check for access to database
        // if no access put the reader in sleep queue of db semaphore
        sem_wait(&db);
    }

    // release mutex variable as multiple readers is allowed
    // also wake up a reader from the sleep queue of the mutex semaphore
    sem_post(&mutex);

    // read data
    printf("Data read by the reader(%d) is %d\n",  ((int) arg), data);
    sleep(1);

    // let only 1 reader decrement reader count and release access to database
    // if no put that reader in sleep queue of the mutex semaphore
    sem_wait(&mutex);

    // udpate reader count
    readerCount--;
    // if last reader release access to database
    if (readerCount == 0) {
        // release access to database
        // also wake up a write in the sleep queue of the db semaphore
        sem_post(&db);
    }
    // release mutex variable also wake up a reader from the sleep queue of the mutex semaphore
    sem_post(&mutex);

}




int main() {

    initSemaphores();

    // declare pthread (POSIX threads) ids
    // A thread is a single sequence stream within in a process
    pthread_t read[N], write[N];

    // create readers and writer threads
    int i;
    for (i = 0; i <= N; i++) {
        pthread_create(&write[i], NULL, writer, (void *)i);
        pthread_create(&read[i], NULL, reader, (void *)i);
    }

    // join threads
    for (i = 0; i <= N; i++) {
        pthread_join(write[i], NULL);
        pthread_join(read[i], NULL);
    }

    return 0;
}

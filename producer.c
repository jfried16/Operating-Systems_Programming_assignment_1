//Joshua Friedman

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/shm.h>

int main(){
    
    // Make sure semaphores are deallocated
    // from previous use.
    sem_unlink("check1");
    sem_unlink("check2");
    sem_unlink("mutexLock");
    sem_unlink("emptySpace");
    sem_unlink("filledSpace");
    
    // Allocate shared memory and semaphores
    // The checks are to synchronize the text before running
    // The emptySpace will always equal the amount of free space in the table
    // The filledSpace will always equal the number of items in the table
    // The mutexLock is to ensure mututal exclusion
    int tbl = shm_open("table", O_CREAT | O_RDWR, 0666);
    int* table = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, tbl, 0);
     
    sem_t *check1 = sem_open("check1", O_CREAT | O_RDWR, 0666, 0);
    sem_t *check2 = sem_open("check2", O_CREAT | O_RDWR, 0666, 0);
    sem_t* mutexLock = sem_open("mutexLock", O_CREAT | O_RDWR, 0666, 1);
    sem_t* emptySpace = sem_open("emptySpace", O_CREAT | O_RDWR, 0666, 2);
    sem_t* filledSpace = sem_open("filledSpace", O_CREAT | O_RDWR, 0666, 0);

    // There are 20 items to be produced
    int loop = 20;

    // Unlocks consumer and waits to be unlocked
    // to format text
    sem_post(check1);
    sem_wait(check2);
    printf("\nProducer ready to produce %d items.\n", loop);


    for(int i = 0; i < loop; i++) {

       // If there is no empty space, then needs to wait
       sem_wait(emptySpace);
       
       // Random time to ensure fairness on mutexLock
       int ms = rand() % 2 + 1;
       sleep(ms);
       sem_wait(mutexLock);
       
       // Tells user how many items are remaining
       // and that an item was produced
       int c = 20 - (i+1);
       printf("item produced, items remaining: %d\n", c);
       
       // Unlocks mutexLock
       sem_post(mutexLock);

       // Updates the amount of filled space
       sem_post(filledSpace);
    }

    // Close and unlink all semaphores
    sem_close(check1);
    sem_close(check2);
    sem_close(mutexLock);
    sem_close(emptySpace);
    sem_close(filledSpace);

    sem_unlink("check1");
    sem_unlink("check2");
    sem_unlink("mutexLock");
    sem_unlink("emptySpace");
    sem_unlink("filledSpace");

    // Deallocate shared memory
    munmap(table, sizeof(int));
    close(tbl);
    shm_unlink("table");

    // Lets the user know producer is done
    printf("Producer cleaned up!\n");
    return 0;
}
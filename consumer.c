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

int main()
{
    // Allocate shared memory and semaphores
    // The checks are to synchronize the text before running
    // The emptySpace will always equal the amount of free space in the table
    // The filledSpace will always equal the number of items in the table
    // The mutexLock is to ensure mututal exclusion
    int shm_fd = shm_open("table", O_RDWR, 0666);
    int *table = mmap(0, sizeof(int), O_RDWR, MAP_SHARED, shm_fd, 0);

    sem_t *check1 = sem_open("check1", O_CREAT | O_RDWR, 0666, 0);
    sem_t *check2 = sem_open("check2", O_CREAT | O_RDWR, 0666, 0);
    sem_t *mutexLock = sem_open("mutexLock", O_CREAT | O_RDWR, 0666, 1);
    sem_t *emptySpace = sem_open("emptySpace", O_CREAT | O_RDWR, 0666, 2);
    sem_t *filledSpace = sem_open("filledSpace", O_CREAT | O_RDWR, 0666, 0);
    
    // There are 20 items to be consumed
    int loop = 20;

    // Waits to be unlocked by producer, then
    // unlocks producer to format text
    sem_wait(check1);
    sem_post(check2);
    printf("\nConsumer ready to recieve %d items.\n", loop);

    for (int i = 0; i < loop; i++)
    {
        // Consumer must wait until there is something 
        // to consume
        sem_wait(filledSpace);
        
        // Random time to ensure fairness on mutexLock
        int ms = rand() % 2 + 1;
        sleep(ms);
        sem_wait(mutexLock);
        
        // Tells user how many items are remaining
        // and that an item was produced
        int c = 20 - (i + 1);
        printf("item consumed, items remaining: %d\n", c);
        
        // Unlocks mutexLock
        sem_post(mutexLock);

        // Updates the amount of empty space
        sem_post(emptySpace);
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
    shm_unlink("table");

    // Lets the user know consumer is done
    printf("Consumer cleaned up!\n");
    return 0;

}
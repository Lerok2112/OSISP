#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>

int main() {
    time_t timer = 0;
    sem_t *sem1 = sem_open("sem1", 0);
    sem_t *sem2 = sem_open("sem2",0);
    while(1){
        sem_getvalue(sem1, &timer);
        printf("process gets current time:  %s \n", ctime(&timer));
        sleep(1);
        sem_post(sem2);
    }
    sem_unlink("sem1");
    sem_unlink("sem2");
    return 0;  
}

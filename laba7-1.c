#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
#include <stdio.h>
#include <fcntl.h>
int main() {
    time_t timer = time(NULL);
    time_t timer2 = 0;
    sem_t *sem1 = sem_open("sem1", O_CREAT, 0777, timer);
    sem_t *sem2 = sem_open("sem2", O_CREAT, 0777, 0);
    while(1){
        sem_getvalue(sem1, &timer2);
        timer = time(NULL);
	int counter=(timer - timer2);
	while(counter>0){
		sem_post(sem1); 
		counter--;
	}
        printf("process sends current time:  %ld\n", timer);
        sem_wait(sem2);
    }
    sem_unlink("sem1");
    sem_unlink("sem2");
    return 0;
    
}

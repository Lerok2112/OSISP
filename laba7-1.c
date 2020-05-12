#include <time.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{

	time_t timer = time(NULL);  //Считываем системное время

	sem_t *sem1 = sem_open("sem1", O_CREAT, 0777, 0);
	sem_t *sem2 = sem_open("sem2", O_CREAT, 0777, 0);
while(1){
	//sem_wait(sem2);
	timer = time(NULL);
	//sem_getvalue(sem1, &timer);
	printf("process sends current time: %ld\n", timer);
	sem_post(sem1); sem_post(sem2);
	}

	sem_unlink("sem1");
	sem_unlink("sem2");
	return(0);
}

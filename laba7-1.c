#include <time.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	time_t timer = time(NULL);  //Считываем системное время
	sem_t *sem1 = sem_open("sem1", O_CREAT, 0777, timer);
	sem_t *sem2 = sem_open("sem2", O_CREAT, 0777, 0);

	sem_getvalue(sem1, &timer);  
	sem_post(sem1);
	printf("process sends current time: %ld\n", timer);
	sem_wait(sem2);
	
	sem_unlink("sem1");
	sem_unlink("sem2");
	return(0);
}

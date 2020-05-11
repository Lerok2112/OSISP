#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void) {
	sem_t *sem1 = sem_open("sem1", O_CREAT, 0777, 0);
	sem_t *sem2 = sem_open("sem2", O_CREAT, 0777, 0);
	time_t timer = 0; char str[128]="";

        sem_getvalue(sem1, &timer); //получаем значение семафора
 	timer = localtime (&timer); //преобразуем системное время в локальное
   	strftime (str, 128, "%x %A %X", timer); //преобразуем локальное время в текстовую строку
        printf("process gets current time: %s \n", str);

        sem_post(sem2);

	sem_unlink("sem1");
	sem_unlink("sem2");
	return 0;
}

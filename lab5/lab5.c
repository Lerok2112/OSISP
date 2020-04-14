#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
	int fd;
	size_t sizeRead, sizeWrite;
	char string[10000];
	//Считываем данные из стандартного потока ввода
	sizeRead = read(0, string, 10000);
	if (sizeRead <= 0) {
		printf("Can\'t read.\n");
		return(-1);
	};
	//разделяем считанную строку на массив строк
	int num = 0;
	char  str[500][1024];
	char *str2 = strtok(string, "\n");
	while (str2 != NULL) {
		strcpy(str[num], str2);
		str2 = strtok(NULL, "\n");
		num++;
	}
	for (int i = 0; i < num; i++) {
		//находим строки начинающиеся на гласную букву
		if (str[i][0] == 'A' || str[i][0] == 'E' || str[i][0] == 'I' || str[i][0] == 'U' || str[i][0] == 'O' || str[i][0] == 'a' || str[i][0] == 'e' || str[i][0] == 'o' || str[i][0] == 'u' || str[i][0] == 'i') {
			write(1, str[i], strlen(str[i]) + 1); //выводим строку в стандартнаый поток
			write(1, "\n", strlen("\n")); 
			write(2,(i+1), sizeof(i+1));   //выводим номер строки в поток ошибок
		}
	}
	return 0;
}

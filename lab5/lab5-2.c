#include <sys/types.h>
#include <sys/stat.h>
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
	char  header[250];
	for (int i = 0; i < num; i++) {
		//ищем заголовки секций руководства
		if (i != 0 && i != (num - 1) && str[i][0] != ' ' && str[i][0] >= 'A' && str[i][0] <= 'Z' && str[i][1] >= 'A' && str[i][1] <= 'Z') {
			strcpy(header, str[i]);
			strcat(header, ".txt"); //объединяем строки (создаем названия для файлов)
		}
		else if (header!=0) {
			int file = open(header, O_WRONLY | O_CREAT | O_APPEND, 0777);  //открываем или создаем файл для записи в конец (права устанавливаем : всем все разрешено)
			write(file, str[i], strlen(str[i]));   //записываем секции в файл
			close(file);
		}
		
	}
	return 0;
}

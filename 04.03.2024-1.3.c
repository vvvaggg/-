#include <stdio.h>
  
int main(void)
{
    char message[] = "Hello METANIT.COM!"; // записываемая строка
    char * filename = "data.txt"; // файл для записи
    int n = sizeof(message)/sizeof(message[0]); // находим длину записываемой строки
    FILE * fp= fopen(filename, "w");
    if(fp)
    {
        for(int i=0; i < n; i++) // посимвольно записываем в файл
        {
            putc(message[i], fp); // Для записи символа в файл применяется функция putc()
        }
         
        fclose(fp); // После завершения работы с файлом его следует закрыть
        printf("File has been written\n");
    }
}
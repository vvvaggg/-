#include <stdio.h>
  
int main(void)
{
    // строка для записи
    char * message = "Hello METANIT.COM!\nAn apple a day keeps the doctor away";
    // файл для записи
    char * filename = "data.txt";
    // запись в файл
    FILE *fp = fopen(filename, "w");
    if(fp)
    {
        // записываем строку
        fputs(message, fp); // Функция fputs() записывает в файл строку, то есть набор символов, который завершается символом '\0'
        fclose(fp);
        printf("File has been written\n");
    }
}
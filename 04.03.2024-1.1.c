#include <stdio.h>
  
int main(void)
{
    FILE * fp= fopen("data28.txt", "r"); // Для открытия потока применяется функция fopen()
    
    if(fp==NULL) // проверка на наличие файла
    {
        perror("Error occured while opening data28.txt"); // Для вывода ошибки на консоль применяется встроенная функция perror()
        return 1; // сбой
    }
     
    fclose(fp); // После завершения работы с файлом его следует закрыть
    return 0; // успех
}
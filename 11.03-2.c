#include <stdio.h>
 
int main() {
    int N  = 20;
    char str[N];   // определяем буфер достаточной длины
 
    FILE *fp = fopen("data.txt", "r"); // указатель на файловый поток для чтения
    int count = fread(str, sizeof str[0], N, fp); 
    if(count == N)
    {
        printf("%s \n", str);
    }
    else
    {
        if (feof(fp))   // проверяем, достигнут ли конец файла
        {
            printf("Unexpected end of file\n");
            printf("Available: %s",str);
        }
        else if (ferror(fp))    // проверяется наличие же ошибки
            perror("Error while reading file\n");
    }
    fclose(fp);
}
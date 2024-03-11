#include <stdio.h>
 
int main(void)
{   
    char * filename = "users.dat";
    char name[20];  // для считывания имени
    int age;        // для считывания возраста
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Error occured while opening file\n");
        return 1;
    }
     
    while((fscanf(fp, "%20s  %d\n", name, &age))!=EOF) // Для чтения данных в определенном формате применяется функция fscanf()
    {
        printf("%s  %d\n", name, age);
    }
    fclose(fp);
    return 0;
}
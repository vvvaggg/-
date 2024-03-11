#include <stdio.h>
 
struct person
{
    char name[20];
    int age;
};
int main(void)
{
    char * filename = "users.dat";
    struct person people[] = { {"Tom", 23}, {"Alice", 27}, {"Bob", 31}, {"Kate", 29} };
    // количество записываемых структур
    int n = sizeof(people)/sizeof(people[0]);
    FILE *fp = fopen(filename, "w");
    if (!fp)
    {
        printf("Error occured while opening file\n");
        return 1;
    }
      
    for(int i=0; i < n; i++)
    {
        fprintf(fp, "%s  %d\n", people[i].name, people[i].age); // Эта функция записывает 
        // данные, передаваемые в качестве третьего параметра, в файл с учетом форматирования, 
        // определяемого строкой форматирования. Первый параметр представляет указатель на 
        // файловый поток, в который производится запись.
    }
    fclose(fp);
    printf("File has been written\n");
    return 0;
}
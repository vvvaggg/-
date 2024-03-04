/*
сохраним и считаем из файла массив структур
*/
#include <stdio.h>
#include <stdlib.h>
  
struct person
{
    char name[20];
    int age;
};
   
int save(char * filename, struct person *st, int n);
int load(char * filename);
   
int main(void)
{
    char * filename = "people.dat";
    struct person people[] = { {"Tom", 23}, {"Alice", 27}, {"Bob", 31}, {"Kate", 29 }};
    int n = sizeof(people) / sizeof(people[0]);
   
    save(filename, people, n);
    load(filename);
    return 0;
}
   
// запись в файл массива структур
int save(char * filename, struct person * st, int n)
{
    char *c;    // для записи отдельных символов
    // число записываемых байтов
    int size = n * sizeof(struct person);
    FILE * fp = fopen(filename, "wb");
    if (!fp)
    {
        printf("Error occured while opening file\n");
        return -1;
    }
    // записываем количество структур
    c = (char *)&n;
    for (int i = 0; i < sizeof(n); i++)
    {
        putc(*c++, fp);
    }
   
    // посимвольно записываем в файл все структуры
    c = (char *)st;
    for (int i = 0; i < size; i++)
    {
        putc(*c, fp);
        c++;
    }
    fclose(fp);
    return 0;
}
   
// загрузка из файла массива структур
int load(char * filename)
{
    char *c;    // для считывания отдельных символов
    int m = sizeof(int);    // сколько надо считать для получения размера массива
    int n;  // количество структур в массиве
   
    FILE * fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Error occured while opening file\n");
        return -1;
    }
    // выделяем память для хранения количества данных
    int *ptr_count = malloc(m);
    // считываем количество структур
    c = (char *)ptr_count;
    // пока не считаем m байт, сохраняем байт в выделенный блок для размера массива
    while (m > 0 && (*c = getc(fp)) != EOF)
    {
        c++;
        m--;
    }
    //получаем число элементов
    n = *ptr_count;
    free(ptr_count);    // освобождаем память
    // выделяем память для считанного массива структур
    struct person * ptr = malloc(n * sizeof(struct person));
    // устанавливаем указатель на блок памяти, выделенный для массива структур
    c = (char *)ptr;
    // считываем посимвольно из файла
    while ((*c= getc(fp))!=EOF)
    {
        c++;
    }
    // перебор загруженных элементов и вывод на консоль
    printf("\nFound %d people\n\n", n);
   
    for (int i = 0; i < n; i++)
    {
        printf("%-5d %-10s %5d \n", i + 1, (ptr + i)->name, (ptr + i)->age);
        // или так
        // printf("%-5d %-10s %5d \n", i + 1, ptr[i].name, ptr[i].age);
    }
   
    free(ptr);
    fclose(fp);
    return 0;
}

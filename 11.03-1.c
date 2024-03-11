#include <stdio.h>
 
int main() {
    char str[] = "Hello METANIT.COM"; // указатель на первый объект из массива, который должен быть записан
    size_t N = sizeof(str); // количество объектов, которые надо записать
    FILE *fp = fopen("data.txt", "w"); // указатель на файловый поток для записи
    size_t count = fwrite(str, sizeof str[0], N, fp); // sizeof str[0] - размер одного символа
    printf("wrote %zu elements out of %zu\n", count,  N);
    fclose(fp); // закрываем файл
}
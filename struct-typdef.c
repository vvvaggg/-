/*
Задача.
Сформировать массив, содержащий сведения о личной коллекции книголюба.
Структурный тип содержит поля: шифр книги, автор, название, год издания, местоположение (номер стеллажа).
Написать программу, выдающую следующую информацию:
• местоположение книги автора X названия Y;
• список книг автора Z, находящихся в коллекции;
• число книг издания XX года, имеющихся в библиотеке.

Вагина Полина Алексеевна, 32ИС-21, 2024-01-20 
*/

#include <stdio.h>
#include <string.h>


typedef struct {
    char code[20];
    char author[100];
    char title[100];
    int year;
    int shelf;

} Book;

int main() {
    Book col[100];
    int books = 0;
    
    strcpy(col[0].code, "A01"); // strcpy(s1, s2) - функция копирует s2 в s1 и возвращает s1

    strcpy(col[0].author, "Pushkin A.S.");
    strcpy(col[0].title, "Ruslan & Ludmila");
    col[0].year = 1820;
    col[0].shelf = 1;
    books++;
    
    strcpy(col[1].code, "A02");
    strcpy(col[1].author, "Pushkin A.S.");
    strcpy(col[1].title, "Evgeniy Onegin");
    col[1].year = 1833;
    col[1].shelf = 2;
    books++;
    
 
 
 
    char author[100];
    char title[100];
    printf("Введите автора книги: ");
    fgets(author, 100, stdin); /* author - Указатель на массив типа char, в который сохраняются считанные символы.
                                  100 - Максимальное количество символов для чтения, включая нулевой символ.
                                  stdin - Для чтения из стандартного ввода, stdin может быть использован в качестве этого параметра. */
    
    author[strcspn(author, "\n")] = '\0'; // Функция поиска первого символа в строке изи заданного набора символов

    printf("Введите название книги: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0'; 
    
    for (int i = 0; i < books; i++) {
        if (strcmp(col[i].author, author) == 0 && strcmp(col[i].title, title) == 0) /* Начиная с первых символов функция strcmp 
                                                                                    сравнивает поочередно каждую пару символов, и 
                                                                                    продолжается это до тех пор, пока не будут найдены 
                                                                                    различные символы или не будет достигнут конец строки.
                                                                                    
                                                                                    0 – если сравниваемее строки идентичны.*/
        {
            printf("Книга %s (шифр %s) находится на стеллаже %d\n", col[i].title, col[i].code, col[i].shelf);
        }
    }
   
   
   
    char list[100];
    printf("Введите автора книг: ");
    fgets(list, 100, stdin);
    list[strcspn(list, "\n")] = '\0'; // Удаление символа новой строки

    printf("Список книг автора %s:\n", list);
    for (int i = 0; i < books; i++) {
        if (strcmp(col[i].author, list) == 0) {
            printf("- %s (шифр %s)\n", col[i].title, col[i].code);
        }
    }
    
    
    
    int x;
    printf("Введите год издания для подсчета: ");
    scanf("%d", &x);

    int count = 0;
    for (int i = 0; i < books; i++) {
        if (col[i].year == x) {
           count++;
        }
    }
    printf("Число книг издания %d года, имеющихся в библиотеке: %d\n", x, count);
    
    return 0;
}

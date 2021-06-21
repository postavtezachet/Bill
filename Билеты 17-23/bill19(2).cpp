//Билет 19 задание 2
//Максим
//Разработать программу «Библиотека». Структура: автор, название, год. Должны работать функции добавления и сортировки.
// Это по факту мини первая лаба. Я создал массив структур и 3 функции в меню

#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<locale.h>
#pragma warning(disable : 4996)// чтобы работал scanf fopen и т.д.
struct library {// структура как сказано в условии
	char athor[30];
	char name[50];
	int year;
};
void gets_max(char* name, int n) {// Это моя функция ввода строк так как я не люблю gets
									// единственное чем она отличается это проверка на длинну строки
									// чтобы пользователь не мог ввести строку большего размера
	int i = 0;
	char c;
	do {
		rewind(stdin);
		i = 0;
		c = ' ';
		int error = 0;
		while (c != '\n') {
			scanf("%c", &c);

			if (c != '\n') {
				name[i] = c;
				i++;
			}
			if (i > n) {
				printf("error\n");
				error = 1;
				break;
			}

		}
		if (error == 0) {
			break;
		}
	} while (1);
	name[i] = '\0';
}
void menu() {// это просто вывод меню
	printf("1:Автор\n");
	printf("2:Название\n");
	printf("3:Год\n");
}
int tolowersorting(char* s1, char* s2) {// эта функция преобразовывает две строки к нижнему регистру и результатом
										// даёт сравнение этих двух строк
	char f[50];// строка для записи первой строки в нижнем регистре
	char f1[50];// строка для записи второй строки в нижнем регистре
	int i = 0, j = 0;// я не знаю зачем мне два счётчика для индекса строк( наверное можно только один)
	while (s1[i]) {// мы проходим по первой строке и записываем в f каждый элемент в нижнем регистре
		f[j] = tolower(s1[i]);// tolower приводит элемент к нижнему регистру(S->s)
		i++;// увеличиавем индексы
		j++;
	}
	i = 0;// обнуляем для работы со второй строкой
	j = 0;
	while (s2[i]) {		// так же как и для первой только для второй
		f1[j] = tolower(s2[i]);
		i++;
		j++;
	}
	return strcmp(f, f1);// возвращает сравнение двух строк в нижнем регистре (0 когда одинаковые строки)
}
void add(library* mas, int n) {// функция ввода информации в новый элемент масиива(n-номер нового элемента)
	printf("Введите автора\n");
	gets_max(mas[n].athor, 30);
	printf("Введите название\n");
	gets_max(mas[n].name, 50);
	printf("Введите год публикации\n");
	scanf("%d", &mas[n].year);
}
void output(library* mas, int n) {// вывод массива структур
	for (int i = 0; i < n; i++) {
		printf("Книга номер %d\n", i + 1);
		printf("Автор %s\n", mas[i].athor);
		printf("Название %s\n", mas[i].name);
		printf("Год издания %d\n\n", mas[i].year);
	}
}
void sort(library* mas, int n) {// сортировка масиива( n - размер) 
	int choice;
	library* r;
	r = (library*)calloc(1, sizeof(library));// выделяем память на новую структуру(она будет использоваться как буффер)
	printf("Что вы хотите сортировать\n");// вариант выбора что сортировать
	printf("1:По автору\n");
	printf("2:По названию\n");
	printf("3:По году публикации\n");
	while (!scanf("%d", &choice)) {// проверка на ввод числа(если введёте больше 3 то она просто выйдет из функции
		rewind(stdin);
	}
	switch (choice) {
	case 1:// сортировка по автору
		for (int i = 0; i < n; i++) {// тут обычный пузырёк(вроде) для сортировки по алфавиту
			for (int j = 0; j < n; j++) {
				if (tolowersorting(mas[i].athor, mas[j].athor) < 0) {
					r[0] = mas[i]; // r[0] для того чтобы поменять местами два элемента массива
					mas[i] = mas[j];
					mas[j] = r[0];

				}
			}
		}
		break;
	case 2:// сортировка по названию
		for (int i = 0; i < n; i++) {// тут обычный пузырёк(вроде) для сортировки по алфавиту
			for (int j = 0; j < n; j++) {
				if (tolowersorting(mas[i].name, mas[j].name) < 0) {
					r[0] = mas[i];// r[0] для того чтобы поменять местами два элемента массива
					mas[i] = mas[j];
					mas[j] = r[0];

				}
			}
		}
		break;
	case 3:// сортировка по году публикации по возрастанию
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mas[i].year<mas[j].year) {
					r[0] = mas[i];// r[0] для того чтобы поменять местами два элемента массива
					mas[i] = mas[j];
					mas[j] = r[0];

				}
			}
		}
		break;
	}

}
int main() {
	system("chcp 1251>null");// это изменение кодировки для работы с русским текстом(при setlocale не введёшь строку на русском)
	library* mas;
	int n = 3;
	mas = (library*)calloc(n, sizeof(library));// выделяем память под массив
	for (int i = 0; i < n; i++) {//вводим информацию
		add(mas, i);
	}
	int choice;
	do {// цикл работает пока не введём 4 
		printf("1:Добавление\n");
		printf("2:Вывод\n");
		printf("3:Сортировка\n");
		printf("4:Выход\n");
		while (!scanf("%d", &choice)) {// проверка на ввод числа
			rewind(stdin);
		}
		
		switch (choice) {
		case 1:// добавление
			system("cls");
			mas = (library*)realloc(mas, (n + 1) * sizeof(library));// выделяем память под новый элемент
			
			add(mas, n);
			n++;// увеличиваем количество элементво в массиве
			break;
		case 2:// вывод
			system("cls");
			output(mas, n);
			break;
		case 3://сортировка
			sort(mas, n);
			break;
		case 4:// выход
			break;
		}
			

	} while (choice != 4);
	free(mas);
	return 0;

}

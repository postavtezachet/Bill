//����� 19 ������� 2
//������
//����������� ��������� �����������. ���������: �����, ��������, ���. ������ �������� ������� ���������� � ����������.
// ��� �� ����� ���� ������ ����. � ������ ������ �������� � 3 ������� � ����

#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<locale.h>
#pragma warning(disable : 4996)// ����� ������� scanf fopen � �.�.
struct library {// ��������� ��� ������� � �������
	char athor[30];
	char name[50];
	int year;
};
void gets_max(char* name, int n) {// ��� ��� ������� ����� ����� ��� ��� � �� ����� gets
									// ������������ ��� ��� ���������� ��� �������� �� ������ ������
									// ����� ������������ �� ��� ������ ������ �������� �������
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
void menu() {// ��� ������ ����� ����
	printf("1:�����\n");
	printf("2:��������\n");
	printf("3:���\n");
}
int tolowersorting(char* s1, char* s2) {// ��� ������� ��������������� ��� ������ � ������� �������� � �����������
										// ��� ��������� ���� ���� �����
	char f[50];// ������ ��� ������ ������ ������ � ������ ��������
	char f1[50];// ������ ��� ������ ������ ������ � ������ ��������
	int i = 0, j = 0;// � �� ���� ����� ��� ��� �������� ��� ������� �����( �������� ����� ������ ����)
	while (s1[i]) {// �� �������� �� ������ ������ � ���������� � f ������ ������� � ������ ��������
		f[j] = tolower(s1[i]);// tolower �������� ������� � ������� ��������(S->s)
		i++;// ����������� �������
		j++;
	}
	i = 0;// �������� ��� ������ �� ������ �������
	j = 0;
	while (s2[i]) {		// ��� �� ��� � ��� ������ ������ ��� ������
		f1[j] = tolower(s2[i]);
		i++;
		j++;
	}
	return strcmp(f, f1);// ���������� ��������� ���� ����� � ������ �������� (0 ����� ���������� ������)
}
void add(library* mas, int n) {// ������� ����� ���������� � ����� ������� �������(n-����� ������ ��������)
	printf("������� ������\n");
	gets_max(mas[n].athor, 30);
	printf("������� ��������\n");
	gets_max(mas[n].name, 50);
	printf("������� ��� ����������\n");
	scanf("%d", &mas[n].year);
}
void output(library* mas, int n) {// ����� ������� ��������
	for (int i = 0; i < n; i++) {
		printf("����� ����� %d\n", i + 1);
		printf("����� %s\n", mas[i].athor);
		printf("�������� %s\n", mas[i].name);
		printf("��� ������� %d\n\n", mas[i].year);
	}
}
void sort(library* mas, int n) {// ���������� �������( n - ������) 
	int choice;
	library* r;
	r = (library*)calloc(1, sizeof(library));// �������� ������ �� ����� ���������(��� ����� �������������� ��� ������)
	printf("��� �� ������ �����������\n");// ������� ������ ��� �����������
	printf("1:�� ������\n");
	printf("2:�� ��������\n");
	printf("3:�� ���� ����������\n");
	while (!scanf("%d", &choice)) {// �������� �� ���� �����(���� ������ ������ 3 �� ��� ������ ������ �� �������
		rewind(stdin);
	}
	switch (choice) {
	case 1:// ���������� �� ������
		for (int i = 0; i < n; i++) {// ��� ������� ������(�����) ��� ���������� �� ��������
			for (int j = 0; j < n; j++) {
				if (tolowersorting(mas[i].athor, mas[j].athor) < 0) {
					r[0] = mas[i]; // r[0] ��� ���� ����� �������� ������� ��� �������� �������
					mas[i] = mas[j];
					mas[j] = r[0];

				}
			}
		}
		break;
	case 2:// ���������� �� ��������
		for (int i = 0; i < n; i++) {// ��� ������� ������(�����) ��� ���������� �� ��������
			for (int j = 0; j < n; j++) {
				if (tolowersorting(mas[i].name, mas[j].name) < 0) {
					r[0] = mas[i];// r[0] ��� ���� ����� �������� ������� ��� �������� �������
					mas[i] = mas[j];
					mas[j] = r[0];

				}
			}
		}
		break;
	case 3:// ���������� �� ���� ���������� �� �����������
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mas[i].year<mas[j].year) {
					r[0] = mas[i];// r[0] ��� ���� ����� �������� ������� ��� �������� �������
					mas[i] = mas[j];
					mas[j] = r[0];

				}
			}
		}
		break;
	}

}
int main() {
	system("chcp 1251>null");// ��� ��������� ��������� ��� ������ � ������� �������(��� setlocale �� ������ ������ �� �������)
	library* mas;
	int n = 3;
	mas = (library*)calloc(n, sizeof(library));// �������� ������ ��� ������
	for (int i = 0; i < n; i++) {//������ ����������
		add(mas, i);
	}
	int choice;
	do {// ���� �������� ���� �� ����� 4 
		printf("1:����������\n");
		printf("2:�����\n");
		printf("3:����������\n");
		printf("4:�����\n");
		while (!scanf("%d", &choice)) {// �������� �� ���� �����
			rewind(stdin);
		}
		
		switch (choice) {
		case 1:// ����������
			system("cls");
			mas = (library*)realloc(mas, (n + 1) * sizeof(library));// �������� ������ ��� ����� �������
			
			add(mas, n);
			n++;// ����������� ���������� ��������� � �������
			break;
		case 2:// �����
			system("cls");
			output(mas, n);
			break;
		case 3://����������
			sort(mas, n);
			break;
		case 4:// �����
			break;
		}
			

	} while (choice != 4);
	free(mas);
	return 0;

}

//????? 23 ??????? 1
//??????
//??? ??????????????? ????????? ????. ???????? ????????? ?????????? ???????? ???????, ?? ??????? ???????????????.
//??? ???? ??????? ?????? ????? ??? ???????? ?? ????????(? ??????? ???????????????)( ???? ? ???????? ?? ????? ???????? ??? ? ? ??)
//???????? ???? ??? ???????? ????? ??????? ?????? ?? ???????? ???????? ?????? ?????? ? ???????? ?????
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#pragma warning(disable : 4996)//????? ???????????? scanf fopen ? ?.?.
void gets_max(char* name, int n) { // I hate gets and i created this function
									//??? ??? ??????? ?? ??? ????? ?? ???? ??????(????? ???????????? ?????? gets)
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
			if (i > n) { // if input more than n
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
void output(FILE* f) {// ?????? ?????
	char c;
	rewind(f);// ????????? ? ?????? ?????
	fscanf(f, "%c", &c);
	while (1) {
		if (feof(f)) {
			break;
		}
		printf("%c", c);

		fscanf(f, "%c", &c);
	}
}
int main() {
	system("chcp 1251>null");// ??? ?? ?????? ?????????(??? ??? setlocale ?? ????????? ??? ?????????? ?????? ?? ???????)
	char* string;// ?????? ??????? ?? ????? ?????????? ? ????
	int trig =0;
	string = (char*)calloc(100, sizeof(char));
	gets_s(string, 100);
	FILE* f;
	if (!(f = fopen("file.txt", "w+"))) {
		printf("Error\n");
		return 0;
	}
	fprintf(f, "%s", string);
	rewind(f);//????????? ? ?????? ?????

	char c,c1, c2;// ? ? ?? ?????????? ????? ? ?????????? ? ????????? ??????
				//?1 ?? ?????????? ?????? ??????? ?? ????? ??????????
				//?2 ?? ?????????? ?????? ?? ??????? ?? ????? ?????????? c1
	printf("\n??????? ?????? ??????? ?? ?????? ????????(?? ???????)\n");
	char symbol;
	scanf("%c", &symbol);// ?????? ?????? ??????? ????? ????????
	rewind(stdin);// ??? ???????? ???????( ??? ??? ????? scanf ???????? \n ??????? ???? gets ????? ??? ????????? ? ?????????? ??????)
	rewind(f);// ????????? ? ?????? ?????
	while (1) {// ???? 1
		while (1) {// ???? 2
			
			fscanf(f, "%c", &c);// ?????? ?????? ?? ?????
			
			if (feof(f)) {// ???? ????? ????? ?? ??????? ?? ????? 2
				break;
			}
			if (symbol < c && c != ' ') {// ???? ?????? ????? ?? ???????? ? ?? ?? ????? ???????
				fseek(f, -1, 1);// ????????? ?? ?????????? ??????
				trig = 1;// ???? ??????? ????? ????? ?????? ???? ?? ????????? ????? ?????? ? ?????
				break;// ??????? ?? ????? 2
			}
		}
		if (trig == 0){// ???? ?? ?? ????? ?????? ??????? ????? ? ???????? ?? ????????? ? ?????
			fprintf(f, "%c", symbol);
			break;// ??????? ?? ????? 1
		} 
		else {
			c1 = c;// ?????????? ?????? ??????? ????? ?? ????????
			fprintf(f, "%c", symbol);// ?????????????? ?? ??? ????? ????????? ??????
			while (1) {//???? 3
				fseek(f, 0, 1);// ? ??? ??????? ?? ?????? ????? ??? ???????(??? ??? ????? ?? ????????) ???? ??? ?????? ??????????? ? ????? ?? ???? ????
								// ?? ???? ????? ?? ??????
				fscanf(f, "%c", &c2);// ?????? ????????? ??????? ????? ?1
				if (feof(f)) {// ???? ????? ?????
					
					fprintf(f, "%c", c1);// ?????????? ????????? ?????
					break;// ??????? ?? ????? 3
				}
				fseek(f, -1, 1);// ????????? ?? ???? ?????? ?????
				fprintf(f, "%c", c1);//?????????? c1
				
				
				c1 = c2;// ? c1 ?????????? ????????? ??????
			}
			break;// ??????? ?? ????? 1


		}
	}
	rewind(f);// ????????? ? ?????? ?????
	printf("????? ??????????\n");
	output(f);
	fclose(f);

	return 0;
}
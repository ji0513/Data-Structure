#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include<stdio.h>
#include<ctype.h>

typedef struct {
	char data[MAX_SIZE];
	int top;
}stack;                                                 // 스택 구조체 정
void init(stack* s) {
	s->top = -1;
}                                                      //스택초기화(top=-1)
void push(stack* s, char a) {
	s->top++;
	s->data[s->top] = a;
}
char pop(stack* s) {
	return s->data[s->top--];
}

int main() {
	stack s;
	init(&s);                                         //시작과 동시에 바로 초기화

	char str[100];
	char temp[100];                                   //입력받는 문자열과 전처리결과를 받을 문자 생성

	int j = 0;

	printf("문자열을 입력하시오:");
	fgets(str, sizeof(str), stdin);                 //fgets()는 공백을 포함한 한줄 전체를 입력받는다.(<->scanf는 공백을 받지못함.)

	for (int i = 0;str[i] != '\0'; i++) {
		if (str[i] != '\n' && str[i] != ' ') {
			char ch = tolower(str[i]);                 //ctype.h가 있어야 사용가능, 대문자->소문자 변환
			temp[j] = ch;
			push(&s, ch);

			j++;
		}
	}

	temp[j] = '\0';                               //문자열 끝을 알려주는 널문
	printf("전처리 결과: %s\n", temp);

	int flag = 1;                                 //회문여부를 확인하 변수
	for (int i = 0;temp[i] != '\0';i++) {
		char ch = pop(&s);
		if (temp[i] != ch) {
			flag = 0;
			break;
		}

	}
	if (flag)
		printf("회문입니다.\n");
	else
		printf("회문이 아닙니다\n");

	return 0;
}

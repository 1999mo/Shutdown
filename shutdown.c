/*
개인 명세서 처리(입력 / 정밀 / 출력)
 개인 명세서를 정의하고(아래 출력 예 참조))
 입력될 명세서의 개수(7 - 10)를 입력받아서 개수 만큼의 배열 할당
 개별 명세서를 입력 받아서 동적메모리를 할당 받아 저장(7개 이상)
 입력된 자료(명세서)를 3번 출력한다(single line)
  입력 자료를 입력순으로 출력
  입력 자료를 이름순(내림차순)으로 출력
  입력 자료를 생년월일순(올림차순)으로 출력
 적절한 function을 저으이하여 구현한다
입출력 예
 입력할 명세서의 개수를 입력하시오 : 8
 개별명세 입력1: 홍길동 1999/10/20 남자 01012345678
 개별명세 입력2: 아무개 1996/01/19 여자 01013246789
...
이름   생년월일     성별 전화번호
홍길동  1995-10-20  남   010-1234-5678
아무개  1996-01-19  여   010-1324-6789
...
*/  
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void scanN();
int n(int a);
struct List *array;
void scanList();
void printList();
int compName(int i);
int compBirth(int i);
void strcp(int i);

struct List{
	char name[30];
	char birth[12];
	char sex[5];
	char tele[12];
};

int main(void)
{
	scanN();
	scanList();
	printList();
	
	return 0; 
}

void scanN()
{
	int i;
	printf("입력할 명세서의 개수를 입력하시오 : ");
	scanf("%d", &i);
	n(i);
}

int n(int a)
{
	static int num = 0;
	
	if(a != 0)
	{
		num = a;
	}
	else return num;
}

void scanList()
{
	int i;
	
	if((array = ((struct List *)malloc(57 * n(0)))) == NULL)
	{
		printf("Memory Error ...\n");
		exit(1);
	}
	
	for(i = 0; i < n(0); i++)
	{
		printf("개별명세 입력%d : ", i+1);
		
		scanf("%s %s %s %s", array[i].name, array[i].birth, array[i].sex, array[i].tele);
		
		array[i].birth[4] = '-';
		array[i].birth[7] = '-';
	}
}

void printList()
{
	
	int i = 0;
	
	printf("입력순\n");
	
	for(i = 0; i < n(0); i++)
	{
		printf("이름   생년월일   성별 전화번호\n");
		
		printf("%s %s   %s   %s\n", array[i].name, array[i].birth, array[i].sex, array[i].tele);
	}
	
	for(i = 0; i < n(0) - 1; i++)
	{
		if(compName(i) == 0) i--;
	}
	
	printf("\n이름순\n");// 내림 
	
	for(i = 0; i < n(0); i++)
	{
		printf("이름   생년월일   성별 전화번호\n");
		
		printf("%s %s  %s\n", array[i].name, array[i].birth, array[i].tele);
	}
	
	for(i = 0; i < n(0) - 1; i++)
	{
		if(compBirth(i) == 0) i--;
	}
	
	printf("\n생일순\n"); //올림순
	
	for(i = 0; i < n(0); i++)
	{
		printf("이름   생년월일   성별 전화번호\n");
		
		printf("%s %s  %s\n", array[i].name, array[i].birth, array[i].tele);
	}
}

int compName(int i)
{
	if(strcmp(array[i].name, array[i + 1].name) < 0)
	{
		strcp(i);
		
		return 0;
	}
	else return 1;
}

int compBirth(int i)
{
	if(strcmp(array[i].birth, array[i + 1].birth) > 0)
	{
		strcp(i);
		
		return 0;
	}
	else return 1;
}

void strcp(int i)
{
	char cmp[30] = {'\0'};
	
	strcpy(cmp, array[i].name);
	strcpy(array[i].name, array[i + 1].name);
	strcpy(array[i + 1].name, cmp);
	
	strcpy(cmp, array[i].birth);
	strcpy(array[i].birth, array[i + 1].birth);
	strcpy(array[i + 1].birth, cmp);
	
	strcpy(cmp, array[i].sex);
	strcpy(array[i].sex, array[i + 1].sex);
	strcpy(array[i + 1].sex, cmp);
	
	strcpy(cmp, array[i].tele);
	strcpy(array[i].tele, array[i + 1].tele);
	strcpy(array[i + 1].tele, cmp);
}

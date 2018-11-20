/*
���� ���� ó��(�Է� / ���� / ���)
 ���� ������ �����ϰ�(�Ʒ� ��� �� ����))
 �Էµ� ������ ����(7 - 10)�� �Է¹޾Ƽ� ���� ��ŭ�� �迭 �Ҵ�
 ���� ������ �Է� �޾Ƽ� �����޸𸮸� �Ҵ� �޾� ����(7�� �̻�)
 �Էµ� �ڷ�(����)�� 3�� ����Ѵ�(single line)
  �Է� �ڷḦ �Է¼����� ���
  �Է� �ڷḦ �̸���(��������)���� ���
  �Է� �ڷḦ ������ϼ�(�ø�����)���� ���
 ������ function�� �������Ͽ� �����Ѵ�
����� ��
 �Է��� ������ ������ �Է��Ͻÿ� : 8
 ������ �Է�1: ȫ�浿 1999/10/20 ���� 01012345678
 ������ �Է�2: �ƹ��� 1996/01/19 ���� 01013246789
...
�̸�   �������     ���� ��ȭ��ȣ
ȫ�浿  1995-10-20  ��   010-1234-5678
�ƹ���  1996-01-19  ��   010-1324-6789
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
	printf("�Է��� ������ ������ �Է��Ͻÿ� : ");
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
		printf("������ �Է�%d : ", i+1);
		
		scanf("%s %s %s %s", array[i].name, array[i].birth, array[i].sex, array[i].tele);
		
		array[i].birth[4] = '-';
		array[i].birth[7] = '-';
	}
}

void printList()
{
	
	int i = 0;
	
	printf("�Է¼�\n");
	
	for(i = 0; i < n(0); i++)
	{
		printf("�̸�   �������   ���� ��ȭ��ȣ\n");
		
		printf("%s %s   %s   %s\n", array[i].name, array[i].birth, array[i].sex, array[i].tele);
	}
	
	for(i = 0; i < n(0) - 1; i++)
	{
		if(compName(i) == 0) i--;
	}
	
	printf("\n�̸���\n");// ���� 
	
	for(i = 0; i < n(0); i++)
	{
		printf("�̸�   �������   ���� ��ȭ��ȣ\n");
		
		printf("%s %s  %s\n", array[i].name, array[i].birth, array[i].tele);
	}
	
	for(i = 0; i < n(0) - 1; i++)
	{
		if(compBirth(i) == 0) i--;
	}
	
	printf("\n���ϼ�\n"); //�ø���
	
	for(i = 0; i < n(0); i++)
	{
		printf("�̸�   �������   ���� ��ȭ��ȣ\n");
		
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

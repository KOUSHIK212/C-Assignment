#include<stdio.h>

char k[20];
int up=-1;

void push(char);
void pop();

void push(char a)
{
	k[++up]=a;
}

void pop()
{
	printf("%c",k[up--]);
}

void main()
{
	char input[20];
	printf("\n enter string:");
	scanf("%k",input);
	
	int i=0;
	while (input[i]!='\0')
	{
		push(input[i]);
		i++;
	}
	
	printf("\n");
	while(up!=-1)
	{
		pop();
	}
}

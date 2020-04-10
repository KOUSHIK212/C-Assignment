#include<stdio.h>
#define size 50

char stack[size];
int up=-1;

void push(char i1)
{
	if(up>=size-1)
	printf("\n stack oerflow,push not possible \n");
	else
	{
		up++;
		stack[up]=i1;
	}
}
char pop()
{
	char i1;
	i1=stack[up];
	up--;
	return(i1);
}
int is_operator(char s1)
{
	if(s1=='^'||s1=='*'||s1=='/'||s1=='+'||s1=='-')
	return 1;
	else
	return 0;
	
}
int precedence(char s1)
{
	if(s1=='^')
	return 3;
	else if(s1=='*'|| s1=='/')
	return 2;
	else if(s1=='+'||s1=='-')
	return 1;
	else
	return 0;
	
	
}
int main()
{
	char infix[size],postfix[size],i1,temporary;
	int i=0,j=0;
	printf("\n enter the arthimatic notation in infix notation:");
	gets(infix);
	while(infix[i]!='\0')
	{
		i1=infix[i];
		if(i1=='(')
		{
			push(i1);
		}
		else if(i1>='A' && i1<='Z' || i1>='a' && i1<='z')
		{
			postfix[j]=i1;
			j++;
		}
		else if(is_operator(i1)==1)
		{
			temporary=pop();
			while(is_operator(temporary)==1 && precedence(temporary)>=precedence(i1))
			{
				postfix[j]=temporary;
				j++;
				temporary=pop();
				
			}
			push(temporary);
			push(i1);
		}
		else if(i1==')')
		{
			temporary=pop();
			while(temporary!='(')
			{
				postfix[j]=temporary;
				j++;
				temporary=pop();
				
			}
		}
		else
		{
			printf("\n The arthimatic expression is not valid.\n");
			getch();
		    exit(0);
			
			
			
		}
		i++;
	}
	while(up>-1)
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';
	puts(postfix);
	
	getch();
	return 0;
}

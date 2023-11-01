#include<stdio.h>  
#include<stdlib.h>
#include<conio.h>

#define size 6

int top; 
char stack[size]; 
char array[size];  

void push(char data)
{
	if(top+1==size)
	{
		puts("Stack is full!");
	}
	else
	{
		stack[++top]=data;
	}
}

char peek()
 {
   return stack[top];
}

char pop() {
	return stack[--top];
}

bool IsItEmpty()
{
	if(top==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsItTrue()
{
    int i;
    
	while(array[i] !='\0')
	{
		char c =array[i];
		printf("\nData: %c",c);
		
		if (c == '{' || c == '(' || c == '[')
		{
			 push(c);
			 printf("\nPush: %c",c);
		}
		else if (c == '}' || c == ')' || c == ']')
		{
			if(IsItEmpty() == true)
			{
				puts("\nStack is empty!");
				return false;
			}
			char peekd=peek();
			printf("\nPeek: %c",peekd);
			
			if(c == '}' && peekd == '{' || c == ')' && peekd == '(' || c == ']' && peekd == '[')
			{
				pop();
			}
			else
			{
				return false;
			}
		}
		
		i+=1;
	}
	return IsItEmpty();
}
     
int main ()
{		
	puts("Please enter the values: ");
	fgets(array,sizeof(array),stdin);
	
	if(IsItTrue ()== true)
	{
		puts("\nTRUE!");
		getch();
	}
	else
	{
		puts("\nFALSE!");
		getch();
	}
}

					// INFIX TO POSTFIX 
#include "stdio.h"
#include "string.h"
#define MAX 200									// INCASE OF LARGER SIZE ; JUST TO MAKE ONE CHANGE

int top = -1, current = -1;
char str[MAX], stk[MAX], post[MAX];

int prece(char *add){							// TO CALCULATE OPERATOR HIRERCHY
	if((*add == '+') || (*add == '-'))
		return 1;
	if((*add == '*') || (*add == '/'))
		return 2;
	if(*add == '^')
		return 3;
}

void display(void){								// TO PRINT POSTFIX EXPRESSION
	int i;
	for(i=0; i <= current; i++)
		printf("%c ", post[i]);
	printf("\n");
}

void insert(char *add){							// TO ADD ELEMENTS IN POSTFIX STRING
	++current;
	post[current] = *add;
}

void push(char *add){							// TO PUSH IN STACK
	++top;
	stk[top] = *add;
}

void pop(char *add){							// TO POP IN STACK
	if(*add==')'){
		while(stk[top] != '('){
			insert(&stk[top]);
			--top;
			if(stk[top] =='('){
				--top;
				break;
			}
		}
	}
}

int main(){
	int i;
	char ch;

	printf("\t\t\a!! CAUTION !! this program can deal with single digits only !! CAUTION !!\n\n");
	printf("enter the infix expression, (.) at end\n");

	for(i=0; i < MAX; i++){						// INPUT INFIX
		scanf(" %c", &ch);
		if(ch == '.')
			break;
		else
			str[i] = ch;
	}

	for(i=strlen(str)+1; i > 0; i--){			// ADDING BRACES AND RESIZING
		if(i == 1){
			str[i] = str[i-1];
			str[i-1] = '(';
		}
		else
			str[i] = str[i-1];
	}

	strcat(str,")");

	for(i=0; i < strlen(str); i++){				// CONVERSION CONDITIONS 			
		if(str[i] == '(')
			push(&str[i]);
		else if(str[i] == ')')
			pop(&str[i]);
		else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
			if((stk[top] == '+') || (stk[top] == '-') || (stk[top] == '*') || (stk[top] == '/') || (stk[top] == '^')){
				if(prece(&stk[top]) > prece(&str[i])){
					insert(&stk[top]);
					stk[top] = str[i];
				}
				else if(prece(&stk[top]) < prece(&str[i]) || prece(&stk[top]) < prece(&str[i]))
					push(&str[i]);
			}
			else
				push(&str[i]);
		}
		else
			insert(&str[i]);
	}

	printf("the postfix expression is shown below\n");

	display();

	return 0;
}
																		// A 13 C

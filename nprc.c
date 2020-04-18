/************************ DESCRIPTION SECTION *************************/

/*
 * Unicamp Faculty of Technology - FT
 *
 * SI010 - Data Structures II - 1st Half 2020
 *
 * Developers:
 * 	Gustavo Adrien Polli	217357
 * 	Victor Gomes Sampaio	225133
 *
 * Description:
 * Non Regurar Purpose Calculator is a simple RPN (Reverse Polish
 * Notation) written in C.
 */


/************************* LIBRARIES SECTION **************************/

/*
 * Libraries
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMBER '0' //signal that a number was found


/************************* STRUCTURES SECTION *************************/

/*
 * Data structures
 */
typedef struct Node{
	double data;
	struct Node *next;
} NODEPTR;


/************************* CODE CONVENTIONS ***************************/

/*
 * In function returns:
 * 1 - means success
 * 0 - means failure
 */

/************************** HEADERS SECTION ***************************/

/* Function headers */
int initStack(NODEPTR **start); //start an empty stack
int empty(NODEPTR **stack); //verifies if the stack is empty
void push(NODEPTR **stack, double data); //insert a node into the stack
double pop(NODEPTR **stack); //remove a node from the stack and return status
void menu(NODEPTR **stack); //prints an options menu on screen
double calc(double value1, double value2, char operator); //calculates the result
int print(NODEPTR *stack);
int isNumber(char *input);
char getOp(char *operator);

/*********************** MAIN FUNCTION SECTION ************************/

int main(int argc, char* argv[]){
	NODEPTR *stack;

	initStack(&stack);

	menu(&stack);
	return 0; //need to return system status
}


/************************* FUNCTIONS SECTION **************************/

/* start an empty stack */
int initStack(NODEPTR **start){
	*start = NULL;
	return 1; //success
}

/* verifies if the stack is empty */
int empty(NODEPTR **stack){
	if(*stack == NULL){
		return 1; //true
	}else{
		return 0; //false
	}
}

int print(NODEPTR *stack){
	NODEPTR *wander = stack;

	if(wander == NULL){		
		return 0; //Lista vazia
	} else {
		printf("\nTOPO ->");
		while(wander->next != NULL){
				printf(" %.2lf ->", wander->data);
				wander = wander->next;
		}
		printf(" %.2lf\n", wander->data);
		return 1;
	}
}

/* insert a node into the stack */
void push(NODEPTR **stack, double data){
	NODEPTR *ptr, *wander;
	ptr = (NODEPTR*) malloc(sizeof(NODEPTR));

	ptr->data = data;

	if(empty(stack)){
		*stack = ptr;
	}
	else{
		wander = (*stack);
		(*stack) = ptr;
		(*stack)->next = wander;
	}
}

/* remove a node from the stack */
double pop(NODEPTR **stack){
	NODEPTR *wander = (*stack), *aux;
	double data = 0;
	if(empty(stack)){
		return 0;
	}else{
			aux = wander;
			wander = wander->next;
			data = aux->data;
			free(aux);
			(*stack) = wander;
			return data;
	}
}

void menu(NODEPTR **stack){
	double result = 0;

	char input[100];	

	do{
		scanf("%s", input);
		getchar();

		switch(getOp(input)){
			case NUMBER:
				push(stack, atof(input));
				break;
			case '+':
				result = calc(pop(stack), pop(stack), '+');
				printf("\n The result is: %.2lf\n", result);
				push(stack, result);
				break;
			case '-':
				result = calc(pop(stack), pop(stack), '-');
				printf("\n The result is: %.2lf\n", result);
				push(stack, result);
				break;
			case '*':
				result = calc(pop(stack), pop(stack), '*');
				printf("\n The result is: %.2lf\n", result);
				push(stack, result);
				break;
			case '/':
				result = calc(pop(stack), pop(stack), '/');
				printf("\n The result is: %.2lf\n", result);
				push(stack, result);
				break;
		}
	}while(1);

}

double calc(double value1, double value2, char operator){
	double result = 0;

	switch(operator){
		case '*':
			result = value1 * value2;
			break;
		case '/':
			result = value1 / value2;
			break;
		case '+':
			result = value1 + value2;
			break;
		case '-':
			result = value1 - value2;
			break;
	}

	return result;
}


int isNumber(char *input) {
    if (*input == '-' || *input == '+') input++;
    if (*input == '\0') {
        return 0;
    }

    while (isdigit(*input)) input++;

    if (*input == '.') {
        input++;
        while (isdigit(*input)) input++;
    }

    if (*input == 'e' || *input == 'E') {
        input++;
        while (isdigit(*input)) input++;
    }

    return *input == '\0';
}


char getOp(char *input) {
    return isNumber(input) ? NUMBER : *input;
}
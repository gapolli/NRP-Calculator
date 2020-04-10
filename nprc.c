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
 * Notation) write in C.
 */


/************************* LIBRARIES SECTION **************************/

/*
 * Libraries
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

/*
 * Function headers
 */
int initStack(NODEPTR **start); //start an empty stack
int empty(NODEPTR **stack); //verifies if the stack is empty
void push(NODEPTR **stack, double data); //insert a node into the stack
int pop(NODEPTR **stack); //remove a node from the stack and return status
void menu(NODEPTR **stack); //prints an options menu on screen
double calc(); //calculates the result
int print(NODEPTR *stack);

/*********************** MAIN FUNCTION SECTION ************************/

/*
 * main function
 */
int main(int argc, char* argv[]){
	NODEPTR *stack;

	initStack(&stack);

	menu(&stack);
	return 0; //need to return system status
}


/************************* FUNCTIONS SECTION **************************/

/*
 * start an empty stack
 */
int initStack(NODEPTR **start){
	*start = NULL;
	return 1; //success
}

/*
 * verifies if the stack is empty
 */
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
		//Lista vazia
		return 0;
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

/*
 * insert a node into the stack
 */
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

/*
 * remove a node from the stack
 */
int pop(NODEPTR **stack){
	// char* data = (char*) malloc(sizeof(char));
	double data = 0;
	NODEPTR *ptr;

	if(empty(stack)){
		return 0; // failure: underflow
	}

	ptr = (*stack)->next;
	data = ptr->data;

	if(ptr == *stack){
		*stack = NULL;
	}
	else{
		(*stack)->next = ptr->next;
	}

	free(ptr);

	return 1; //success
}

/*
 * prints an options menu on screen
 */
void menu(NODEPTR **stack){
	double inputValue = 0;
	char operator;
	int err;

	do{
		err = empty(stack);
		if(err == 1){
			printf("The stack is empty\n\n");
		}
		scanf("%lf", &inputValue);
		push(stack, inputValue);
		print(*stack);
	}while(1);

}

/*
 * calculates the result
 * 
 * TODO: this function needs to verify if the data is either a numeric
 * value or a char value and do the cast if necessary
 */
double calc(){
	return 0; //need to return some value
}

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
	char* data;
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
void push(NODEPTR **stack, char* data); //insert a node into the stack
int pop(NODEPTR **stack); //remove a node from the stack and return status
void menu(); //prints an options menu on screen
double calc(); //calculates the result


/*********************** MAIN FUNCTION SECTION ************************/

/*
 * main function
 */
int main(int argc, char* argv[]){
	menu();
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

/*
 * insert a node into the stack
 */
void push(NODEPTR **stack, char* data){
	NODEPTR *ptr = (NODEPTR*) malloc(sizeof(NODEPTR));
	strcpy(ptr->data, data);
	if(empty(stack)){
		*stack = ptr;
	}
	else{
		ptr->next = (*stack)->next;
	}
	(*stack)->next = ptr;
}

/*
 * remove a node from the stack
 */
int pop(NODEPTR **stack){
	char* data = (char*) malloc(sizeof(char));
	NODEPTR *ptr;
	if(empty(stack)){
		return 0; //failure: underflow
	}
	ptr = (*stack)->next;
	strcpy(data, ptr->data);
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
void menu(){
	
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

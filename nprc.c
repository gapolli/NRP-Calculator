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


/************************* STRUCTURES SECTION *************************/

/*
 * Data structures
 */
typedef struct Node{
	int data;
	struct Node *next;
} NODEPTR;


/************************** HEADERS SECTION ***************************/

/*
 * Function headers
 */
int initStack(NODEPTR **start); //start an empty stack
int empty(NODEPTR **stack); //verifies if the stack is empty
void push(); //insert a node into the stack
void pop(); //remove a node from the stack
double calc(); //calculates the result


/*********************** MAIN FUNCTION SECTION ************************/

/*
 * main function
 */
int main(int argc, char* argv[]){
	return 0; //need to return system status
}


/************************* FUNCTIONS SECTION **************************/

/*
 * start an empty stack
 */
int initStack(NODEPTR **start){
	return 0;
}

/*
 * verifies if the stack is empty
 */
int empty(NODEPTR **stack){
	return 0; //need to return status
}

/*
 * insert a node into the stack
 */
void push(){
	
}

/*
 * remove a node from the stack
 */
void pop(){
	
}

/*
 * calculates the result
 */
double calc(){
	return 0; //need to return some value
}

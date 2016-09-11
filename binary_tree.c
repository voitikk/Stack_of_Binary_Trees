//Alex Voitik
//Compiler Construction
//Stack of Binary Trees
//Last Edit: Sun, Sept. 11th



#include "stdio.h"
#include <stdlib.h>

#define MAXSIZE  8

//struct for the binary tree
typedef struct treeNode
{
        int data;
        struct treeNode *left;
        struct treeNode *right;

}treeNode;

//holds name and pointer to binary tree
typedef struct stackElement
{
	
	char name;
	treeNode *bst;

}stackElement;

//the stack of binary trees
struct stack
{
    stackElement stk[MAXSIZE];
    int top;

};


//define the stack
typedef struct stack STACK;
STACK s;

//functions
void push(void);
int  pop(void);
void display(void);
void clearBuffer(void);
void initializeTree(void);
treeNode * Insert(treeNode *node,int data);
void PrintInorder(treeNode *node);

//main
int main(){
    s.top = -1;
    int finished = 1;

	//menu options
    while(finished == 1){
        
        char option;
        
		//FIX MENU ARGS
        printf("Please Enter an Option\n");
        printf("p(U)sh: Push an empth tree onto the stack\n");
        printf("p(O)p: Pop the top tree off the stack\n");
        printf("(A)dd: Add a symbol to the binary tree on the top of the stack\n");
        printf("(S)earch: Search for a symbol\n");
        printf("(Q)uit: Quit this program\n\n");
        scanf("%c", &option);
        
        switch (option) {
            case 'q' : finished = 0; break;

            case 'u' : printf("Option to Push\n"); push(); break;
                
            case 'o' : printf("Option to Pop\n"); pop(); break;
				
		    case 'd' : display(); break;

				//case 'i' : initializeTree();
                
		    case 'a' : printf("Enter Value to add to the tree\n");
				       int num;
				       scanf("%d", &num);
				       Insert(s.stk[s.top].bst, num); break;
                
		    case 's' : printf("Option to Search\n"); PrintInorder(s.stk[s.top].bst); break;
                
            default  : printf("Not Recognized\n\n"); break;
        }
        clearBuffer();
    }
    printf("Done\n");    
}

//don't read in the escape
void clearBuffer(){   
    while(getchar() != '\n');
}


/*****************************************************************************************
Playing with binary trees */
/*  http://www.cprogramming.com/tutorial/c/lesson18.html

void initializeTree(){
	treeNode *root = NULL; //root of the tree
	root = Insert(root, 8);
	root = Insert(root, 9);
	root = Insert(root, 1);
	PrintInorder(root);
	return;

	}*/

//FOR DEBUGGING PURPOSES, WORKS
void PrintInorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintInorder(node->left);
        printf("%d ",node->data);
        PrintInorder(node->right);
}

//WORKS FINE
treeNode * Insert(treeNode *node,int data)
{
        if(node==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }
        if(data >(node->data))
        {
                node->right = Insert(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = Insert(node->left,data);
        }
        /* Else there is nothing to do as the data is already in the tree. */
        return node;
}


//http://www.sanfoundry.com/c-program-stack-implementation/

//WORKS FINE
void push(){
	char name;
	stackElement newElement;
	treeNode *root = NULL;

    if (s.top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        printf ("Enter the name of the element to be pushed\n"); //gets name of the stack

		getchar(); //chew up newline
        name = getchar();
        s.top = s.top + 1;

		newElement.name = name; //assign name to newElement

		newElement.bst = Insert(root, 8); //bst points to the tree, initialized at 8

		printf("name = %c\n", newElement.name); //debugging
		printf("data = %d\n", newElement.bst -> data); //debugging
		//assign newElement to s.top (overload operator)
		s.stk[s.top] = newElement;
		printf("s.top = %d\n", (s.stk[s.top]).bst -> data); //debugging

		//here, s.stk[s.top].bst is the pointer to the binary tree in top
    }
    return;
}

//WORKS FINE
int pop ()
{
    int num;
    if (s.top == - 1)
    {
        printf ("Stack is Empty\n");
        return (s.top);
    }
    else
    {
        num = s.top;
        printf ("poped element is = %d\n", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return(num);
}

//PROBABLY DON'T NEED
void display ()
{
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The names of the stack items are: \n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%c\n", s.stk[i]);
        }
    }
    printf ("\n");
}

//NEED TO IMPLEMENT A SEARCH, BUT ONE IS GIVEN ON THE BINARY TREE SPEC

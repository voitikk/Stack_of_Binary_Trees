/*

Alex Voitik
Compiler Construction
Stack of Binary Trees
Last Edit: Sun, Sept. 15th

Stack and Binary Tree Functions based on code taken from
        - http://www.cprogramming.com/tutorial/c/lesson18.html
        - http://www.sanfoundry.com/c-program-stack-implementation/
        
Worked on this project with Kyle Quinn, we discussed how to visualize
the problem, and then we helped each other when errors presented
themselves.

*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE  8

//struct for the binary tree
typedef struct treeNode{
        int data;
        struct treeNode *left;
        struct treeNode *right;
}treeNode;

//holds name and pointer to binary tree
typedef struct stackElement {
	char name;
	treeNode *bst;
}stackElement;

//the stack of binary trees
struct stack{
    stackElement stk[MAXSIZE];
    int top;
};

//define the stack
typedef struct stack STACK;
STACK s;

//functions
void initialize();
void push(void);
int  pop(void);
void clearBuffer(void);
treeNode * Insert(treeNode *node,int data);
treeNode * search(int key, treeNode *leaf);

//main
int main(){
        
    s.top = -1;
    int finished = 1;
    initialize(); //initialize stack with name 'o' with one element, 8
    while(finished == 1){
        
        char option;
        
		//Menu Args
        printf("Please Enter an Option\n");
        printf("p(U)sh: Push an empty tree onto the stack\n");
        printf("p(O)p: Pop the top tree off the stack\n");
        printf("(A)dd: Add a symbol to the binary tree on the top of the stack\n");
        printf("(S)earch: Search for a symbol\n");
        printf("(Q)uit: Quit this program\n\n");
        
        scanf("%c", &option);
        
        switch (option) {
            case 'q' : finished = 0; break;
                
            case 'u' : push(); break;
                
            case 'o' : pop(); break;
                
		    case 'a' : printf("Enter Value to add to the tree\n");
				       int num;
				       scanf("%d", &num);
				       s.stk[s.top].bst = Insert(s.stk[s.top].bst, num);
                       break;
                       
		    case 's' : printf("What do you want to search for?\n");
                       int item;
                       int found = 0;
                       int i = s.top;
                       scanf("%d", &item);
                       
                       //loops through all the trees to find the item
                       for(i; i >= 0; i--){
                                if(search(item, s.stk[i].bst)){
                                     printf("Item Found in tree %c\n\n", s.stk[i].name);
                                     found = 1;
                                     break;
                                }      
                       }
                       if(!found){
                                printf("Item not found\n");
                       }
                       //the pointer to the value you are searching for is held in (s.stk[i].bst) -> data
                       break;
                
            default  : printf("Not Recognized\n\n"); break;
        }
        clearBuffer();
    }
    printf("Done\n");    
}

//doesn't read in the escape
void clearBuffer(){   
    while(getchar() != '\n');
}

//initialize the stack with one tree and one element
void initialize(){
	stackElement newElement;
	treeNode *root = 0;
    s.top = s.top + 1;
    newElement.name = 'o'; //assign name to newElement
    newElement.bst = Insert(root, 8); //bst points to the tree, initialized at 8
    s.stk[s.top] = newElement;
}

//pushes empty tree onto the stack
void push(){

	char name;
	stackElement newElement;
	treeNode *root = 0;

    if (s.top == (MAXSIZE - 1)){
        printf ("Stack is Full\n");
        return;
    }
    else{
        name = s.stk[s.top].name + 1;
        s.top = s.top + 1;
		newElement.name = name; //assign name to newElement
		newElement.bst = 0;//bst points to the null tree
		s.stk[s.top] = newElement;
    }
    return;
}

//Inserts a leaf, in sorted order, to the tree passes to it
treeNode * Insert(treeNode *node,int data){
        if(node==0){
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }
        if(data >(node->data)){
                node->right = Insert(node->right,data);
        }
        else if(data < (node->data)){
                node->left = Insert(node->left,data);
        }
        /* Else there is nothing to do as the data is already in the tree. */
        return node;
}

//Pops a tree off of the stack
int pop (){
        
    int num;
    if (s.top == - 1){
        printf ("Stack is Empty\n");
        return (s.top);
    }
    else{
        num = s.top;
        s.top = s.top - 1;
    }
    return(num);
}

//Searches a tree for an element. If found, a pointer to the value is returned.
//if not found, 0 is returned.
treeNode * search(int key, treeNode *leaf){
  if( leaf != 0 ){
      if(key==leaf->data){
          return leaf;
      }
      else if(key<leaf->data){
          return search(key, leaf->left);
      }
      else{
          return search(key, leaf->right);
      }
  }
  else return 0;
}
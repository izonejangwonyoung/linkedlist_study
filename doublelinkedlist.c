//#include <stdio.h>
//#include <stdlib.h>
//
//struct NODE
//{
//    struct NODE* left;
//    int data;
//    struct NODE* right;
//};
//struct NODE* head;
//struct NODE* tail;
//
//
//struct NODE* makeNode(int value){
//    struct NODE *node = (struct NODE*)malloc(sizeof(struct NODE));
//    node->left = NULL;
//    node->data = value;
//    node->right = NULL;
//    return node;
//}
//
//
//void print(){
//    struct NODE *p;
//    p = head;
//    while(p-> right!= tail){
//        printf("%d ",p->data);
//        p = p-> right;
//    }
//    printf("%d ",p->data);
//}
//
//void reset(){
//    head = (struct NODE*)malloc(sizeof(struct NODE));
//    tail = (struct NODE*)malloc(sizeof(struct NODE));
//    head->data=10 ;
//    tail->data=0;
//
//    head->right = tail;
//    tail->right = tail;
//    head->left = head;
//    tail->left = head;
//}
//
//
//void addNode(int value){
//    struct NODE* newNode = makeNode(value);
//    struct NODE* p;
//    p = tail;
//    p->left->right = newNode; //꼬리의 left포인터가 가리키는 노드(처음엔 head)의 right 포인터에게 newnode 가리키게 하자
//    newNode->left = p->left; //뉴노드 left 포인터를 tail의 left가 가리키는 노드 가리키게 하자(처음엔 head를 가리키게 되는 것) 여기서 뉴노드의 헤드 연결 끝
//    p->left = newNode;  //tail left 포인터를 뉴노드에 연결
//    newNode->right = p; // 뉴노드 right  포인터 tail연결  /연결 끝/
//}
//void removenode(int value){
//    struct NODE* p;
//    p = head->right;
//    while(p->right != tail){
//        if(p->data == value){
//            p->right->left = p->left;
//            p->left->right = p->right;
//            free(p);
//            return;
//        }
//        p = p->right;
//    }
//}
//
//
//int main(){
//reset();
//    addNode(10);
//    addNode(20);
//    addNode(30);
//    addNode(40);
//    addNode(50);
//
//    addNode(5);
//    addNode(25);
//    addNode(55);
//
//    removenode(10);
//    removenode(30);
//    removenode(50);
//
//    print();  //출력
//}

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
void push(int);
char pop();
void infix_to_prefix();
int precedence (char);
char stack[20],infix[20],prefix[20];
int top = -1;

int main()
{
    printf("\nINPUT THE INFIX EXPRESSION : ");
    scanf("%s",infix);
    infix_to_prefix();
    return 0;
}
// method that pushes the elements onto the character stack
void push(int pos)
{
    if(top == MAX-1)
    {
        printf("\nSTACK OVERFLOW\n");
    }
    else {
        top++;
        stack[top] = infix[pos];
    }}

// method that removes character from stack and returns them
char pop()
{
    char ch;
    if(top < 0)
    {
        printf("\nSTACK UNDERFLOW\n");
        exit(0);
    }
    else
    {
        ch = stack[top];
        stack[top] = '\0';
        top--;
        return(ch);
    }
    return 0;
}
// method that converts String from infix to prefix
// all the strings are assumed to be valid expressions

void infix_to_prefix()
{
    int i = 0,j = 0;
    strrev(infix); // Reverse the infix expression
    while(infix[i] != '\0')
    {
// if an alphabet is found then copy it to the output string
        if(infix[i] >= 'a' && infix[i] <= 'z')
        {
            prefix[j] = infix[i];
            j++;
            i++;
        }
// In the reversed string, closing bracket will be found first so put it in the stack
        else if(infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
        {
            push(i);
            i++;
        }
// if an opening bracket is found, then
        else if(infix[i] == '(' || infix[i] == '{' || infix[i] == '[') /* when closing bracket is found */
        {
            if(infix[i] == '(')
            {
                while(stack[top] != ')') /* pop till opening bracket is found */
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
                i++;
            }
            else if(infix[i] == '[')
            {
                while(stack[top] != ']') /* pop till corresponding opening bracket is found */
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
                i++;
            }
            else if(infix[i] == '{')
            {
                while(stack[top] != '}') /*pop till corresponding opening bracket is found*/
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
                i++;
            }}
        else
        {
// if the stack if empty, then we simply put the operator in stack
            if(top == -1)
            {
                push(i);
                i++;
            }
// if the precedence of operator is less than the stack top then
            else if( precedence(infix[i]) < precedence(stack[top]))
            {
                prefix[j] = pop();  // pop the stack top and add it to the prefix string
                j++;
// if you have an operator that has precedence greater than operator
                while(precedence(stack[top]) > precedence(infix[i])){
                    prefix[j] = pop();    // Pop the operator
                    j++;
                    if(top < 0) {
                        break;
                    }}
                push(i);
                i++;
            }
// if the precedence of operator is greater than or equal to the stack top
            else if(precedence(infix[i]) >= precedence(stack[top]))
            {
                push(i);  //  Push it onto the stack
                i++;
            }}}
// At the end remove all the operators from the stack
    while(top != -1)
    {
        prefix[j] = pop();
        j++;
    }
// Reverse the final string before output
    strrev(prefix);
    prefix[j] = '\0';
    printf("EQUIVALENT PREFIX NOTATION : %s ",prefix);
}

/* Function to return precedence of operators */
int precedence(char alpha)
{
    if(alpha == '+' || alpha =='-')
    {
        return(1);
    }
    if(alpha == '*' || alpha =='/')
    {
        return(2);
    }
    return 0;
}

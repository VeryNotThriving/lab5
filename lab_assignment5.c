
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
char letter;
struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
    int count =0;
    while(head != NULL){
        head=head->next;
        count++;
    }
    return count;
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    struct node* temp=head;
    int len = length(head);
    char Cstring = (char*)malloc((len+1)*sizeof(char));
    int i=0;
    for(; i<len;i++){
        Cstring[i]=head->letter;
        head=head->next;
    }
    Cstring[i]='\0';
    return Cstring;
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->letter = c;
    newNode->next = NULL;
    if(*pHead ==NULL){
        *pHead=newNode;
        return;
    }
    struct node* temp= *pHead;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{   
    struct node* temp = *pHead;
    while(pHead!=NULL){
        free(temp);
        temp=temp->next;
    }
    
    
}
int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
    }

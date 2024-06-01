#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    node*next;
}node;
node*createnode(int data)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data =data;
    newnode->next=NULL;
    return newnode;
}

void addatpos(node*head,int pos){
    node*temp=head;
    node*newadd=createnode(99);
    while(pos!=2){
        temp=temp->next;
        pos--;
    }
    printf("reached at %d \n", temp->data);
    newadd->next=temp->next;
    temp->next=newadd;
    
}

int main() {
        struct node*head=createnode(1);
        struct node*sec=createnode(2);
        struct node*th=createnode(3);
        struct node*tail=createnode(4);
        head->next=sec;
        sec->next=th;
        th->next=tail;
//add node at 3rd pos
addatpos(head,3);
node*temp = head;
while(temp!=NULL)
{
    printf("%d ->",temp->data);
    temp=temp->next;
}
printf("NUll");
        return 0;
}

//Implementation of Queue using Singly Linked List

#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node Node;

struct Queue{
    Node *front, *rear;
};
typedef struct Queue Queue;

void insert(Queue *,int);
void delete(Queue *);
void traverse(Queue *);
Node * createNode(int);

int main(){
    Queue Q;
    Q.front = NULL;
    Q.rear = NULL;
    insert(&Q,1);
    insert(&Q,3);
    insert(&Q,2);
    insert(&Q,4);
    traverse(&Q);
    delete(&Q);
    delete(&Q);
    traverse(&Q);
    insert(&Q,7);
    insert(&Q,22);
    insert(&Q,13);
    traverse(&Q);
    delete(&Q);
    traverse(&Q);
    return 0;
}

void insert(Queue *Q, int data){
    Node *newnode = createNode(data);
    if(newnode)
        printf("Inserting element %d in Queue\n",data);
    if(Q->front == NULL){
        Q->rear = newnode;
        Q->front = Q->rear;
        return ;
    }
    Q->rear->next = newnode;
    Q->rear = newnode;
}

void delete(Queue *Q){
    Node *temp;
    if(Q->front==NULL){
        printf("Queue is empty. Underflow");
        return ;
    }
    temp = Q->front;
    Q->front = Q->front->next;
    printf("\nElement deleted is %d",temp->data);
    return ;
}

void traverse(Queue *Q){
    Node *temp;
    temp = Q->front;
    printf("\nQueue is:\n");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* createNode(int data){
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

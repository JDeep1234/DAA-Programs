#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

struct queue
{
    int front, rear;
    char message[SIZE][30];
};
typedef struct queue QUEUE;

void sender(QUEUE *q, char msg[30])
{
    if (q->front == (q->rear + 1) % SIZE)
        printf("\nThe message queue is full.\n");
    else
    {
        q->rear = (q->rear + 1) % SIZE;
        strcpy(q->message[q->rear], msg);
        if (q->front == -1)
            q->front = 0;
    }
}

char *reciever(QUEUE *q)
{
    char *msg;
    if (q->front == -1)
    {
        printf("\nThe message queue is empty.\n");
        return NULL;
    }

    else
    {
        msg = q->message[q->front];
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
            q->front = (q->front + 1) % SIZE;
        return msg;
    }
}

void display(QUEUE q)
{
    int i;
    if (q.front == -1)
        printf("\nThe message queue is empty.\n");
    else
    {
        printf("\nThe messages are : \n");
        for (i = 0; i != q.rear; i = (i + 1) % SIZE)
            printf("%s\n", q.message[i]);
        printf("%s\n", q.message[i]);
    }
}

int main()
{
    QUEUE q;
    q.front = -1;
    q.rear = -1;
    int ch;
    char msg[20], *ptr;
    for (;;)
    {
        printf("\nEnter the choices to perform.\n1.Send a message\n2.Recieve a message.\n3.Display all messages.\n4.Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &ch);
        getchar();
        switch (ch)

        {
        case 1:
            printf("\nEnter the message : ");
            scanf("%s", msg);
            sender(&q, msg);

            break;

        case 2:
            ptr = reciever(&q);
            printf("The message is : %s\n", ptr);
            break;

        case 3:
            display(q);
            break;

        default:
            exit(0);
        }
    }
}
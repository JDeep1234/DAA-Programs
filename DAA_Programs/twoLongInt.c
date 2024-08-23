#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *addr;
};
typedef struct node *NODE;

NODE insertBegin(NODE head, int item)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->addr = NULL;
    if (head->addr == NULL)
    {
        head->addr = temp;
        return head;
    }
    temp->addr = head->addr;
    head->addr = temp;
    return head;
}

NODE insertEnd(NODE head, int item)
{
    NODE temp, curr;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->addr = NULL;
    if (head->addr == NULL)
    {
        head->addr = temp;
        return head;
    }
    curr = head->addr;
    while (curr->addr != NULL)

        curr = curr->addr;

    curr->addr = temp;
    return head;
}

void display(NODE head)
{
    NODE temp;
    if (head->addr == NULL)
    {
        printf("\nList is empty\n");
    }

    else
    {
        temp = head->addr;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->addr;
        }
    }
}

NODE revese(NODE head)
{
    NODE curr, prev, next;
    curr = head->addr;
    prev = NULL;
    while (curr != NULL)
    {
        next = curr->addr;
        curr->addr = prev;
        prev = curr;
        curr = next;
    }
    head->addr = prev;
    return head;
}

void appendZero(NODE head1, NODE head2)
{
    NODE curr;
    int count1 = 0, count2 = 0, i;
    curr = head1->addr;
    while (curr != NULL)
    {
        count1 += 1;
        curr = curr->addr;
    }
    curr = head2->addr;
    while (curr != NULL)
    {
        count2 += 1;
        curr = curr->addr;
    }
    if (count1 > count2)
    {
        for (i = 0; i < (count1 - count2); i++)
            head2 = insertBegin(head2, 0);
    }
    else
    {
        for (i = 0; i < (count2 - count1); i++)
            head1 = insertBegin(head1, 0);
    }
}

void add(NODE head1, NODE head2)
{
    int sum = 0, carry = 0;
    NODE head, t1, t2;
    head = (NODE)malloc(sizeof(struct node));
    head->addr = NULL;
    head1 = revese(head1);
    head2 = revese(head2);
    t1 = head1->addr;
    t2 = head2->addr;
    if (t1 == NULL)
    {
        printf("\nT1 is NULL\n");
    }

    while (t1 != NULL)
    {
        sum = t1->data + t2->data + carry;
        carry = sum / 10;
        // printf("\nCarry: %d", carry);
        sum = sum % 10;
        // printf("\nSum : %d", sum);
        head = insertBegin(head, sum);
        t1 = t1->addr;
        t2 = t2->addr;
    }
    if (carry > 0)
        head = insertBegin(head, carry);
    printf("\nResult is : ");
    display(head);
    printf("\n");
}

int main()
{
    NODE head1, head2;
    char first[20], sec[20];
    int i;
    printf("\nRead 1st number: ");
    scanf("%s", first);
    head1 = (NODE)malloc(sizeof(struct node));
    head1->addr = NULL;
    for (i = 0; first[i] != '\0'; i++)
        head1 = insertEnd(head1, first[i] - '0');
    printf("First number is : %s\n", first);
    printf("\nRead 2nd number: ");
    scanf("%s", sec);
    head2 = (NODE)malloc(sizeof(struct node));
    head2->addr = NULL;
    for (i = 0; sec[i] != '\0'; i++)
        head2 = insertEnd(head2, sec[i] - '0');
    printf("Second number is : %s\n", sec);

    appendZero(head1, head2);

    add(head1, head2);
    return 0;
}
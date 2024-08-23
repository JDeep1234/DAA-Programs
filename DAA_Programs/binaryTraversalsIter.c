#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

void preorder_iter(NODE root)
{
    NODE curr, s[10];
    int top = -1;
    if (root == NULL)
    {
        printf("\nNo Traversal.\n");
        return;
    }
    curr = root;

    while (top != -1 || curr != NULL)
    {
        if (curr != NULL)
        {
            printf("%d\t", curr->data);
            s[++top] = curr;
            curr = curr->left;
        }
        else
        {
            curr = s[top--];
            curr = curr->right;
        }
    }

    /*while (1)
    {
        while (curr != NULL)
        {
            s[++top] = curr;
            printf("%d\t", curr->data);
            curr = curr->left;
        }
        if (top != -1)
        {
            s[top--] = curr;
            curr = curr->right;
        }
        else
            return;
    }*/
}

void inorder_iter(NODE root)
{
    NODE curr, s[10];
    int top = -1;
    if (root == NULL)
    {
        printf("\nNo Traversal.\n");
        return;
    }
    curr = root;

    while (top != -1 || curr != NULL)
    {
        if (curr != NULL)
        {

            s[++top] = curr;
            curr = curr->left;
        }
        else
        {
            curr = s[top--];
            printf("%d\t", curr->data);
            curr = curr->right;
        }
    }

    /*while (1)
    {
        while (curr != NULL)
        {
            s[++top] = curr;

            curr = curr->left;
        }
        if (top != -1)
        {
            s[top--] = curr;
            printf("%d\t", curr->data);
            curr = curr->right;
        }
        else
            return;
    }*/
}

void postorder_iter(NODE root)
{
    NODE curr, s1[10], s2[10];
    int top1 = -1, top2 = -1;

    if (root == NULL)
    {
        printf("\nNo Traversal.\n");
        return;
    }
    curr = root;

    while (top1 != -1 || curr != NULL)
    {
        if (curr != NULL)
        {
            if (curr->right != NULL)
                s2[++top2] = curr->right;
            s1[++top1] = curr;
            curr = curr->left;
        }
        else
        {
            curr = s1[top1];
            if (top2 != -1 && curr->right == s2[top2])
                curr = s2[top2--];
            else
            {
                printf("%d\t", curr->data);
                s1[top1--];
                curr = NULL;
            }
        }
    }

    /*while (1)
    {
        while (curr != NULL)
        {
            s[++top] = curr;

            curr = curr->left;
        }
        if (top != -1)
        {
            s[top--] = curr;

            curr = curr->right;
        }
        else
            printf("%d\t", curr->data);
    }*/
}

int height(NODE root)
{
    int leftheight, rightheight;
    if (root == NULL)
        return 0;
    else
    {
        leftheight = height(root->left);
        rightheight = height(root->right);
        if (leftheight > rightheight)
            return (leftheight + 1);
        else
            return (rightheight + 1);
    }
}

int countLeaf(NODE root)
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else
    {
        return (countLeaf(root->left) + countLeaf(root->right));
    }
}

int countNonleaf(NODE root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    else
        return (countNonleaf(root->left) + countNonleaf(root->right) + 1);
}

NODE createNode(int item)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insertLeft(NODE root, int item)
{
    root->left = createNode(item);
}

void insertRight(NODE root, int item)
{
    root->right = createNode(item);
}

int countNodes(NODE root)
{
    if (root == NULL)
        return 0;
    else
        return (countNodes(root->left) + countNodes(root->right) + 1);
}

int main()
{
    NODE root = NULL;
    root = createNode(10);
    insertLeft(root, 20);
    insertRight(root, 30);
    insertLeft(root->left, 40);
    insertRight(root->left, 50);
    insertLeft(root->right, 60);
    printf("\nLeaf %d Nonleaf %d height %d Nodes %d\n", countLeaf(root), countNonleaf(root), height(root), countNodes(root));
    printf("\nPREORDER\n");
    preorder_iter(root);
    printf("\nINORDER\n");
    inorder_iter(root);
    printf("\nPOSTORDER\n");
    postorder_iter(root);

    return 0;
}
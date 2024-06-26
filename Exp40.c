#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

struct node* constructTreeUtil(int pre[], int post[], int* preIndex, int l, int h, int size)
{
    if (*preIndex >= size || l > h)
        return NULL;

    struct node* root = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (l == h)
        return root;

    int i;
    for (i = l; i <= h; i++)
        if (post[i] == pre[*preIndex])
            break;

    if (i <= h)
    {
        root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil(pre, post, preIndex, i + 1, h, size);
    }

    return root;
}

struct node* constructTree(int pre[], int post[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, post, &preIndex, 0, size - 1, size);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main()
{
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(pre) / sizeof(pre[0]);

    struct node* root = constructTree(pre, post, size);

    printf("Postorder traversal of the constructed tree is : \n");
    printPostorder(root);

    return 0;
}

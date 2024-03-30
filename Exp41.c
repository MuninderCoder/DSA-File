#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* createNode(int data) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void printPostorder(struct node* root) {
  if (root == NULL)
    return;

  printPostorder(root->left);
  printPostorder(root->right);
  printf("%d ", root->data);
}

int main() {
  struct node* root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);

  printf("Postorder traversal of the binary tree is: ");
  printPostorder(root);

  return 0;
}

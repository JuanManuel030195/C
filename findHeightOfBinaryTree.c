#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int GetNodeHeight(struct Node* node);

struct Node* CreateNode(int data);

void FreeNode(struct Node* node);

int main() {
   struct Node* root = CreateNode(1);
   root->left = CreateNode(2);
   root->right = CreateNode(3);

   root->left->left = CreateNode(4);
   root->left->right = CreateNode(5);

   root->right->left = CreateNode(6);
   root->right->right = CreateNode(7);

   root->right->left->left = CreateNode(8);
   root->right->left->right = CreateNode(9);

   int height = GetNodeHeight(root);
   printf("Height of the binary tree is: %d\n", height);

    // Free allocated memory
    FreeNode(root);

    return 0;
}

int GetNodeHeight(struct Node* node) {
    if (node == NULL) {
        return 0;
    }

    int leftHeight = GetNodeHeight(node->left);
    int rightHeight = GetNodeHeight(node->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

struct Node* CreateNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void FreeNode(struct Node* node) {
    if (node != NULL) {
        FreeNode(node->left);
        FreeNode(node->right);
        free(node);
    }
}

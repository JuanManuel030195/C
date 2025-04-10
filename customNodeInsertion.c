#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* CreateNode(int data);

void FreeNode(struct Node* node);

void InsertNodeAtPosition(struct Node* root, struct Node* addedNode, int position);

void InsertNodeAtTheBeginning(struct Node** root, struct Node* addedNode);

void InsertNodeAtTheEnd(struct Node* root, struct Node* addedNode);

void PrintList(struct Node* root);

int main() {
   struct Node* root = CreateNode(1);

   printf("Initial List: ");
   PrintList(root);

   struct Node* node2 = CreateNode(2);
   InsertNodeAtTheBeginning(&root, node2);
   printf("After inserting 2 at the beginning: ");
   PrintList(root);

   struct Node* node3 = CreateNode(3);
   InsertNodeAtTheEnd(root, node3);
   printf("After inserting 3 at the end: ");
   PrintList(root);

   struct Node* node4 = CreateNode(4);
   InsertNodeAtPosition(root, node4, 1);
   printf("After inserting 4 at position 2: ");
   PrintList(root);

   return 0;
}

struct Node* CreateNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void InsertNodeAtPosition(struct Node* root, struct Node* addedNode, int position) {
    struct Node* current = root;
    struct Node* previous = NULL;

    for (int i = 0; i < position && current != NULL; i++) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        addedNode->next = root;
        root = addedNode;
    } else {
        previous->next = addedNode;
        addedNode->next = current;
    }
}

// Using double pointer to modify the root pointer itself, not only the data
void InsertNodeAtTheBeginning(struct Node** root, struct Node* addedNode) {
   addedNode->next = *root;
   *root = addedNode;
}

void InsertNodeAtTheEnd(struct Node* root, struct Node* addedNode) {
    struct Node* current = root;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = addedNode;
}

void FreeNode(struct Node* node) {
    if (node != NULL) {
        FreeNode(node->next);
        free(node);
    }
}

void PrintList(struct Node* root) {
    struct Node* current = root;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

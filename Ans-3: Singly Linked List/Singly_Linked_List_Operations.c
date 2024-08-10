#include <stdio.h>
#include <stdlib.h>

// Definition of the node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node at the end of the list
void addNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node by position
void deleteNodeByPosition(struct Node** head, int position) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    struct Node* next = temp->next->next;

    free(temp->next);
    temp->next = next;
}

// Function to delete all nodes with a particular data
void deleteNodesByValue(struct Node** head, int value) {
    while (*head != NULL && (*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    struct Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == value) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Function to delete the entire linked list
void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

// Function to display the linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to display the linked list in reverse order
void displayInverted(struct Node* head) {
    if (head == NULL) return;
    displayInverted(head->next);
    printf("%d -> ", head->data);
}

// Function to calculate total memory occupied by the linked list
void totalMemoryOccupied(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    printf("Total memory occupied by the linked list: %zu bytes\n", count * sizeof(struct Node));
}

// Function to delete all nodes with a particular data and the next subsequent node
void deleteNodesByValueAndNext(struct Node** head, int value) {
    while (*head != NULL && (*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            struct Node* temp2 = *head;
            *head = (*head)->next;
            free(temp2);
        }
        free(temp);
    }

    struct Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == value) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            if (current->next != NULL) {
                struct Node* temp2 = current->next;
                current->next = current->next->next;
                free(temp2);
            }
            free(temp);
        } else {
            current = current->next;
        }
    }
}

int main() {
    struct Node* head = NULL;

    addNode(&head, 1);
    addNode(&head, 5);
    addNode(&head, 3);
    addNode(&head, 5);
    addNode(&head, 5);
    addNode(&head, 4);

    printf("Original List: ");
    displayList(head);

    deleteNodeByPosition(&head, 2);
    printf("After deleting node at position 2: ");
    displayList(head);

    deleteNodesByValue(&head, 5);
    printf("After deleting nodes with value 5: ");
    displayList(head);

    totalMemoryOccupied(head);

    addNode(&head, 6);
    addNode(&head, 5);
    addNode(&head, 7);
    printf("After adding new nodes: ");
    displayList(head);

    deleteNodesByValueAndNext(&head, 5);
    printf("After deleting nodes with value 5 and subsequent node: ");
    displayList(head);

    printf("Inverted List: ");
    displayInverted(head);
    printf("NULL\n");

    deleteList(&head);
    printf("After deleting the entire list: ");
    displayList(head);

    return 0;
}

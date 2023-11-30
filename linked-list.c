#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new element at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to display the elements of the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to delete the first element from the linked list
struct Node* deleteFirstNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("First element deleted.\n");
    return head;
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    // Insert elements at the beginning
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 7);
    head = insertAtBeginning(head, 12);

    // Display the linked list
    displayList(head);

    // Delete the first element
    head = deleteFirstNode(head);

    // Display the linked list after deletion
    displayList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}

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

int main() {
    struct Node* head = NULL; // Initialize an empty linked list
    int choice, data;

    do {
        // Menu
        printf("\nMenu:\n");
        printf("1. Create linked list\n");
        printf("2. Add at the beginning\n");
        printf("3. Display linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create linked list
                printf("Enter the data for the first node: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printf("Linked list created.\n");
                break;

            case 2:
                // Add at the beginning
                if (head == NULL) {
                    printf("Linked list is not created. Create a linked list first.\n");
                } else {
                    printf("Enter the data to be added at the beginning: ");
                    scanf("%d", &data);
                    head = insertAtBeginning(head, data);
                    printf("Data added at the beginning.\n");
                }
                break;

            case 3:
                // Display linked list
                if (head == NULL) {
                    printf("Linked list is empty.\n");
                } else {
                    displayList(head);
                }
                break;

            case 4:
                // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free the memory allocated for the linked list
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

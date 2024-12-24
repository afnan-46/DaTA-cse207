#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char village[50];
    int postNumber;
    char district[50];
    int nidNumber;
    struct Node* next;
};

struct Node* createNode(const char* name, const char* village, int postNumber, const char* district, int nidNumber) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    strcpy(newNode->village, village);
    newNode->postNumber = postNumber;
    strcpy(newNode->district, district);
    newNode->nidNumber = nidNumber;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("Name: %s\t", temp->name);
        printf("Village: %s\t", temp->village);
        printf("Post Number: %d\t", temp->postNumber);
        printf("District: %s\t", temp->district);
        printf("NID Number: %d\t", temp->nidNumber);
        printf("\n");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    head = createNode("Fahim", "Green Village", 12345, "Dhaka", 1001);
    head->next = createNode("Afnan", "Blue Village", 67890, "Khulna", 1002);
    head->next->next = createNode("Sajid", "Yellow Village", 11223, "Rangpur", 1003);

    printf("NID Information List:\n");
    printList(head);


    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

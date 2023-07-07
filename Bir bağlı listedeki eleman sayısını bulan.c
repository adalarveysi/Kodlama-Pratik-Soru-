#include <stdio.h>
#include <stdlib.h>

// Bağlı liste düğüm yapısı
struct Node {
    int data;
    struct Node* next;
};

// Yeni düğüm oluşturma
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Bağlı listeye eleman ekleme
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Bağlı listedeki eleman sayısını bulma
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Bağlı listeyi yazdırma
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Bağlı listeye eleman ekleme
    insertNode(&head, 5);
    insertNode(&head, 2);
    insertNode(&head, 9);
    insertNode(&head, 1);
    insertNode(&head, 7);

    printf("Bağlı liste: ");
    printList(head);

    int count = countNodes(head);
    printf("Eleman sayısı: %d\n", count);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void displayList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* append(Node* head, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* deleteAfter(Node* head, int key) {
    if (head == NULL) return NULL;

    Node* current = head;
    while (current->next != NULL && current->data != key) {
        current = current->next;
    }

    if (current != NULL && current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return head;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* myList = NULL;
    int operation, value, key;

    do {
        printf("\nOperation a effectuer:\n");
        printf("1 - Afficher\n");
        printf("2 - Ajouter un element a la fin de la liste\n");
        printf("3 - Supprimer apres l'element\n");
        printf("0 - Quitter\n");
        printf("Operation ? ");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                displayList(myList);
                break;
            case 2:
                printf("Veuillez entrer la valeur a ajouter : ");
                scanf("%d", &value);
                myList = append(myList, value);
                break;
            case 3:
                printf("Veuillez entrer l'element apres lequel supprimer : ");
                scanf("%d", &key);
                myList = deleteAfter(myList, key);
                break;
            case 0:
                printf("Programme termine.\n");
                break;
            default:
                printf("Operation invalide.\n");
        }
    } while (operation != 0);

    freeList(myList);

    return 0;
}

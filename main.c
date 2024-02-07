#include <stdio.h>
#include <stdlib.h>

// Structure d'un élément de la liste chaînée
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Affichage de la liste
void displayList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Ajout d'un élément à la fin de la liste
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

// Suppression de l'élément suivant l'élément donné
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

// Libérer la mémoire de la liste chaînée
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
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

    // Libérer la mémoire de la liste chaînée avant de quitter
    freeList(myList);

    return 0;
}
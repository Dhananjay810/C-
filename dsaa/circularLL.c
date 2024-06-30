#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *ins(struct node *cll, int data, int val) {
    struct node *b = malloc(sizeof(struct node));
    if (cll == NULL) {
        printf("List is empty\n");
        return cll;
    }
    struct node *a = cll;
    while (a->next != cll && a->info != data) {
        a = a->next;
    }
    if (a->info == data) {
        b->info = val;
        b->next = a->next;
        a->next = b;
    } else {
        printf("Data not found\n");
        free(b);
    }
    return cll;
}

struct node *begin(struct node *cll, int val) {
    struct node *b = malloc(sizeof(struct node));
    b->info = val;
    if (cll == NULL) {
        b->next = b;
        return b;
    }
    struct node *a = cll;
    while (a->next != cll) {
        a = a->next;
    }
    b->next = cll;
    a->next = b;
    return b;
}

struct node *del(struct node *cll, int data) {
    if (cll == NULL) {
        printf("List is empty\n");
        return cll;
    }
    struct node *a = cll;
    struct node *b = NULL;
    while (a->next != cll && a->info != data) {
        b = a;
        a = a->next;
    }
    if (a->info == data) {
        if (b == NULL) {
            struct node *temp = a->next;
            while (temp->next != cll) {
                temp = temp->next;
            }
            temp->next = a->next;
            cll = a->next;
        } else {
            b->next = a->next;
        }
        free(a);
    } else {
        printf("Data not found\n");
    }
    return cll;
}

void trans(struct node *cll) {
    if (cll == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *a = cll;
    do {
        printf("%d ", a->info);
        a = a->next;
    } while (a != cll);
    printf("\n");
}

int main() {
    struct node *cll = NULL;
    printf("Today we use Circular Linked List\n");
    printf("Enter '+' to insert a node at the beginning\n");
    printf("Enter '-' to insert a node other than the beginning\n");
    printf("Enter '*' to delete a node\n");
    printf("Enter '/' to traverse the list\n");

    int n = 900;
    char ch;
    while (n > 0) {
        printf("Enter any character: ");
        scanf(" %c", &ch);
        if (ch == '+') {
            int x;
            printf("Enter the value you want to insert: ");
            scanf("%d", &x);
            cll = begin(cll, x);
        } else if (ch == '-') {
            int data;
            printf("Enter the value after which you want to insert: ");
            scanf("%d", &data);
            int x;
            printf("Enter the value you want to insert: ");
            scanf("%d", &x);
            cll = ins(cll, data, x);
        } else if (ch == '*') {
            int data;
            printf("Enter the value you want to delete: ");
            scanf("%d", &data);
            cll = del(cll, data);
        } else if (ch == '/') {
            trans(cll);
        }
        n--;
    }

    return 0;
}

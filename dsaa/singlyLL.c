#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node* ins(struct node *start, int data, int val) {
    struct node *a = start;
    struct node *b = (struct node*)malloc(sizeof(struct node));
    while (a != NULL && a->info != data) {
        a = a->next;
    }
    if (a == NULL) {
        printf("Data not found\n");
        return start;
    }
    b->next = a->next;
    b->info = val;
    a->next = b;
    return start;
}

struct node* insbeg(struct node *start, int val) {
    struct node *b = (struct node*)malloc(sizeof(struct node));
    b->next = start;
    b->info = val;
    return b;
}

struct node* del(struct node *start, int data) {
    struct node *a = start;
    struct node *b = start->next;
    if (start->info == data) {
        printf("%d is deleted\n", start->info);
        free(start);
        return b;
    }
    while (b != NULL && b->info != data) {
        a = a->next;
        b = b->next;
    }
    if (b == NULL) {
        printf("Data not found\n");
        return start;
    }
    printf("%d is deleted\n", b->info);
    a->next = b->next;
    free(b);
    return start;
}

void tra(struct node *start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *curr = start;
    while (curr != NULL) {
        printf("%d ", curr->info);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct node *ll = NULL;
    printf("Today's code is on singly linked list\n");
    printf("Press '@' to insert a node\n");
    printf("Press '#' to insert a node at the beginning\n");
    printf("Press '$' to delete a node\n");
    printf("Press '&' to traverse the node\n");

    int g = 8;
    char ch;
    int value, data;
    while (g > 0) {
        printf("Enter symbol: ");
        scanf(" %c", &ch);
        switch (ch) {
            case '@':
                printf("Enter data after which you want to insert: ");
                scanf("%d", &data);
                printf("Enter data you want to insert: ");
                scanf("%d", &value);
                ll = ins(ll, data, value);
                break;
            case '#':
                printf("Enter data you want to insert: ");
                scanf("%d", &value);
                ll = insbeg(ll, value);
                break;
            case '$':
                printf("Enter data you want to delete: ");
                scanf("%d", &data);
                ll = del(ll, data);
                break;
            case '&':
                tra(ll);
                break;
        }
        g--;
    }

    return 0;
}

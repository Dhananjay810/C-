#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *prev;
};

struct node *ins(struct node *dll, int val, int data) {
    struct node *b = malloc(sizeof(struct node));
    struct node *a = dll;
    while (a->info != data) {
        a = a->next;
    }
    b->info = val;
    b->next = a->next;
    b->prev = a;
    if (a->next != NULL) {
        a->next->prev = b;
    }
    a->next = b;
    return dll;
}

struct node *begins(struct node *dll, int val) {
    struct node *b = malloc(sizeof(struct node));
    b->info = val;
    b->next = dll;
    b->prev = NULL;
    if (dll != NULL) {
        dll->prev = b;
    }
    return b;
}

struct node *del(struct node *dll, int data) {
    struct node *a = dll;
    if (dll->info == data) {
        printf("%d is deleted\n", dll->info);
        dll = dll->next;
        if (dll != NULL) {
            dll->prev = NULL;
        }
        free(a);
    } else {
        while (a->info != data) {
            a = a->next;
        }
        printf("%d is deleted\n", a->info);
        a->prev->next = a->next;
        if (a->next != NULL) {
            a->next->prev = a->prev;
        }
        free(a);
    }
    return dll;
}

struct node *trans(struct node *dll) {
    struct node *a = dll;
    while (a != NULL) {
        printf("%d ", a->info);
        a = a->next;
    }
    printf("\n");
    return dll;
}

int main() {
    struct node *dll = NULL;
    printf("Press '1' to insert a node at the beginning\n");
    printf("Press '2' to insert a node after data\n");
    printf("Press '3' to delete\n");
    printf("Press '4' to print info\n");

    int f = 500;
    while (f > 0) {
        int t;
        printf("Enter the digit corresponding to the instruction you want to perform: ");
        scanf("%d", &t);
        if (t == 1) {
            int n;
            printf("Enter data you want to store: ");
            scanf("%d", &n);
            dll = begins(dll, n);
        } else if (t == 2) {
            int n;
            printf("Enter data you want to store: ");
            scanf("%d", &n);
            int g;
            printf("Enter info after which you want to store: ");
            scanf("%d", &g);
            dll = ins(dll, n, g);
        } else if (t == 3) {
            int g;
            printf("Enter data you want to delete: ");
            scanf("%d", &g);
            dll = del(dll, g);
        } else if (t == 4) {
            dll = trans(dll);
        }
        f--;
    }
    return 0;
}

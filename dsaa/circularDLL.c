#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *prev;
};

struct node *begin(struct node *cdll, int val) {
    struct node *b = malloc(sizeof(struct node));
    if (cdll == NULL) {
        b->info = val;
        cdll = b;
        b->next = b;
        b->prev = NULL;
    } else {
        struct node *a = cdll;
        struct node *c = cdll;
        while (a->next != c) a = a->next;
        b->info = val;
        b->next = cdll;
        b->prev = NULL;
        cdll->prev = b;
        cdll = b;
        a->next = b;
    }
    return cdll;
}

struct node *ins(struct node *cdll, int data, int val) {
    struct node *a = cdll;
    struct node *b = malloc(sizeof(struct node));
    while (a->info != data) a = a->next;
    b->info = val;
    b->next = a->next;
    b->prev = a;
    a->next = b;
    return cdll;
}

struct node *del(struct node *cdll, int data) {
    struct node *a = cdll;
    struct node *c = cdll;
    if (a->info == data) {
        struct node *b = cdll;
        while (b->next != c) b = b->next;
        printf("%d is deleted\n", a->info);
        b->next = a->next;
        a->next->prev = NULL;
        free(a);
        cdll = b->next;
    } else {
        struct node *b = cdll;
        while (b->next->info != data) b = b->next;
        printf("%d is deleted\n", b->next->info);
        struct node *temp = b->next;
        b->next = b->next->next;
        b->next->prev = b;
        free(temp);
    }
    return cdll;
}

struct node *trav(struct node *cdll) {
    struct node *a = cdll;
    struct node *c = cdll;
    do {
        printf("%d ", a->info);
        a = a->next;
    } while (a != c);
    printf("\n");
    return cdll;
}

int main() {
    struct node *cdll = NULL;
    printf("Enter '~' to insert at the beginning\n");
    printf("Enter '@' to insert\n");
    printf("Enter '#' to delete\n");
    printf("Enter '$' to traverse\n");

    char ch;
    int t = 4000;
    while (t > 0) {
        printf("Enter input: ");
        scanf(" %c", &ch);
        if (ch == '~') {
            int n;
            printf("Enter value: ");
            scanf("%d", &n);
            cdll = begin(cdll, n);
        }
        if (ch == '@') {
            int n;
            printf("Enter value: ");
            scanf("%d", &n);
            int m;
            printf("Enter data: ");
            scanf("%d", &m);
            cdll = ins(cdll, m, n);
        }
        if (ch == '#') {
            int n;
            printf("Enter data: ");
            scanf("%d", &n);
            cdll = del(cdll, n);
        }
        if (ch == '$') {
            cdll = trav(cdll);
        }
        t--;
    }
    return 0;
}

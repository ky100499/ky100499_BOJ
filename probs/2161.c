#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int length;
    struct node *next;
} List;

typedef struct node {
    int value;
    struct node *prev, *next;
} Node;

void push(List *root, int v);
int popleft(List *root);
void rotate(List *root, int step, int reverse);
void freeList(List *root);

int main(int argc, char *argv[])
{
    int N;
    scanf("%d", &N);

    List *root = (List*) malloc(sizeof(List));
    for (int i = 0; i < N; i++) {
        push(root, i+1);
    }

    while (root->length) {
        printf("%d ", popleft(root));
        rotate(root, 1, 0);
    }

    freeList(root);

    return 0;
}

void push(List *root, int v)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = v;

    if (root->length == 0) {
        root->next = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        newNode->next = root->next;
        newNode->prev = root->next->prev;
        root->next->prev->next = newNode;
        root->next->prev = newNode;
    }
    root->length++;
}

int popleft(List *root)
{
    if (root->length == 0) return -1;

    Node *tmp = root->next;
    int ret = tmp->value;

    root->next = tmp->next;
    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;
    root->length--;

    free(tmp);

    if (root->length == 0) root->next = NULL;

    return ret;
}

void rotate(List *root, int step, int reverse)
{
    if (root->length == 0) return;

    Node *tmp = root->next;

    if (step < 0) {
        reverse = !reverse;
        step *= -1;
    }

    while (step--) {
        if (reverse)
            tmp = tmp->prev;
        else
            tmp = tmp->next;
    }

    root->next = tmp;
}

void freeList(List *root)
{
    while (root->length) popleft(root);
    free(root);
}

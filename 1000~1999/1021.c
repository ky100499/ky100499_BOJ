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
int find(List *root, int v);
void freeList(List *root);

int main(int argc, char *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);

    List *root = (List*) malloc(sizeof(List));
    for (int i = 0; i < N; i++) {
        push(root, i+1);
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        int out;
        scanf("%d", &out);

        int idx = find(root, out);
        if (idx > root->length / 2) {
            cnt += root->length - idx;
            rotate(root, root->length - idx, 1);
        }
        else {
            cnt += idx;
            rotate(root, idx, 0);
        }

        popleft(root);
    }
    printf("%d\n", cnt);

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

int find(List *root, int v)
{
    int pos = 0;
    Node *tmp = root->next;
    while (pos < root->length) {
        if (tmp->value == v) return pos;
        tmp = tmp->next;
        pos++;
    }
    return -1;
}

void freeList(List *root)
{
    while (root->length) popleft(root);
    free(root);
}

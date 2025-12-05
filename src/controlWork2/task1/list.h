#pragma once

typedef struct elem {
    int value;
    struct elem* next;
    struct elem* prev;
} elem_t;

typedef struct List {
    elem_t* head;
    int len;
} List;

List* listInit(void);
void listFree(List*);
void listPushHead(List*, int);

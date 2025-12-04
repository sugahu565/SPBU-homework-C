typedef struct Elem {
    int* p;
    struct Elem* prev;
} elem_t;

typedef struct {
    int len;
    elem_t* last;
} stack;

void init(stack* s);
int get(stack* s);
void push(stack* s, int x);
int pop(stack* s);
void destroy(stack* s);

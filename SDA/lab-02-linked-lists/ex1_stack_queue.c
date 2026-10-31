#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

/* --- STACK (LIFO) --- */
struct Node* stack_top = NULL;

int is_empty_stack() {
    return stack_top == NULL;
}

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = x;
    newNode->next = stack_top;
    stack_top = newNode;
}

int pop() {
    if (is_empty_stack()) {
        return -1;
    }
    struct Node* temp = stack_top;
    int val = temp->val;
    stack_top = stack_top->next;
    free(temp);
    return val;
}

int peek() {
    if (is_empty_stack()) {
        return -1;
    }
    return stack_top->val;
}

/* --- QUEUE (FIFO) --- */
struct Node* queue_front = NULL;
struct Node* queue_rear = NULL;

int is_empty_queue() {
    return queue_front == NULL;
}

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = x;
    newNode->next = NULL;
    if (queue_rear == NULL) {
        queue_front = newNode;
        queue_rear = newNode;
    } else {
        queue_rear->next = newNode;
        queue_rear = newNode;
    }
}

int dequeue() {
    if (is_empty_queue()) {
        return -1;
    }
    struct Node* temp = queue_front;
    int val = temp->val;
    queue_front = queue_front->next;
    if (queue_front == NULL) {
        queue_rear = NULL;
    }
    free(temp);
    return val;
}

int front() {
    if (is_empty_queue()) {
        return -1;
    }
    return queue_front->val;
}

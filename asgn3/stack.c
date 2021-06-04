#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Function to Create Stack
Stack *stack_create(int sizedisks, char name) { 
  // Malloc's enough space in the heap for:
  // - char name
  // - int top
  // - int capacity
  // - int *items
  Stack *s = (struct Stack *)malloc(sizeof(Stack));

  //Check if Stack s is created, if not return NULL
  if (!s) {
    return NULL;
  }

  // In order to malloc in items, minimum disks must be 1 or greater
  if (sizedisks < 1) {
    sizedisks = 1;
  }

  s->capacity = sizedisks;  // Assign capacity to sizedisks parameter
  s->top = 0;               // Initialize stack top = 0
  s->name = name;           // Assign name to name parameter

  // Malloc memory in the heap for disks
  s->items = (int *)malloc(sizeof(int) * sizedisks);

  // Check if malloc worked
  if (!s->items) {
    return 0;
  }

  return s; // Return created stack

}

void stack_delete(Stack *s) {
  free(s->items); // Free heap memory used for items
  free(s);        // Free heap memory used for struct Stack
}

int stack_pop(Stack *s) { //Removes the element at the top of the stack
  // Check if Stack is empty, if yes: return -1
  if (!s) {
    return -1;
  }

  if (s->top > 0) {
    s->top -= 1;              // Decrement top to point at first disk
    return s->items[s->top];  // Return top disk on stack
  } else {
    printf("invalid\n");
    return -1;
  }
}

void stack_push(Stack *s, int item) {
  if (!s) {
    return;
  }

  if (s->top == s->capacity) { // Checks if stack is full
    s->capacity *=2;           // Multiplies capacity by 2 for realloc()
    // Creates new space in heap for more disks
    s->items = (int *)realloc(s->items, s->capacity * sizeof(int));
  }

  if (s->items) {
    s->items[s->top] = item;  // Pushes item parameter to stack
    s->top += 1;
  }
  return;
}

bool stack_empty(Stack *s) {  // Returns boolean value true if stack is empty
  return s->top == 0;
}

int stack_peek(Stack *s) {    // Returns item (disk) at the top of the stack
  s->top -= 1;
  return s->items[s->top];
}


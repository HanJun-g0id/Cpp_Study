#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    int Item;
    struct node* Next;
} node;

typedef node* Nptr;

void Init(Nptr* Top);
bool IsEmpty(Nptr Top);
void Push(Nptr* Top, int Item);
int Pop(Nptr* Top);
void FreeList(Nptr* Top);
char Peek(Nptr Top);
void PrintStack(Nptr Top);
//new
void InfixToPostfix(const char* expr);

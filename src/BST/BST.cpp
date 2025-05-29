#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

void Visit(char* name) {
    printf("%s\n", name);
}

Nptr Insert(Nptr T, int Key, const char* name) {
    if (T == NULL) {
        T = (Nptr)malloc(sizeof(NODE));
        T->Data = Key;
        T->Name = strdup(name);
        T->LChild = T->RChild = NULL;
    }
    else if (T->Data > Key)
        T->LChild = Insert(T->LChild, Key, name);
    else
        T->RChild = Insert(T->RChild, Key, name);
    return T;
}

Nptr Create(int S[]) {
    Nptr Root = NULL;
    char buf[20];
    for(int i=0; i<10; i++) {
        sprintf(buf, "%d", S[i]);
        Root = Insert(Root, S[i], buf);
    }
    return Root;
}

void Destroy(Nptr &T) {
    if (T != NULL) {
        Destroy(T->LChild);
        Destroy(T->RChild);
        free(T->Name);
        free(T);
        T = NULL;
    }
}

void PreOrder(Nptr T) {
    if (T != NULL) {
        Visit(T->Name);
        PreOrder(T->LChild);
        PreOrder(T->RChild);
    }
}

void InOrder(Nptr T) {
    if (T != NULL) {
        InOrder(T->LChild);
        Visit(T->Name);
        InOrder(T->RChild);
    }
}

void PostOrder(Nptr T) {
    if (T != NULL) {
        PostOrder(T->LChild);
        PostOrder(T->RChild);
        Visit(T->Name);
    }
}

void Delete(Nptr &T, int Key) {
    if (T == NULL) {
        printf("No Record with Such Key\n");
        return;
    }
    if (T->Data > Key)
        Delete(T->LChild, Key);
    else if (T->Data < Key)
        Delete(T->RChild, Key);
    else {
        if (T->LChild == NULL) {
            Nptr Temp = T;
            T = T->RChild;
            free(Temp->Name);
            free(Temp);
        } else if (T->RChild == NULL) {
            Nptr Temp = T;
            T = T->LChild;
            free(Temp->Name);
            free(Temp);
        } else {
            Nptr Temp = T->RChild;
            while (Temp->LChild != NULL) Temp = Temp->LChild;
            T->Data = Temp->Data;
            free(T->Name);
            T->Name = strdup(Temp->Name);
            Delete(T->RChild, Temp->Data);
        }
    }
}

Nptr Search(Nptr T, int key) {
    if (T == NULL || T->Data == key)
        return T;
    if (T->Data > key)
        return Search(T->LChild, key);
    else
        return Search(T->RChild, key);
}

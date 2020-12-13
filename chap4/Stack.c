//
// Created by Administrator on 2020/12/13.
//
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack CreateStack() {
    Stack S = (Stack) malloc(sizeof(struct SNode));
    S->Data = NULL;
    S->Next = NULL;
    return S;
}

bool IsEmptyS(Stack S) {
    return S->Next == NULL;
}

bool Push(Stack S, BT B) {
    Stack pNode = (Stack) malloc(sizeof(struct SNode));
    pNode->Data = B;
    pNode->Next = NULL;

    pNode->Next = S->Next;
    S->Next = pNode;

    return true;
}

BT Pop(Stack S) {
    if (S->Next == NULL) {
        return NULL;
    }
    Stack next = S->Next;
    BT data = next->Data;

    S->Next = next->Next;
    next->Next = NULL;
    free(next);
    return data;

}
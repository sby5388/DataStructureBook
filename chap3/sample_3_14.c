//
// Created by Administrator on 2020/12/11.
//
//P75
//一个数组实现2个堆栈

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int Position;
typedef int ElementType;
struct SNode {
    ElementType *Data;
    /*堆栈1的头指针*/
    Position Top1;
    /*堆栈2的头指针*/
    Position Top2;
    /*最大容量*/
    int MaxSize;
};

typedef struct SNode *PtrToSNode;
typedef PtrToSNode Stack;


typedef enum {
    false, true
} bool;


Stack CreateStack(int MaxSize);

bool Push(Stack S, int Tag, ElementType X);

bool IsFull(Stack S);

ElementType Pop(Stack S, int Tag);


Stack CreateStack(int MaxSize) {
    Stack S = (Stack) malloc(sizeof(struct SNode));
    S->Data = (ElementType *) malloc(sizeof(ElementType) * MaxSize);
    S->Top1 = -1;
    S->Top2 = MaxSize;
    S->MaxSize = MaxSize;
    return S;
}


bool Push(Stack S, int Tag, ElementType X) {
    if (IsFull(S) == true) {
        printf("Error ! Stack is Full!");
        return false;
    }
    if (Tag == 1) {
        S->Top1++;
        S->Data[S->Top1] = X;
    } else {
        S->Top2--;
        S->Data[S->Top2] = X;
    }


    return true;
}

ElementType Pop(Stack S, int Tag) {
    if (Tag == 1) {
        if (S->Top1 == -1) {
            printf("Stack Tag 1 is Empty");
            return ERROR;
        }
        ElementType data = S->Data[S->Top1];
        S->Top1--;
        return data;
    } else {
        if (S->Top2 == S->MaxSize) {
            printf("Stack Tag 2 is Empty");
            return ERROR;
        } else {
            ElementType data = S->Data[S->Top2];
            S->Top2++;
            return data;
        }
    }
}


bool IsFull(Stack S) {
    if (S->Top2 - S->Top1 <= 1) {
        return true;
    } else {
        return false;
    }
}




//
// Created by Administrator on 2020/12/11.
//
//P73
//使用数组来实现堆栈

#include <stdlib.h>
#include <stdio.h>

#define ERROR -1

typedef int Position;
typedef int ElementType;
struct SNode {
    /*存储数据的元素*/
    ElementType *Data;
    /*栈顶指针*/
    Position Top;
    /*堆栈的最大容量*/
    int MaxSize;
};
typedef struct SNode *PtrToSNode;
typedef PtrToSNode Stack;

typedef enum {
    false, true
} bool;


Stack CreateStack(int MaxSize);

bool IsFull(Stack S);

bool IsEmpty(Stack S);

bool Push(Stack S, ElementType X);

ElementType Pop(Stack S);


Stack CreateStack(int MaxSize) {
    Stack S = (Stack) malloc(sizeof(struct SNode));
    S->Data = (ElementType *) malloc(sizeof(ElementType) * MaxSize);
    S->MaxSize = MaxSize;
    //负1时为空
    S->Top = -1;
    return S;

}

bool IsFull(Stack S) {
    if (S->Top == S->MaxSize - 1) {
        return true;
    }
    return false;
}

bool Push(Stack S, ElementType X) {
    if (IsFull(S)) {
        printf("Error ! Stack is FUll\n");
        return false;
    }
    S->Top++;
    S->Data[S->Top] = X;
    return true;
}

bool IsEmpty(Stack S) {
    if (S->Top == -1) {
        return true;
    } else {
        return false;
    }
}

ElementType Pop(Stack S) {
    if (S->Top == -1) {
        printf("Error ! Stack is Empty!\n");
        return ERROR;
    }
    ElementType Data = S->Data[S->Top];
    S->Top--;
    return Data;
}


//
// Created by Administrator on 2020/12/11.
//
//P77
//3.15 堆栈的链式存储实现

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct SNode *PtrToNode;
typedef PtrToNode Stack;

struct SNode {
    ElementType Data;
    Stack Next;
};

typedef enum {
    false, true
} bool;

/*
 * 创建堆栈的头结点
 */
Stack CreateStack();

/**
 *
 * 空栈
 */
bool IsEmpty(Stack S);

/**
 * 把元素X放进去S,返回成功与否
 * @param S
 * @param X
 * @return
 */
bool Push(Stack S, ElementType X);

/**
 * 栈顶取值
 * @param S
 * @return
 */
ElementType Pop(Stack S);

Stack CreateStack() {
    Stack S = (Stack) malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty(Stack S) {
    if (S->Next == NULL) {
        return true;
    } else {
        return false;
    }
}

bool Push(Stack S, ElementType X) {
    Stack pNode = (Stack) malloc(sizeof(struct SNode));
    pNode->Next = NULL;
    pNode->Data = X;

    pNode->Next = S->Next;
    S->Next = pNode;

    return true;
}

ElementType Pop(Stack S) {
    Stack next = S->Next;
    if (next == NULL) {
        return ERROR;
    }
    ElementType data = next->Data;
    S->Next = next->Next;
    next->Next = NULL;
    free(next);
    return data;
}

//
// Created by Administrator on 2020/12/13.
//
#include "BinTree.h"

#ifndef DATASTRUCTUREBOOK_STACK_H
#define DATASTRUCTUREBOOK_STACK_H

typedef BinTree BT;
typedef struct SNode *PtrToSNode;
typedef PtrToSNode Stack;
struct SNode {
    BT Data;
    Stack Next;
};

/*
 * 创建堆栈的头结点
 */
Stack CreateStack();

/**
 *
 * 空栈
 */
bool IsEmptyS(Stack S);

/**
 * 把元素X放进去S,返回成功与否
 * @param S
 * @param B
 * @return
 */
bool Push(Stack S, BT B);

/**
 * 栈顶取值
 * @param S
 * @return
 */
BT Pop(Stack S);


#endif //DATASTRUCTUREBOOK_STACK_H

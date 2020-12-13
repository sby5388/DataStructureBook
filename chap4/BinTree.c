//
// Created by Administrator on 2020/12/13.
//
//P109
//二叉树的链表结构，及其操作
#include <stdlib.h>
#include <stdio.h>
//TODO 这个头文件也定义了一些遍历的枚举
//#include <search.h>
#include "BinTree.h"
#include "Stack.h"
#include "Queue.h"

/*********************************/

bool IsEmpty(BinTree B) {
    return B == NULL;
}


/**
 * 中序遍历
 * @param B
 */
void InorderTraversal(BinTree B) {
    if (B) {
        InorderTraversal(B->Left);
        printf("%d ", B->Data);
        InorderTraversal(B->Right);
    }
}

void PreorderTraversal(BinTree B) {
    if (B) {
        printf("%d ", B->Data);
        PreorderTraversal(B->Left);
        PreorderTraversal(B->Right);
    }
}

void PostorderTraversal(BinTree B) {
    if (B) {
        PostorderTraversal(B->Left);
        PostorderTraversal(B->Right);
        printf("%d ", B->Data);
    }
}

/**
 * todo 非递归的中序遍历
 * @param B
 */
void InorderTraversal2(BinTree BT) {
    BinTree T;
    Stack S = CreateStack();

    T = BT;
    while (T || !IsEmptyS(S)) {
        while (T) {
            /*一直向左并将沿途结点压入栈堆*/
            Push(S, T);
            T = T->Right;
        }

        /*结点弹出堆栈*/
        T = Pop(S);
        /*访问结点*/
        printf("%d ", T->Data);
        /*转向右子树*/
        T = T->Right;
    }

}

void LevelorderTraversal(BinTree BT) {
    Queue Q;
    BinTree T;
    if (!BT) {
        return;
    }

    Q = CreateQueue();
    AddQ(Q, BT);
    while (!IsEmptyQ(Q)) {
        T = DeleteQ(Q);
        printf("%d ", T->Data);
        if (T->Left) {
            AddQ(Q, T->Left);
        }
        if (T->Right) {
            AddQ(Q, T->Right);
        }
    }
}

void PreorderPrintLeaves(BinTree BT) {
    if (BT) {
        if (!BT->Right && !BT->Left) {
            printf("%d ", BT->Data);
        }
        PreorderPrintLeaves(BT->Left);
        PreorderPrintLeaves(BT->Right);
    }
}

int GetHeight(BinTree BT) {
    if (BT) {
        int heightRight = GetHeight(BT->Right);
        int heightLeft = GetHeight(BT->Left);
        int max = heightLeft > heightRight ? heightLeft : heightRight;
        return max + 1;
    }
    //空树的高度为0
    return 0;
}
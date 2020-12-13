//
// Created by Administrator on 2019/5/14.
//
#include <stdio.h>
#include <stdlib.h>
#include "LinearList.h"


int main() {
    return 0;
}

List MakeEmpty() {
    List L;
    L = (List) malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

Position Find(List L, ElementType X) {
    Position i = 0;

    while (i <= L->Last && X != L->Data[i]) {
        i++;
    }
    if (i > L->Last) {
        return ERROR;
    } else {
        return i;
    }
}

bool Insert(List L, ElementType X, int i) {
    //实际插入的位置是 i-1
    Position j;
    if (L->Last == MAXSIZE - 1) {
        //空间已满
        return false;
    }

    if (i < 1 || i > L->Last + 2) {
        //位置非法：越界
        return false;
    }

    for (j = L->Last; j >= i - 1; j--) {
        L->Data[j + 1] = L->Data[j];
    }

    //插入到第i位，实际下标是i-1
    L->Data[i - 1] = X;
    L->Last++;
    return true;

}

bool Delete(List L, int i) {
    //删除第i位，实际下标是i-1
    Position j;

    if (i < 1 || i > L->Last + 1) {
        //非法位置：越界
        return false;
    }
    //向前移动
    for (j = i; j < L->Last; ++j) {
        L->Data[j - 1] = L->Data[j];
    }
    L->Last--;
    return true;

}






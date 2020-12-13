//
// Created by Administrator on 2020/12/13.
//
#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"


Queue CreateQueue() {
    Queue Q = (Queue) malloc(sizeof(struct QNode));
    Q->Front = NULL;
    Q->Rear = NULL;
    Q->MaxSize = 0;
    return Q;
}

void AddQ(Queue Q, BinTree B) {
    if (IsEmptyQ(Q)) {
        Q->Front = B;
        Q->Rear = B;
    } else {
        //TODO 元素之间并没有关联，   除非去修改BinTree的结构
//        Q->Rear

    }
}

bool IsEmptyQ(Queue Q) {
    return Q->Front == NULL;
}
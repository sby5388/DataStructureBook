//
// Created by Administrator on 2020/12/13.
//
#include "BinTree.h"

#ifndef DATASTRUCTUREBOOK_QUEUE_H
#define DATASTRUCTUREBOOK_QUEUE_H


typedef struct QNode *PtrToQNode;
typedef PtrToQNode Queue;

struct QNode {
    BinTree Front;
    BinTree Rear;
    int MaxSize;
};

Queue CreateQueue();

void AddQ(Queue Q, BinTree B);

bool IsEmptyQ(Queue Q);

BinTree DeleteQ(Queue Q);


#endif //DATASTRUCTUREBOOK_QUEUE_H

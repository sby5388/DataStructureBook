//
// Created by Administrator on 2020/12/13.
//
//P87
//队列的链式存储实现,不带头结点的

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;


typedef struct Node *PtrToNode;
typedef PtrToNode Position;
struct Node {
    ElementType Data;
    Position Next;
};


typedef struct QNode *PtrToQNode;
typedef PtrToQNode Queue;
struct QNode {
    Position Front;
    Position Rear;
    //TODO 为何还需要长度
    int MaxSize;
};

typedef enum {
    false, true
} bool;


Queue CreateQueue(int MaxSize);


bool AddQ(Queue Q, ElementType X);

bool IsEmpty(Queue Q);

ElementType DeleteQ(Queue Q);

bool IsEmpty(Queue Q) {
    if (Q->Front == NULL) {
        return true;
    } else {
        return false;
    }
}

ElementType DeleteQ(Queue Q) {
    if (IsEmpty(Q)) {
        printf("Queue is Empty !");
        return ERROR;
    }

    Position front = Q->Front;
    //TODO 需要判断删除一个之后，是否为空，如果为空，需要修改尾指针
    if (Q->Front == Q->Rear) {
        Q->Front = NULL;
        Q->Rear = NULL;
    } else {
        Q->Front = front->Next;
    }


    front->Next = NULL;
    ElementType data = front->Data;

    free(front);
    return data;

}

bool AddQ(Queue Q, ElementType X) {
    Position pNode = (Position) malloc(sizeof(struct Node));
    pNode->Next = NULL;
    pNode->Data = X;
    if (Q->Front == NULL) {
        //empty
        Q->Front = pNode;
        Q->Rear = pNode;
    } else {
        //放到最后
        Q->Rear->Next = pNode;
        Q->Rear = Q->Rear->Next;
    }
    return true;
}

Queue CreateQueue(int MaxSize) {
    Queue Q = (Queue) malloc(sizeof(struct QNode));
    Q->Rear = NULL;
    Q->Front = NULL;
    Q->MaxSize = MaxSize;
    return Q;
}
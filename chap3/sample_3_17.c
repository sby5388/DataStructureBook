//
// Created by Administrator on 2020/12/13.
//
//队列，先进先出，fifo
//P85
//使用数组来实现循环队列,用少一个元素来表示队列是否满了（另一种方式是增加一个变量，记录当前队列元素的长度）
#include <stdlib.h>
#include <stdio.h>

#define ERROR -1

typedef int Position;
typedef int ElementType;
//Rear = Front时，空
//TODO 当 时满
struct QNode {
    ElementType *Data;
    /*头指针*/
    Position Front;
    /*尾指针*/
    Position Rear;
    int MaxSize;

};
typedef struct QNode *PtrToQNode;
typedef PtrToQNode Queue;


typedef enum {
    false, true
} bool;


Queue CreateQueue(int MaxSize);

bool IsFull(Queue Q);

bool AddQ(Queue Q, ElementType X);

bool IsEmpty(Queue Q);

ElementType DeleteQ(Queue Q);


Queue CreateQueue(int MaxSize) {
    Queue Q = (Queue) malloc(sizeof(struct QNode));
    Q->Data = (ElementType *) malloc(sizeof(ElementType) * MaxSize);
    Q->Front = 0;
    Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

//TODO 判断条件
bool IsFull(Queue Q) {
    //Q->Rear + 1) % Q->MaxSize，取余
    if ((Q->Rear + 1) % Q->MaxSize == Q->Front) {
        return true;
    }
    return false;
}

bool AddQ(Queue Q, ElementType X) {
    if (IsFull(Q) == true) {
        printf("Queue is Full!");
        return false;
    } else {
        //++,大于最大长度时，回到0
        Q->Rear = (Q->Rear + 1) % Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}

bool IsEmpty(Queue Q) {
    return Q->Rear == Q->Front;
}

ElementType DeleteQ(Queue Q) {
    if (IsEmpty(Q)) {
        printf("Queue is Empty!");
        return ERROR;
    }
    //第一个元素不存放数据
    //TODO
    Q->Front = (Q->Front + 1) % Q->MaxSize;
    return Q->Data[Q->Front];

}
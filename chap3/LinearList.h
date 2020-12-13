//
// Created by Administrator on 2019/5/14.
//线性表
#define MAXSIZE 10
#define ERROR -1
typedef int Position;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};
typedef PtrToLNode List;

enum boolean {
    false, true
};
typedef enum boolean bool;

/**
 * 初始化一个新的空线性表
 * @return
 */
List MakeEmpty();

/**
 * 根据位置 找元素
 * @param L
 * @param i
 * @return
 */
ElementType FindKth(List L, int i);

/**
 * 根据元素找位置
 * @param L
 * @param X
 * @return
 */
Position Find(List L, ElementType X);

/**
 * 指定位置中插入元素
 * @param L
 * @param X
 * @param i
 * @return
 */
bool Insert(List L, ElementType X, int i);

/**
 * 删除某个位置的元素
 * @param L
 * @param i
 * @return
 */
bool Delete(List L, int i);

/**
 * 线性表的长度
 * @param L
 * @return
 */
int Length(List L);
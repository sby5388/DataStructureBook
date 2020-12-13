//
// Created by Administrator on 2020/12/13.
//

#ifndef DATASTRUCTUREBOOK_BINTREE_H
#define DATASTRUCTUREBOOK_BINTREE_H

typedef int ElementType;

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;

};

typedef enum {
    false, true
} bool;


bool IsEmpty(BinTree B);

/**
 * 二叉树的遍历
 * 主要有 前序，中序，后序，层次 四种
 * @param B
 */
void Traversal(BinTree B);

BinTree CreateBinTree();


/**
 * 中序遍历
 * @param B
 */
void InorderTraversal(BinTree B);

/**
 * 前序遍历
 * @param B
 */
void PreorderTraversal(BinTree B);

/**
 * 后序遍历
 * @param B
 */
void PostorderTraversal(BinTree B);


/**
 * todo 非递归的中序遍历
 * @param B
 */
void InorderTraversal2(BinTree BT);

/**
 * 层次便利
 * @param BT
 */
void LevelorderTraversal(BinTree BT);

/**
 * 前序输出二叉树的所有叶结点（没有左子树也没有右子树）
 * @param BT
 */
void PreorderPrintLeaves(BinTree BT);

/**
 * 树的高度
 * @param BT
 * @return
 */
int GetHeight(BinTree BT);

#endif //DATASTRUCTUREBOOK_BINTREE_H

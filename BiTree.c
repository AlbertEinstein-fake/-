#include<stdio.h>
#include<stdlib.h>

//存储
typedef char ElemType;

typedef struct TreeNode
{
    ElemType data;
    struct TreeNode*lchild;
    struct TreeNode*rchild;
}TreeNode;

typedef TreeNode*BiTree;

//先序遍历
void preOrder(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("%c", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

//中序遍历
void inOrder(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    inOrder(T->lchild);
    printf("%c",T->data);
    inOrder(T->rchild);
}

//后序遍历
void PostOrder(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    printf("%c",T->data);
}

//线索二叉树
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode*lchild;
    struct ThreadNode*rchild;
    int ltag;
    int rtag;  //为零 表示是树 为一表示线索：左边指向前驱 后边指向后继
}ThreadNode;

typedef ThreadNode*ThreadTree;  //声明指针

char str[] = "";
int idx = 0;  //当下标用


//创建树
void createTree(ThreadTree*T)
{
    

}

//层序遍历


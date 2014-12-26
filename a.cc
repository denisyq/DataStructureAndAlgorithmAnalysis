#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
    struct node *parent;
}Node,*pNode;

void insert(Node** root, int key){

    if((*root) == NULL){
        Node* p = (Node*)malloc(sizeof(Node));
        p->left=p->right=p->parent=NULL;
        p->key=key;

        *root=p;
        return;
    }
    else if( (*root)->key > key){
        insert(&(*root)->left,key);
    }
    else if( (*root)->key < key){
        insert( &(*root)->right, key);
    }
    else if ( (*root)->key == key){
        //lazy add
    }
}

int main(void){
    int i;
    cin>>i;
    Node *root=NULL;
    insert(&root,i);
    cout<<root->key<<endl;
    return 0;
}
http://blog.csdn.net/touch_2011/article/details/6831924
http://www.cnblogs.com/huangxincheng/archive/2012/07/21/2602375.html





























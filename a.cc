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
}Node;

Node* makeEmpty(Node* root){
    if(root == NULL) return NULL;
    else{
        makeEmpty(root->left);
        makeEmpty(root->right);
    }
    free(root);
}
void insert(Node** root, int key){
    //insert root, notice root is Node**
    if((*root) == NULL){
        Node* p = (Node*)malloc(sizeof(Node));
        p->left=p->right=p->parent=NULL;
        p->key=key;

        *root=p;
        return;
    }
    else if( key < (*root)->key){
        //if( (*root)->left == NULL) parent = (*root);
        insert(&(*root)->left,key);
    }
    else if( (*root)->key < key){
        insert( &(*root)->right, key);
    }
    else if ( (*root)->key == key){
        //lazy add
    }
}
Node* findParent(Node* root, Node* node){
    Node* parent=NULL;
    if(root == node) return NULL;
    while(root != node){
        parent = root;
        if(node->key > root->key)
            root = root->right;
        else if(node->key < root->key)
            root = root->left;
        else 
            return NULL;
    }
    return parent;
}
Node* find(Node* node, int key){
    if(node == NULL) return NULL;
    if(key > node->key)
        return find(node->right,key);
    else if(key < node->key)
        return find(node->left,key);
    else
        return node;
}
Node* findMin(Node* node){
    if(node == NULL) return node;
    else if(node->left == NULL) return node;
    else
        return findMin(node->left);
}
Node* findMax(Node* node){
    if(node != NULL){
        while(node->right != NULL)
            node = node->right;
    }
    return node;
}
Node* del(Node* root, int key){
    if(root == NULL) return NULL;
    Node* node = find(root,key);
    if(node == NULL) {cout<<"not find"<<endl;return NULL;}
    Node* tmp;
    
    //one or no children
    if(node->left == NULL || node->right == NULL){
        cout<<"one/no child"<<endl;
        tmp = node;
        Node* parent = findParent(root,node);
        if(node->left == NULL){
            cout<<parent<<endl;
            parent->right = node->right;
            node = node->right;
            cout<<"node "<<node<<" node->right "<<node->right<<endl;
        }
        else if(node->right == NULL){
            parent->left = node->left;
            node = node->left;
        }
        free(tmp);
        return node;
    }
    else{//two children
        cout<<"2 child"<<endl;
        tmp = findMin(node->right);
        node->key = tmp->key;//exchange value
        return del(tmp,tmp->key);
    }
}
void inOrder(Node* root){
    if(root != NULL){
        inOrder(root->left);
        cout<<" "<<root<<"-"<<root->key<<endl;
        inOrder(root->right);
    }
}
int main(void){
        Node* root=NULL;
        Node* tmp;
        int i=0;
    while(i++<6){
        int i; cin>>i;
        insert(&root,i);
        inOrder(root);
        cout<<endl;

    }
        tmp = del(root,4);
        if(tmp == NULL) cout<<"del failed" <<endl;
        else //inOrder(node);
            cout<<tmp->key<<endl;
        inOrder(root);
    return 0;
}

//http://blog.csdn.net/touch_2011/article/details/6831924
//http://www.cnblogs.com/huangxincheng/archive/2012/07/21/2602375.html





























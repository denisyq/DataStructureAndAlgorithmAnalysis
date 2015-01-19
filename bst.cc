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

class BST{
    public:
        BST();
        ~BST();
        void inOrder(void);
        void insert(int key);
        Node* find(int key);
        Node* remove(int key);
    private:
        Node* _root;
        Node* _insert(Node* node, int key);
        Node* _find(Node* node, int key);
        Node* _remove(Node* node, int key);
        void _makeEmpty(Node* node);
        void _inOrder(Node* node);

};
BST::BST(){
    _root = NULL;
}
BST::~BST(){
    _makeEmpty(_root);
}
void BST::_inOrder(Node* root){
    if(root != NULL){
        _inOrder(root->left);
        cout<<" "<<root<<"-"<<root->key<<endl;
        _inOrder(root->right);
    }
}
void BST::inOrder(void){
    _inOrder(_root);
}
void BST::_makeEmpty(Node* root){
    if(root == NULL) return;
    else{
        _makeEmpty(root->left);
        _makeEmpty(root->right);
    }
    delete root;
}
void BST::insert(int key){
    _root = _insert(_root,key);
}
Node* BST::_insert(Node* node, int key){
    if(node == NULL){
        node = new Node;
        node->left = node->right = NULL;
        node->key = key;
    }
    else if( key < node->key){
        node->left  = _insert(node->left,key);
    }
    else if( key > node->key){
        node->right = _insert(node->right,key);
    }
    return  node;
}

Node* BST::find(int key){
    return _find(_root,key);
}
Node* BST::_find(Node* node, int key){
    if(node == NULL) return NULL;
    if(key < node->key)
        return _find(node->left,key);
    else if(key > node->key)
        return _find(node->right,key);
    else
        return node;
}
int main(void){
    BST bst;
    int i=-1;
    int a[7]={6,4,7,2,5,1,3};
    //int a[7]={1,2,3,4,5,6,7};
    //int a[7]={7,6,5,4,3,2,1};
    while(i++<6){
        bst.insert(a[i]);
        bst.inOrder();
        cout<<endl;
    }
    Node* tmp = bst.find(4);
    cout<<tmp->key<<endl;


    return 0;
}
/*
Node** findMin(Node** node){
    if(*node == NULL) return node;
    else if((*node)->left == NULL) return node;
    else
        return findMin(&(*node)->left);
}
Node** findMax(Node** node){
    if(*node != NULL){
        while((*node)->right != NULL)
            node = &(*node)->right;
    }
    return node;
}
Node** deleteNode(Node**, Node**);
Node** deleteKey(Node** root, int key){
    if(*root == NULL) return NULL;
    Node** node =  find(root,key);
    if(*node == NULL){
        cout<<"not find"<<endl;
        return NULL;
    }
    return deleteNode(root,node);
}
Node** deleteNode(Node** root, Node** node){
    Node** tmp;
    //cout<<"root "<<*root<<endl;
    //cout<<"delete begins from "<<*node<<" "<<(*node)->key<<endl; 

    //one or no children
    if((*node)->left == NULL || (*node)->right == NULL){
        tmp = node;
        //cout<<"tmp "<<*tmp<<endl;
        free(*tmp);
        Node** parent = &(*node)->parent;
        //cout<<"parent "<<*parent<<endl;
        Node** LR; //node is parent left/right child?

        if(*parent == NULL){//delete root
            if((*node)->left == NULL)
                *root = (*node)->right;
            else if((*node)->right == NULL)
                *root = (*node)->left;
            return root;
        }
        else if((*parent)->left == *node)
            LR = &(*parent)->left;
        else 
            LR = &(*parent)->right;
        //cout<<"LR "<<*LR<<endl;

        if((*node)->left == NULL && (*node)->right == NULL)//no child
            *LR = NULL;
        else if((*node)->left == NULL)//one child
            *LR = (*node)->right;
        else if((*node)->right == NULL)//one child
            *LR = (*node)->left;

        return LR;
    }
    else{//two children
        //if use change tmp/node, has to change their left/right relation
        tmp = findMax(&(*node)->left);//random choose one to avoid un-balance
        //tmp = findMin(&(*node)->right);
        (*node)->key = (*tmp)->key;
        return deleteNode(root,tmp);
    }
}

int main(void){
    Node* root=NULL;
    Node** tmp;
    int i=-1;
    int a[7]={6,4,7,2,5,1,3};
    //int a[7]={1,2,3,4,5,6,7};
    //int a[7]={7,6,5,4,3,2,1};
    while(i++<6){
        insert(&root,NULL,a[i]);
        inOrder(root);
        cout<<endl;
    }

    int j;
    cout<<"delete one number"<<endl;
    cin>>j;
    tmp = deleteKey(&root,j);
    if(*tmp != NULL)
        cout<<(*tmp)->key<<endl;
    inOrder(root);

    return 0;
}
*/





























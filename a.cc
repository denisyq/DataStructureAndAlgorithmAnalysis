#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct node{
    struct node* left;
    struct node* right;
    int data;
}Node;

class Splay{
public:
    Node* insert(int element);
    Node* remove(int element);
    Node* find(int element);
private:
    Node* root;
    Node* _insert(Node* root, int element);
    Node* _remove(Node* root, int element);
    Node* _find(Node* root, int element);
    Node* _singleToRight(Node* T);
    Node* _singleToLeft(Node* T);
    Node* _splay(Node* T);
    Node* _makeEmpty(Node* root);
};

Splay::Splay(){
    root = NULL;
}
Splay::~Splay(){
    _makeEmpty(root);
}

Node* Splay::insert(int element){
    return _insert(root,element);
}
Node* Splay::remove(int element){
    return _remove(root,element);
}
Node* Splay::find(int element){
    return _find(root,element);
}

Node* Splay::_singleToRight(Node* T){
    Node* p,q,k;
    p = T;
    q = T->left;
    k = q->right;

    p->left = k;
    q->right = p;
    T = q;
    return T;
}
Node* Splay::_singleToLeft(Node* T){
    Node* p,q,k;
    p = T;
    q = T->right;
    k = q->left;

    p->right = k;
    q->left = p;
    T = q;
    return T;
}

Node* Splay::_insert(Node* T, int element){
    Node* node = new Node;
    node->data = element;
    if(T == NULL){
        node->left = node->right = NULL;
        T = node;
    }
    else{
        T = _splay(T,element);
        if(element > T->data){
            
        }
    }
}

int main(){
    A *a=new B(2);  
    system("pause");  
    return 0;  
}  



























#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <queue>
#include <memory.h>
using namespace std;

const int RED = 1;
const int BLACK = 2;

typedef struct node{
    int key;
    int color;
    struct node *left;
    struct node *right;
    struct node *parent;
}Node;

class RBTree{
    public:
        RBTree();
        ~RBTree();
        void inOrder(void);
        void insert(int key);
        Node* find(int key);
        Node* remove(int key);
    private:
        Node* _root;
        void _insert(Node* node, Node* parent, int key);
        Node* _find(Node* node, int key);
        Node* _remove(Node* node, int key);
        void _makeEmpty(Node* node);
        void _inOrder(Node* node);
		Node* _findMin(Node* node);
		Node* _findMax(Node* node); 
        Node* _rebalance(Node* node);
        Node* _leftRotate(Node* node);
        Node* _rightRotate(Node* node);
};
RBTree::RBTree(){
    _root = NULL;
}
RBTree::~RBTree(){
    _makeEmpty(_root);
}
void RBTree::_inOrder(Node* root){
    if(root != NULL){
        _inOrder(root->left);
        cout<<" "<<root<<"-"<<root->key<<endl;
        _inOrder(root->right);
    }
}
void RBTree::inOrder(void){
    _inOrder(_root);
}
void RBTree::_makeEmpty(Node* root){
    if(root == NULL) return;
    else{
        _makeEmpty(root->left);
        _makeEmpty(root->right);
    }
    delete root;
}
void RBTree::insert(int key){
    _insert(_root,NULL,key);
}
Node* RBTree::_leftRotate(Node* node){
    Node* p = node->right;
    node->right = p->left;
    p->left = node;
    return p;
}
Node* RBTree::_rightRotate(Node* node){
    Node* p = node->left;
    node->left = p->right;
    p->right = node;
    return p;
}
Node* RBTree::_rebalance(Node* node){
    while(node != _root && node->parent->color == RED){
        if(node->parent == node->parent->parent->left){//left branch
            Node* uncle = node->parent->parent->right;
            if(uncle && uncle->color == RED){//double RED-->change parent,uncle,grandpa, grandpa recursive
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }else{//parent RED, uncle BLACK, grandpa BLACK-->change parent/grandpa,rotate
                if(node == node->parent->right)
                    node->parent->parent->left = _leftRotate(node->parent);
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                _rightRotate(node->parent->parent);
            }
        }else{//right branch,similar action
            Node* uncle = node->parent->parent->left;
            if(uncle && uncle->color == RED){
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else{
                if(node == node->parent->left)
                    _rightRotate(node->parent);
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                _leftRotate(node->parent->parent);

            }
        }
    }
    _root->color = BLACK;

}
void RBTree::_insert(Node* node, Node* parent, int key){
    while(node != NULL){
        parent = node;
        if(key<node->key){
            node = node->left;
        }else if(key>node->key){
            node = node->right;
        }else
            break;
    }
    if(node == NULL){
        node = new Node;
        node->left = node->right = NULL;
        node->parent = parent;
        node->color = RED;
        node->key = key;
        if(parent == NULL) _root=node;
        else{
            if(node->key < node->parent->key)
                node->parent->left = node;
            else
                node->parent->right = node;
        }
    }
    _rebalance(node);
}

Node* RBTree::find(int key){
    return _find(_root,key);
}
Node* RBTree::_find(Node* node, int key){
    if(node == NULL) return NULL;
    if(key < node->key)
        return _find(node->left,key);
    else if(key > node->key)
        return _find(node->right,key);
    else
        return node;
}
Node* RBTree::_findMin(Node* node){
    if(node == NULL) return node;
    else if(node->left == NULL) return node;
    else
        return _findMin(node->left);
}
Node* RBTree::_findMax(Node* node){
    if(node != NULL){
        while(node->right != NULL)
            node = node->right;
    }
    return node;
}
Node* RBTree::remove(int key){
	_root = _remove(_root,key);
	return _root;
}
Node* RBTree::_remove(Node* node, int key){
	if(node == NULL) return NULL;
	else if( key < node->key)
		node->left = _remove(node->left,key);
	else if(key > node->key)
		node->right = _remove(node->right,key);
	else{
		if(node->left != NULL && node->right != NULL){
			Node* tmp = _findMin(node->right);
			node->key = tmp->key;
			node->right =  _remove(node->right,node->key);
		}
		else{
			Node* tmp = node;
			if(node->left == NULL)
				node = node->right;
			else
				node = node->left;
			delete tmp;
		}
	}
	return node;
}
int main(void){
	RBTree bst;
    int i=-1;
    int a[7]={6,4,7,2,5,1,3};
    //int a[7]={1,2,3,4,5,6,7};
    //int a[7]={7,6,5,4,3,2,1};
    while(i++<6){
        bst.insert(a[i]);
        bst.inOrder();
        cout<<endl;
    }

    int j;
    cout<<"delete one number"<<endl;
    cin>>j;
    Node* tmp = bst.remove(j);
    if(tmp != NULL)
        cout<<tmp->key<<endl;
    bst.inOrder();

    return 0;
}





























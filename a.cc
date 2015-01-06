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

void inOrder(Node* root){
    if(root != NULL){
        inOrder(root->left);
        cout<<" "<<root<<"-"<<root->key<<endl;
        inOrder(root->right);
    }
}
Node* makeEmpty(Node* root){
    if(root == NULL) return NULL;
    else{
        makeEmpty(root->left);
        makeEmpty(root->right);
    }
    free(root);
}
void insert(Node** root, Node* parent, int key){
    //insert root, notice root is Node**
    if((*root) == NULL){
        Node* p = (Node*)malloc(sizeof(Node));
        p->left=p->right=NULL;
        p->parent = parent;
        p->key=key;

        *root=p;
        return;
    }
    //parent = *root;
    else if( key < (*root)->key){
        //if( (*root)->left == NULL) parent = (*root);
        insert(&(*root)->left,*root,key);
    }
    else if( (*root)->key < key){
        insert( &(*root)->right,*root, key);
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
Node** find(Node** node, int key){
    if(*node == NULL) return NULL;
    if(key > (*node)->key)
        return find(&(*node)->right,key);
    else if(key < (*node)->key)
        return find(&(*node)->left,key);
    else
        return node;
}
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
    cout<<"root "<<*root<<endl;
    cout<<"delete begins from "<<*node<<" "<<(*node)->key<<endl; 
    //one or no children
    if((*node)->left == NULL || (*node)->right == NULL){
        cout<<"one/no child"<<endl;
        tmp = node;
        //Node* parent = findParent(root,node);
        Node** parent = &(*node)->parent;
        cout<<"parent "<<*parent<<endl;
        Node** LR; //node is parent left/right child?
        if(*parent == NULL){
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
        cout<<"LR "<<*LR<<endl;
        if((*node)->left == NULL && (*node)->right == NULL){
            *LR = NULL;
        }
        else if((*node)->left == NULL){
            *LR = (*node)->right;
            //node = node->right;
        //    cout<<"node "<<node<<" node->right "<<node->right<<endl;
        }
        else if((*node)->right == NULL){
            *LR = (*node)->left;
            //node = node->left;
        }
        free(*tmp);
        return LR;
    }
    else{//two children
        cout<<"2 child"<<endl;
        tmp = findMax(&(*node)->left);
        (*node)->key = (*tmp)->key;//exchange value
        cout<<"exchange -- "<<(*tmp)->key<<endl;
        inOrder(*root);
        return deleteNode(root,tmp);
    }
}
/*
Node* del(Node* root, int key){
    if(root == NULL) return NULL;
    Node* node = find(root,key);
    if(node == NULL) {cout<<"not find"<<endl;return NULL;}
    Node* tmp;
    cout<<"delete begins from "<<node<<" "<<node->key<<endl; 
    //one or no children
    if(node->left == NULL || node->right == NULL){
        cout<<"one/no child"<<endl;
        tmp = node;
        Node* parent = findParent(root,node);
        if(node->left == NULL){
            cout<<parent<<endl;
            parent->right = node->right;
            node = node->right;
        //    cout<<"node "<<node<<" node->right "<<node->right<<endl;
        }
        else if(node->right == NULL){
            cout<<parent<<endl;
            parent->left = node->left;
            node = node->left;
        }
        free(tmp);
        return node;
    }
    else{//two children
        cout<<"2 child"<<endl;
        tmp = findMax(node->left);
        node->key = tmp->key;//exchange value
        cout<<"exchange -- "<<tmp->key<<endl;
        inOrder(root);
        return del(tmp,tmp->key);
    }
}
*/


int main(void){
        Node* root=NULL;
        Node** tmp;
        int i=-1;
    //int a[7]={6,4,7,2,5,1,3};
    int a[7]={1,2,3,4,5,6,7};
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
        if(*tmp == NULL) cout<<"del failed" <<endl;
        else //inOrder(node);
            cout<<(*tmp)->key<<endl;
        inOrder(root);
    return 0;
}

//http://blog.csdn.net/touch_2011/article/details/6831924
//http://www.cnblogs.com/huangxincheng/archive/2012/07/21/2602375.html





























#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int data[7][7]={
    {0,0,0,0,0,0,0},
    {0,0,1,2,0,0,0},
    {0,1,0,0,1,2,0},
    {0,2,0,0,4,0,6},
    {0,0,1,4,0,5,5},
    {0,0,2,0,5,0,1},
    {0,0,0,6,5,1,0} };

class Prim{
public:
    Prim(int n, int src):vertex_(n),src_(src){
        visited_.assign(vertex_+1,0);
        path_.assign(vertex_+1,0);
        dist_.assign(vertex_+1,INT_MAX);
    }
    void work(){
        visited_[src_]=true;
        path_[src_]=0;
        dist_[src_]=0;

        int min,next=src_;
        for(int i=1;i<=vertex_;++i){
            for(int j=1;j<=vertex_;++j){
               if(!visited_[j] && data[next][j]!=0 && data[next][j]<dist_[j]){
                   dist_[j]=data[next][j];
                   path_[j]=next;
               }
            }
            min=INT_MAX;
            for(int k=1;k<=vertex_;++k){
                if(!visited_[k] && dist_[k]<min){
                    min = dist_[k];
                    next = k;
                }
            }
            visited_[next]=true;
        }
    }
    void print(void){
        for(int i=1;i<=vertex_;++i){//need find vertex-1 times
           if(path_[i]) cout<<"from "<<path_[i]<<" to "<<i<<endl;
        }
    }
private:
    vector<int> visited_;
    vector<int> path_;
    vector<int> dist_;
    int vertex_;
    int src_;
};
    struct Node{
        int src;
        int dest;
        int dist;
    };
    priority_queue<Node> ip;
    bool operator < (Node node1, Node node2){
        return node1.src>node2.src;
    }
    
int main(void){
    //Prim prim(6,5);
    //prim.work();
    //prim.print();
    Node node1,node2;
    node1.dist=1;node1.src=1;node1.dest=1;
    node2.dist=2;node2.src=2;node2.dest=2;
    ip.push(node1);
    ip.push(node2);

    while(!ip.empty()){
        cout<<ip.top().src<<endl;
        ip.pop();
    }
    return 0;
}





























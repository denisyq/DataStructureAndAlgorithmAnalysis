#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int dataDirection[7][7]={
    {0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,0,0,0,1,1,0},
    {0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
};
typedef struct node{
    int u;
    int v;
    int cost;
}Node;

const int NUM_EDGE=6;
Node edge[NUM_EDGE];

void initData(void){
    edge[0].u=1;edge[0].v=2;edge[0].cost=1;
    edge[1].u=1;edge[1].v=3;edge[1].cost=1;
    edge[2].u=2;edge[2].v=4;edge[2].cost=1;
    edge[3].u=2;edge[3].v=5;edge[3].cost=1;
    edge[4].u=5;edge[4].v=3;edge[4].cost=1;
    edge[5].u=3;edge[5].v=6;edge[5].cost=1;
}
//BellmanFord algorithm aims to edge while dijkstra aims to vertex.
//BellmanFord adjacent matrix form will cause O(V*V*V)
//BellmanFord adjacent list form will cause O(V*E)
class BellmanFord{
public:
    BellmanFord(int n,int src):vertex_(n),src_(src){
        dist_.assign(vertex_+1,999);
        visited_.assign(vertex_+1,0);
        path_.assign(vertex_+1,0);
    }
    bool work(){
        dist_[src_]=0;
        //except the src, has vertex-1 times to loop
        //every time, loop every edge if any, O(V*E)
        for(int i=1;i<=vertex_-1;++i){
            for(int j=0;j<NUM_EDGE;++j){
                if(dist_[edge[j].u]+edge[j].cost < dist_[edge[j].v]){
                    dist_[edge[j].v] = dist_[edge[j].u]+edge[j].cost;
                    path_[edge[j].v] = edge[j].u;
                }
            }
        }
        //check whether negative loop
        bool flag=true;
        for(int i=1;i<=NUM_EDGE;++i){
            if(dist_[edge[i].u]+edge[i].cost < dist_[edge[i].v]){
                flag=false;
                break;
            }
        }
        return flag;
        
    }

    void printPath(int index){
        stack<int> s;
        int i = index;
        s.push(i);
        while(i!=src_){
            s.push(path_[i]);
            i = path_[i];
        }   
        //data ready, print the stack
        while(!s.empty()){
            cout<<"->"<<s.top();
            s.pop();
        }   
        cout<<endl;
    }   
 
private:
    int vertex_;
    int src_;
    vector<int> dist_;
    vector<int> visited_;
    vector<int> path_;
};


int main(void){
    cout<<"------------"<<endl;
    initData();
    BellmanFord bell(6,1);
    bell.work();
    bell.printPath(6);
    return 0;
}


#include <iostream>
#include <vector>
#include <stack>
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

typedef struct node{
    int u;
    int v;
    int cost;
}Node;

class BellmanFord{
public:
    BellmanFord(int n,int src):vertex_(n),src_(src){
        dist_.assign(vertex_,999);
        visited_.assign(vertex_+1,0);
        path_.assign(vertex_+1,0);
    }
    bool work(){
        dist_[src_]=0;
        for(int i=1;i<=vertex_-1;++i){
            for(int j=1;j<=NUM_EDGE;++j){
                if(dist_[edge[j].u]+edge[j].cost < dist_[edge[j].v]){
                    dist_[edge[j].v] = dist_[edge[j].u]+edge[j].cost;
                    path_[edge[j].v] = edge[j].u;
                }
            }
        }
        bool flag=true;
        for(int i=1;i<=NUM_EDGE;++i){
            if(dist_[edge[j].u]+edge[j].cost < dist_[edge[j].v]){
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
        while(path_[i]!=src_){
            s.push(path_[i]);
            i = path_[i];
        }   
        s.push(src_);
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
    cout<<"------BFS"<<endl;
	//BFS bfs;
	//bfs.work(1);
    cout<<"------------"<<endl;
    DFS dfs;
    dfs.dfsCheckLoop2(1);
    cout<<dfs.isLoop()<<endl;
    return 0;
}


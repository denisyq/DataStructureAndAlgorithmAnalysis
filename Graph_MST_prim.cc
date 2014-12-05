#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
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
int main(void){
    Prim prim(6,5);
    prim.work();
    prim.print();
    return 0;
}


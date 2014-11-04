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

int dataDirection[7][7]={
    {0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,0,0,0,1,1,0},
    {0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
};



class BFS{
public:
		BFS():n_(7){
			visited_.assign(n_,0);	//first arg is num, sec is value
		}
		void work(int start){
			if(!visited_[start]){
                //push in queue, set visited[]
                //do move visited_[start]=1 to queue.pop
                //in case duplicate in queue.
				iq_.push(start);
                visited_[start]=true;
            }
			while(iq_.size()!=0){
				int tmp=iq_.front();
				iq_.pop();
				cout<<"print  "<<tmp<<endl;
				for(int i=1;i<n_;++i){
					if(dataDirection[tmp][i]!=0 && !visited_[i]){
						iq_.push(i);
                        visited_[i]=true;//see comments in line_25
                    }
				}
			}
		}
private:
		vector<int> visited_;
		queue<int> iq_;
		int n_;
};

class DFS{
public:
    DFS():n_(7){
        visited_.assign(n_,0); 
    }
    void dfsRecursive(int start){
        //print start here to get positive traverse
        //cout<<"print "<<start<<endl;
        visited_[start]=true;
        //use recursive algo to hide stack operation.
        for(int i=1;i<n_;++i){
            if(dataDirection[start][i]!=0 && !visited_[i])
                work(i);
        }
        //print start here to get reverse traverse
        //while this traverse could be used to topology sort.
        //cout<<"print "<<start<<endl;
    }
    void dfsNoRecursive(int start){
        visited_[start]=true;
        s_.push(start);
        while(!s_.empty()){
            int tmp=s_.top();
            s_.pop();
            //cout<<"print "<<tmp<<endl;
            for(int i=1;i<n_;++i){
                if(dataDirection[tmp][i] != 0 && !visited_[i]){
                    s_.push(i);
                    visited_[i]=true;
                }
            }
        }
    }
private:
    vector<int> visited_;
    stack<int> s_;//store non recursive DFS
    int n_;

};



int main(void){
    cout<<"------BFS"<<endl;
	BFS bfs;
	bfs.work(1);
    return 0;
}


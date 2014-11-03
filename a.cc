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



class BFS{
	public:
		BFS():N_(7){
			visited_.assign(0,N_);	
		}
		void work(int start){
			if(!visited_[start])
				iq_.push(start);
			while(iq_.size()!=0){
				cout<<" while"<<endl;
				int tmp=iq_.front();
				iq_.pop();
				visited_[tmp]=1;
				cout<<"-->"<<tmp;
				for(int i=1;i<N_;++i){
					if(data[tmp][i]!=0 && !visited_[i])
						iq_.push(i);
				}
			}
		}
private:
		vector<int> visited_;
		queue<int> iq_;
		int N_;
};

int main(void){
	BFS bfs;
	bfs.work(1);
    return 0;
}


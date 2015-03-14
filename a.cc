#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <deque>
using namespace std;

typedef struct Meeting{
    int from;
    int end;
    int tag;
    int room;
    friend bool operator < (struct Meeting const &a, struct Meeting const &b) {
        if(a.end != b.end)
            return a.end < b.end;
        else
            return a.from<b.from;
    }
    friend bool operator > (struct Meeting const &a, struct Meeting const &b) {
        if(a.end != b.end)
            return a.end > b.end;
        else
            return a.from>b.from;
    }
}Meeting;

bool bigger(Meeting const& a, Meeting const& b){
    if(a.end != b.end)
        return a.end > b.end;
    else
        return a.from>b.from;
}
bool small(Meeting const& a, Meeting const& b){
    if(a.end != b.end)
        return a.end < b.end;
    else 
        return a.from < b.from;
}
void printMeeting(Meeting meeting){
    cout<<meeting.tag<<" "<<meeting.from<<" "<<meeting.end<<endl;
}

class Solution{
public:
    Solution(int N):num_case(N){};
    void fix(void){
        for(int i=0;i<num_case;i++){
            cout<<"Case #"<<i+1<<endl;
            container.clear();
            for(int k=0;k<=100;k++)
                output[k].clear();
            //queueMeet.clear();
            cin>>num_meeting>>num_room;
            for(int j=1;j<=num_meeting;j++){
                cin>>a>>b>>c>>d;
                meet_.from = a*100+b;
                meet_.end = c*100+d;
                meet_.tag = j;
                container.push_back(meet_);
            }
            sort(container.begin(),container.end(),bigger );
            //cout<<"afer sort, meeting sequence print___"<<endl;
            //for_each(container.begin(),container.end(),printMeeting);


            while(!container.empty()){
                Meeting containerMeet = container.back();
                //cout<<"begin"<<" container.from/end" <<containerMeet.from<<"  "<<containerMeet.end<<endl;
                //cout<<queueMeet.empty()<<endl;
                if(!queueMeet.empty()){//swap one
                    Meeting topMeet = queueMeet.top();
                    if(topMeet.end < containerMeet.from){
                        //cout<<"swap it!!!!!"<<"topMeet.end:"<<topMeet.end<<" container.from"<<containerMeet.from<<endl;
                        containerMeet.room = topMeet.room;
                        save(topMeet.room,topMeet.tag);
                        queueMeet.pop();
                        queueMeet.push(containerMeet);
                    }
                    else if(queueMeet.size() == num_room){
                        //cout<<"drop it!!!"<<endl;
                    }
                    else{
                        //cout<<"push into queue!!"<<"from="<<containerMeet.from<<"end="<<containerMeet.end<<endl;
                        containerMeet.room = queueMeet.size()+1;
                        queueMeet.push(containerMeet);
                    }
                }
                else{//push one
                    //cout<<"push into queue!!"<<"from="<<containerMeet.from<<"end="<<containerMeet.end<<endl;
                    containerMeet.room = queueMeet.size()+1;
                    queueMeet.push(containerMeet);
                }
                container.pop_back();
                /*
                priority_queue< Meeting,vector<Meeting>,greater<Meeting> > copyone(queueMeet);
                while(!copyone.empty()){
                    cout<<"in queue "<<copyone.top().from<<" "<<copyone.top().end<<endl;
                    copyone.pop();
                }
                */
            }
            while(!queueMeet.empty()){
                Meeting topMeet = queueMeet.top();
                save(topMeet.room,topMeet.tag);
                queueMeet.pop();
            }
            //print output
            for(int i=1;i<=100;i++){
                if(!output[i].empty()){
                    string s = output[i];
                    s.erase(s.end()-1);
                    cout<<s<<endl;
                }
                else break;
            }

        }
    }


    void fix_2(void){
        for(int i=0;i<num_case;i++){
            cout<<"Case #"<<i+1<<endl;
            container.clear();
            for(int k=0;k<=100;k++)
                output[k].clear();
            //queueMeet.clear();
            cin>>num_meeting>>num_room;
            for(int j=1;j<=num_meeting;j++){
                cin>>a>>b>>c>>d;
                meet_.from = a*100+b;
                meet_.end = c*100+d;
                meet_.tag = j;
                container.push_back(meet_);
            }
            sort(container.begin(),container.end(),bigger );
            //cout<<"afer sort, meeting sequence print___"<<endl;
            //for_each(container.begin(),container.end(),printMeeting);

            int last_end=9999;

            int room=1;
        again:
            if(room>num_room) goto end;
            while(!container.empty()){

                //memset((void*)tmp,0,sizeof(Meeting));
                Meeting containerMeet = container.back();
                //cout<<"begin"<<" container.from/end" <<containerMeet.from<<"  "<<containerMeet.end<<endl;
                //cout<<queueMeet.empty()<<endl;
                if(last_end == 9999){
                    last_end = containerMeet.end;
                    save_2(room,containerMeet.tag);
                    container.pop_back();
                }else{
                    if(last_end < containerMeet.from){
                        last_end = containerMeet.end;
                        save_2(room,containerMeet.tag);
                        container.pop_back();
                    }else{
                        copyContainer.push_front(containerMeet);
                        container.pop_back();
                    }
                }

            }

            output_2.erase(output_2.end()-1);
            //cout<<"print one line"<<endl;
            cout<<output_2<<endl;
            output_2.clear();
            if(!copyContainer.empty()){
                //for_each(copyContainer.begin(),copyContainer.end(),printMeeting);
                vector<Meeting> tmp(copyContainer.begin(),copyContainer.end());
                copyContainer.clear();
                container.swap(tmp);
                room++;
                last_end = 9999;
                //cout<<"goto again"<<endl;
                goto again;
            }
        end:
            //cout<<"another case"<<endl;
            output_2.clear();
            container.clear();
            copyContainer.clear();

        }
    }
    void fix_3(void){//graph color
        for(int i=0;i<num_case;i++){
            cout<<"Case #"<<i+1<<endl;
            container.clear();
            cin>>num_meeting>>num_room;
            for(int j=1;j<=num_meeting;j++){
                cin>>a>>b>>c>>d;
                meet_.from = a*100+b;
                meet_.end = c*100+d;
                meet_.tag = j;
                container.push_back(meet_);
            }
            sort(container.begin(),container.end(),small );
            for_each(container.begin(),container.end(),printMeeting);
            vector<int> res[num_meeting];
            int final[10000]={0};
            for(int j=0;j<container.size();j++){
                res[j].push_back(j); 
            }
        }
    }
private:
    int num_case;
    int num_room;
    int num_meeting;
    int a,b,c,d;
    int from,end;
    string output_2;
    string output[101];
    vector<Meeting> container;
    deque<Meeting> copyContainer;
    priority_queue< Meeting,vector<Meeting>,greater<Meeting> > queueMeet;
    Meeting meet_;
    //map<int,string> out_map;
    string toString(int i){
        char buf[10000];
        sprintf(buf,"%d",i);
        string s(buf);
        return s;
    }
    void save(int room, int tag){
        string str = toString(tag);
        str += " ";
        output[room] += str;
        //cout<<"___output["<<room<<"] ="<<output[room]<<"##"<<endl;
    }
    void save_2(int room, int tag){
        output_2 += toString(tag);
        output_2 += " ";
    }

};
int main(int argc, char* argv){
    freopen("input","r",stdin);
    int n;
    cin>>n;
    Solution solution(n);
    solution.fix_3();
}
/*
3
5 1
13 20 14 0
3 40 7 20
12 30 13 30
13 50 14 20
22 10 24 0
6 2
13 20 14 0
3 40 7 20
12 30 13 30
7 0 8 30
22 10 24 0
0 0 7 0
4 2
3 0 4 0
3 10 4 0
3 20 4 0
3 50 4 0
*/
























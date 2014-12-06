int visit[nMAX];    
  
/** 到已连通集合的最短距离 */  
int dis[nMAX];  
  
/** 节点v 到已连通集合的距离为dis */  
struct Node{  
    int v;    //路线的终点  
    int dis;  //路线的长度     
};  
  
priority_queue<Node> q;    
bool operator < ( Node node1, Node node2 ){  
    return node1.dis > node2.dis;  
}    
  
int prim()  
{  
    int i, size = 1, sum = 0;  
    visit[0] = 1;  
    Node node;  
    for( i = 1; i < n; i ++ ){  
        dis[i] = map[0][i];  
        node.v = i;  
        node.dis = map[0][i];  
        q.push( node );  
    }  
  
    /** size 表示已加入连通集合的节点数 */  
    while( size < n ){  
        node = q.top();  
        q.pop();  
        if( visit[node.v] == 1 )  
            continue;  
        visit[node.v] = 1;  
        size ++;  
        sum += node.dis;  
  
        /** 更新每个节点到连通集合的最短距离 */  
        for( i = 1; i < n; i ++ ){  
            if( !visit[i] && dis[i] > map[node.v][i] ){  
                dis[i] = map[node.v][i];  
                Node tmp;  
                tmp.v = i;  
                tmp.dis = map[node.v][i];  
                q.push( tmp );  
            }  
        }  
    }  
    return sum;  
}  

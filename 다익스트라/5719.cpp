#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
#define MAXX_N 500

int n,m,st,des,dist[MAXX_N+1],visited[MAXX_N+1];
vector<vector<pair<int,int>>> vt,rvt;
int check[MAXX_N+1][MAXX_N+1];

void dijkstra(){
    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    while(!pq.empty()){
        int cost=-pq.top().first;
        int here=pq.top().second;
        pq.pop();
        if(dist[here]!=-1)
            continue;
        
        dist[here]=cost;
        for(int i=0;i<vt[here].size();i++){
            int there=vt[here][i].first;
            int ncost=cost+vt[here][i].second;
            if(dist[there]==-1)
                pq.push({-ncost,there});
        }
    }
}

void dxt(){
    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    while(!pq.empty()){
        int cost=-pq.top().first;
        int here=pq.top().second;
        pq.pop();
        if(dist[here]!=-1)
            continue;
        dist[here]=cost;
        for(int i=0;i<vt[here].size();i++){
            int there=vt[here][i].first;
            int ncost=cost+vt[here][i].second;
            if(check[here][there]) continue;
            if(dist[there]==-1)
                pq.push({-ncost,there});
        }
    }
}

int main(){
    while(1){
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)
            break;
        vt.clear();
        vt.resize(n+1);
        rvt.clear();
        rvt.resize(n+1);
        
        scanf("%d%d",&st,&des);
        for(int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            vt[x].push_back({y,z});
            rvt[y].push_back({x,z});
        }
        memset(dist,-1,sizeof(dist));
        memset(check,0,sizeof(check));
        memset(visited,0,sizeof(visited));
        dijkstra();
        
        queue<int> qu;
        qu.push(des);
        while(!qu.empty()){
            int here=qu.front();
            qu.pop();
            if(here==st)
                continue;
            for(int i=0;i<rvt[here].size();i++){
                int there=rvt[here][i].first;
                if(dist[here]==dist[there]+rvt[here][i].second){
                    check[there][here]=1;
                    qu.push(there);
                }
            }
        }
        
        
        memset(dist,-1,sizeof(dist));
        dxt();
        printf("%d\n",dist[des]);
        
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                printf("%d ",check[i][j]);
//            }
//            puts("");
//        }
//
        
    }
    
}

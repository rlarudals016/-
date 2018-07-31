#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define MAXX_N 2000

int t,n,m,destinationCnt,st,info1,info2;
vector<vector<pair<int,int>>> vt;
priority_queue<pair<int,int>> pq;

void dijkstra(int stPoint,vector<int>& vec){
    pq.push({0,stPoint});
    while(!pq.empty()){
        int cost=-pq.top().first;
        int here=pq.top().second;
        pq.pop();
        
        if(vec[here]!=-1)
            continue;
        vec[here]=cost;
        for(int i=0;i<vt[here].size();i++){
            int there=vt[here][i].first;
            int ncost=cost+vt[here][i].second;
            if(vec[there]==-1)
                pq.push({-ncost,there});
        }
    }
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d",&n,&m,&destinationCnt,&st,&info1,&info2);
        vt.clear();
        vt.resize(n+1);
        vector<int> candidate,ans;
        vector<int> dist1,dist2,dist3;
        dist1.assign(n+1,-1);
        dist2.assign(n+1,-1);
        dist3.assign(n+1,-1);
        
        for(int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            vt[x].push_back({y,z});
            vt[y].push_back({x,z});
        }
        
        for(int i=0;i<destinationCnt;i++){
            int num;
            scanf("%d",&num);
            candidate.push_back(num);
        }
        dijkstra(st, dist1);
        dijkstra(info1, dist2);
        dijkstra(info2, dist3);
        
        for(int i=0;i<candidate.size();i++){
            int tmp=candidate[i];
            if(dist1[tmp]==(dist2[info2]+dist2[st]+dist3[tmp])||dist1[tmp]==(dist2[tmp]+dist3[info1]+dist3[st]))
                ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end());
        
        for(int i=0;i<ans.size();i++)
            printf("%d ",ans[i]);
        puts("");
        
    }
}

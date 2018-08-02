#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXX_K 100
#define MAXX_N 1000

int n,m,k;
vector<vector<pair<int,int>>> vt;
priority_queue<pair<int,int>> pq;
priority_queue<int> kth_path[MAXX_N+1];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    vt.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        vt[x].push_back({y,z});
    }
    
    pq.push({0,1});
    kth_path[1].push(0);
    while(!pq.empty()){
        int here=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        for(int i=0;i<vt[here].size();i++){
            int there=vt[here][i].first;
            int ncost=cost+vt[here][i].second;
            if(kth_path[there].size()<k){
                kth_path[there].push(ncost);
                pq.push({-ncost,there});
            }
            else if(kth_path[there].top()>ncost){
                kth_path[there].pop();
                kth_path[there].push(ncost);
                pq.push({-ncost,there});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(kth_path[i].size()<k)
            puts("-1");
        else{
            int ans=kth_path[i].top();
            printf("%d\n",ans);
        }
    }
    
}

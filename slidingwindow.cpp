class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        long long x=LLONG_MAX;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back({edges[i][1].edges[i][2]});
        }
        vector<vector<int>>dist(n,vector<int>(p+1,x));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        dist[source][power]=0;
        pq.push({0,{source,power}});
        while(!pq.empty()){
            int t=pq.top().first;
            int node=pq.top().second.first;
            int rp=pq.top().second.second;
            pq.pop();
            if(rp<cost[node]){
                  continue;
                }
                if(t>dist[node][rp]){
                    continue;
                }
                int np=rp-cost[node];
            for(auto it:adj[node]){
                int nt=t+it.second.second;
                if(nt<dist[it.second.first][np]){
                    dist[it.second.first][np]=nt;
                    pq.push({nt,it.second.first,np});
                }

                
                
            }
        }
        int besttime=INT_MAX,bestpow=-1;
        for(int p=0;p<=power;p++){
            if(dist[target][p]<besttime){
                besttime=dist[target][p];
                bestpow=p;
            }else if(dist[target][p]==besttime){
                bestpow=p;
            }
        }
        if(besttime==INT_MAX){
            return {-1,-1};
        }
        return {besttime,bestpow};
    }
};
class Solution {
public:
 int countWalls(vector<int>& walls, int L, int R){
    if (L > R){

    return 0;
    }

    int left = lower_bound(walls.begin(), walls.end(), L) - walls.begin();
    int right = upper_bound(walls.begin(), walls.end(), R) - walls.begin();

    return right - left;
}
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n=robots.size();
        vector<pair<int,int>>mp;
        for(int i=0;i<n;i++){
            mp.push_back({robots[i],distance[i]});
        }
        sort(mp.begin(),mp.end());
        sort(walls.begin(),walls.end());
       

   
vector<vector<int>>dp(n,vector<int>(2,0));
int leftside=mp[0].first-mp[0].second;
dp[0][0]=countWalls(walls,leftside,mp[0].first);
int rightside;
if(n==1){
    rightside=mp[0].first+mp[0].second;
}else{
    rightside=min(mp[0].first+mp[0].second,mp[1].first-1);
}
dp[0][1]=countWalls(walls,mp[0].first,rightside);

for(int i=1;i<n;i++){
    int pos=mp[i].first;
    int dist=mp[i].second;
   
    
   int righty;
if (i == n - 1) {
    righty = pos + dist;
} else {
    righty = min(pos + dist, mp[i + 1].first - 1);
}
    
    int rightwalls=countWalls(walls,pos,righty);
    dp[i][1]=max(dp[i-1][0],dp[i-1][1])+rightwalls;
    int lefty=max(pos-dist,mp[i-1].first+1);
    int leftwalls=countWalls(walls,lefty,pos-1);
    dp[i][0] = dp[i - 1][0] + leftwalls;
    int prev=min(mp[i-1].first+mp[i-1].second,pos-1);
    int countleft=countWalls(walls,prev+1,pos-1);
    dp[i][0]=max(dp[i][0],dp[i-1][1]+countleft);
    
}
return max(dp[n-1][0],dp[n-1][1]);


        
        
    }
};
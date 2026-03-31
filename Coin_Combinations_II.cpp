#include<bits/stdc++.h>
using namespace std; 
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
   vector<int>dp(x+1,0);
   const int MOD=1e9 + 7;
   dp[0]=1;
   for(auto it:c){
    for(int i=it;i<=x;i++){
    if((i-it)>=0){
        dp[i]=(dp[i]+dp[i-it])%MOD;

    }

   }
}
   cout<<dp[x]<<endl;

}

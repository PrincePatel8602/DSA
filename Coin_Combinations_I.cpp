#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    const int MOD=1e9 +7;
    vector<int>dp(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(auto it:c){
            if(i-it>=0){
                dp[i]=(dp[i]+dp[i-it])%MOD;
            }
        }
    }
    cout<<dp[x]<<endl;
}
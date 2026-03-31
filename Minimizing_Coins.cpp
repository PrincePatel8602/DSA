#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= x; i++){
        for(auto it : c){
            if(i - it >= 0 && dp[i - it] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i - it]);
            }
        }
    }

    if(dp[x] == INT_MAX) {
        cout << -1 << endl;
    }else{

    cout << dp[x] << endl;

    }
}

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    long long x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<long long> pre(n);

    long long xp=x;
    pre[0]=x;

    for(int i=1;i<n;i++){
        xp=(a*xp+b)%c;
        pre[i]=pre[i-1]+xp;
    }

    long long ans=pre[k-1];

    for(int i=k;i<n;i++){
        ans^=(pre[i]-pre[i-k]);
    }

    cout<<ans;
}
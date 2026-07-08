#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>events;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        events.push_back({a[i],1});
        events.push_back({b[i],-1});
    }
    sort(events.begin(),events.end());
    
    int ans=INT_MIN;
    int count=0;
    for(auto it:events){
        count+=it.second;
        ans=max(ans,count);

    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    vector<pair<int,int>>p;
    for(int i=0;i<n;i++){
          cin>>a[i];
          p.push_back({a[i],i+1});
    }
    sort(p.begin(),p.end());
    int low=0;
    int high=n-1;
    int l=0;
    int r=0;
    while(low<high){
        if(p[low].first+p[high].first>x){
            high--;
        }else if(p[low].first+p[high].first<x){
            low++;
        }else{
            if(p[low].second>p[high].second){
                l=p[high].second;
                r=p[low].second;
            }else{
                l=p[low].second;
                r=p[high].second;
            }
            break;
        }


    }
    if(l>=1 && l<=n && r>=1 && r<=n){
    cout<<l<<" "<<r<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }

}
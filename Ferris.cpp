#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int i=0;
    int j=n-1;
    int count=0;
    while(i<j){
        if(a[i]+a[j]<=x){
            i++;
            j--;
            count++;
        }else if(a[i]+a[j]>x){
            count++;
            j--;
        }
    }
   if(i==j){
    count++;
   }
 cout<<count<<endl;

}
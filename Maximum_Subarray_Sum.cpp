#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long current_sum = a[0];
    long long max_sum = a[0];

    for(int i = 1; i < n; i++){
        current_sum = max(a[i], current_sum + a[i]);
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;
}
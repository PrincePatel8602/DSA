#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> movies;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        movies.push_back({b, a}); 
    }

    sort(movies.begin(), movies.end());

    int count = 0;
    int lastEnd = 0;

    for(auto movie : movies){
        int end = movie.first;
        int start = movie.second;

        if(start >= lastEnd){
            count++;
            lastEnd = end;
        }
    }

    cout << count;
}
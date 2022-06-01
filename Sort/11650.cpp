//
// Created by 이경민 on 2022/06/01.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,x,y;
vector<pair<int,int>> vec;

bool comp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    else return a.first < b.first;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    while(n--){
        cin>>x>>y;
        vec.push_back({x,y});
    }
    sort(vec.begin(),vec.end(),comp);
    for(auto i:vec){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    return 0;
}

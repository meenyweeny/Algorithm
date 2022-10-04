//
// Created by 이경민 on 2022/06/16.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,x;
vector<int> v,arr;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>x;
        v.push_back(x);
        arr.push_back(x);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(auto i:arr) cout<<lower_bound(v.begin(),v.end(),i)-v.begin()<<" ";
}

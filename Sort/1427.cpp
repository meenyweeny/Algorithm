//
// Created by 이경민 on 2022/06/16.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string cmd;
vector<char> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>cmd;
    for(auto i:cmd) v.push_back(i);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(auto i:v) cout<<i;
}

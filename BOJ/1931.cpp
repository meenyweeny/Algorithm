//
// Created by 이경민 on 2022/09/10.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,s,e,answer;
vector<pair<int,int>> v;

bool comp(pair<int,int> frnt, pair<int,int> back) {
    if(frnt.second==back.second){
        return frnt.first < back.first;
    }
    else if(frnt.second>back.second) return false;
    else return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>s>>e;
        v.push_back({s,e});
    }
    sort(v.begin(),v.end(), comp);
    int end = v[0].second;
    ++answer;
    for(int i=1; i<n; i++){
        if(v[i].first >= end) {
            end = v[i].second;
            ++answer;
        }
    }
    cout<<answer;
}
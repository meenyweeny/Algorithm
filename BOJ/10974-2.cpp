//
// Created by 이경민 on 2022/08/07.
//
#include<iostream>
#include<vector>
using namespace std;

int n;
bool map[8];
vector<int> v;

void permutation() {
    if(v.size()==n) {
        for(auto i : v) cout<<i<<" ";
        cout<<"\n";
    }

    for(int i=0; i<n; i++) {
        if(map[i]) continue;
        map[i]=true;
        v.push_back(i+1);
        permutation();
        v.pop_back();
        map[i]=false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    permutation();
}

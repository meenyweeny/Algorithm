//
// Created by 이경민 on 2022-06-14.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1; i<=n; i++) v.push_back(i);

    do {
        for(auto i:v) cout<<i<<" ";
        cout<<"\n";
    }while(next_permutation(v.begin(),v.end()));
}

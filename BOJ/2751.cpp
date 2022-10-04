//
// Created by 이경민 on 2022/06/01.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int n,x;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    while(n--){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<"\n";
    }
}

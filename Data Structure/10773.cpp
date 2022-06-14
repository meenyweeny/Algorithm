//
// Created by 이경민 on 2022-06-14.
//
#include<iostream>
#include<vector>
using namespace std;

int k,x,sum;
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>k;
    while(k--){
        cin>>x;
        if(x==0) v.pop_back();
        else v.push_back(x);
    }
    for(auto i:v){
        sum+=i;
    }
    cout<<sum;
}

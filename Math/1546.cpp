//
// Created by 이경민 on 2022-06-08.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,x,sum;
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    while(n--){
        cin>>x;
        sum+=x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    cout<<(double)((((double)(sum) * ((((double)100/(double)v[0])))/(double)(v.size()))));
}
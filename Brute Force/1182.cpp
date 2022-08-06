//
// Created by 이경민 on 2022/08/06.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,s,answer;
int arr[20];

void solve(int next_index, int sum, vector<int> v) {
    if(sum==s && !v.empty()) {
        ++answer;
    }

    for(int i=next_index; i<n; i++){
        v.push_back(arr[i]);
        solve(i+1, sum+arr[i],v);
        v.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>s;
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<int> k;

    solve(0,0,k);

    cout<<answer;
}

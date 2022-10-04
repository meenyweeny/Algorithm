//
// Created by 이경민 on 2022-06-14.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[9];
vector<int> ans;
void solve(int index, int sum, int count, vector<int> v) {
    if (sum == 100 && count == 7) ans=v;
    if (sum>100 || count>7) return;
    for(int i=index; i<9; i++){
        v.push_back(arr[i]);
        solve(i+1,sum+arr[i],count+1,v);
        v.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0; i<9; i++) cin>>arr[i];
    vector<int> k;
    solve(0,0,0,k);
    sort(ans.begin(), ans.end());
    for(auto i: ans){
        cout<<i<<"\n";
    }
}

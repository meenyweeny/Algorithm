//
// Created by 이경민 on 2022/08/07.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int n,answer;
int arr[8];
bool visited[8];
vector<int> v;

void solve() {
    if(v.size()==n) {
        int sum=0;
        for(int i=0; i<n-1; i++) {
            sum += abs(v[i]-v[i+1]);
        }
        answer=max(answer,sum);
        return;
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i]=true;
            v.push_back(arr[i]);
            solve();
            visited[i]=false;
            v.pop_back();
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    solve();
    cout<<answer;
}

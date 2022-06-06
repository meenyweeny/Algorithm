//
// Created by 이경민 on 2022/06/06.
//
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
int arr[101];
bool visited[101];
vector<int> answer;

void permutation(int count, int sum){
    if(count==3) {
        if(sum<=m) answer.push_back(sum);
        return;
    }
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        permutation(count+1, sum+arr[i]);
        visited[i] = false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    permutation(0,0);
    sort(answer.begin(), answer.end());
    reverse(answer.begin(), answer.end());
    cout<<answer[0];
}

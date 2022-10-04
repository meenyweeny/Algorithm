//
// Created by 이경민 on 2022-06-20.
//
#include<iostream>
#include<algorithm>
using namespace std;

int n,answer;
int arr[1000];
int dp[1000];
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    dp[0]=1;
    for(int i=1; i<n; i++){
        dp[i]=1;
        for(int k=0; k<i; k++){
            if(arr[i]>arr[k]) dp[i] = max(dp[k]+1,dp[i]);
        }
        answer=max(answer,dp[i]);
    }
    cout<<answer;
}

//
// Created by 이경민 on 2022/09/08.
//
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int price[1001];
int dp[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1; i<=n; i++) cin>>price[i];
    dp[1]=price[1];
    for(int i=2; i<=n; i++) {
        dp[i]= price[i];
        for(int k=i; k>=1; k--){
            dp[i]=max(dp[i],dp[i-k]+dp[k]);
        }
    }
    cout<<dp[n];
}
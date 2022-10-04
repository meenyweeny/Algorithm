//
// Created by 이경민 on 2022-06-15.
//
#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];
int dp[1001];
int n,ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    dp[1] = arr[1];
    ans = arr[1];

    for(int i=2; i<=n; i++){
        dp[i] = arr[i];
        for(int k=1; k<=i; k++){
            if(arr[i]>arr[k]) dp[i] = max(dp[i],dp[k]+arr[i]);
        }
        ans = max(ans, dp[i]);
    }

    cout<<ans;

}

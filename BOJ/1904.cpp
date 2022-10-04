//
//  1904.cpp
//  BOJ
//
//  Created by 이경민 on 2022/02/05.
//

#include<iostream>
using namespace std;
#define mod 15746
#define MAX 1000000 + 1

unsigned long long dp[MAX];
int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    cin>>n;
    for(int i=4; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%mod ;
    }
    cout<<dp[n];
}

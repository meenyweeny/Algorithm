//
//  1463.cpp
//  BOJ
//
//  Created by 이경민 on 2022/03/30.
//

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 1000001

int dp[MAX];
int n;

int main() {
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = dp[3] = 1;

    cin >> n;
    for (int i = 4; i <= n; i++) {

        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0) {
            dp[i] = min(1 + dp[i / 2], dp[i]);
        }
        if (i % 3 == 0) {
            dp[i] = min(1 + dp[i / 3], dp[i]);
        }
    }

    cout << dp[n];

}

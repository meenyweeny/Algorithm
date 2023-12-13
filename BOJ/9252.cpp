#include<iostream>
#include<string>
using namespace std;

const int bucketsize = 1e3 + 1;
string arr[2];
int dp[bucketsize][bucketsize];

void input() {
    for(int k=0; k<2; k++) {
        cin>>arr[k];
    }
}

void solution() {
    arr[0] = "."+arr[0];
    arr[1] = ","+arr[1];
    fill(&dp[0][0], &dp[bucketsize-1][bucketsize], 0);
    for(int i=1; i<arr[1].length(); i++) {
        char now = arr[1][i];
        for(int j=1; j<arr[0].length(); j++) {
            char comp = arr[0][j];
            if(now==comp) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = dp[i-1][j];
                dp[i][j] = max(dp[i][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[arr[1].length()-1][arr[0].length()-1]<<'\n';
    int blen = arr[0].length();
    int alen = arr[1].length();
    string answer = "";
    --alen;
    --blen;
    int now = dp[alen][blen];
    while(1) {
        if(dp[alen][blen]==0) {
            break;
        }
        if(now==dp[alen-1][blen]) {
            --alen;
        } else if(now==dp[alen][blen-1]) {
            --blen;
        } else {
            answer += arr[1][alen];
            --alen;
            --blen;
            now = dp[alen][blen];
        }
    }
    reverse(answer.begin(), answer.end());
    cout<<answer;
}

void solve() {
    input();
    solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}

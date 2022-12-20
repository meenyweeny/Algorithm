//
// Created by 이경민 on 2022/12/20.
//
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int cnt[10];
int answer = -1;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    int mod;
    while(n>0) {
        mod = n%10;
        if(mod==9) {
            ++cnt[6];
        } else {
            ++cnt[mod];
        }
        n/=10;
    }

    cnt[6] = ceil((double)cnt[6]/2);
    for(int i=0; i<9; i++) {
        answer = max(answer, cnt[i]);
    }

    cout << answer;
}

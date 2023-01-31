//
// Created by 이경민 on 2023/01/31.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,k;
int price[10001];
vector<int> coin;

void input() {
    cin>>n>>k;
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        coin.push_back(x);
    }
}

void solution() {
    sort(coin.begin(), coin.end());
    int now;
    price[0] = 1;
    for(int i=0; i<n; i++) {
        now = coin[i];
        for(int j=now; j<=k; j++) {
            price[j] += price[j-now];
        }
    }
    cout<<price[k];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}

//
// Created by 이경민 on 2023/01/05.
//
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100001
int n;
unsigned long long dist[MAX];
unsigned long long price[MAX];
unsigned long long answer;

void input() {
    cin>>n;
    for(int i=0; i<n-1; i++) {
        cin>>dist[i];
    }
    for(int i=0; i<n; i++) {
        cin>>price[i];
    }
}

void solve() {
    unsigned long long mini = price[0];
    unsigned long long road = dist[0];
    for(int i=1; i<n-1; i++) {
        if(mini>price[i]) {
            answer += (road*mini);
            mini = price[i];
            road=dist[i];
        } else {
            road += dist[i];
        }
    }
    answer += (road*mini);
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solve();
}

//
// Created by 이경민 on 2023/01/28.
//
#include<iostream>
using namespace std;

int n,k;
int arr[100001];

void input() {
    cin>>n>>k;
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
    }
}

void solution() {
    int s,e;
    s = 1;
    e = k;

    int sum = 0;
    int answer = -1e9;
    for(int i=1; i<=k; i++) {
        sum += arr[i];
    }

    while(e<=n) {
        answer = max(answer, sum);
        ++e;
        sum += arr[e];
        sum -= arr[s];
        ++s;
    }
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}

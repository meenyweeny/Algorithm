//
// Created by 이경민 on 2023/02/14.
//
#include<iostream>
using namespace std;

int n,k;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    int answer = 1;
    for(int i=n; i>n-k; i--) {
        answer *= i;
    }
    for(int i=1; i<=k; i++) {
        answer /= i;
    }
    cout<<answer;
}

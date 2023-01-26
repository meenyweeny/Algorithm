//
// Created by 이경민 on 2023/01/26.
//
#include<iostream>
using namespace std;

int n,m,answer;
int arr[10001];

void input() {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
    }
}

void solution() {
    int f,b,sum;
    f = b = 1;
    sum = arr[1];

    while(1) {
        if(sum>m) {
            sum -= arr[f];
            ++f;
        } else if(sum==m) {
            ++answer;
            ++b;
            sum+=arr[b];
        } else {
            ++b;
            sum+=arr[b];
        }
        if(b>n) {
            break;
        }
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

#include<iostream>
using namespace std;

int n, ansmin, ansmax;
int arr[11];
int oper[4];

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    for(int i=0; i<4; i++) {
        cin>>oper[i];
    }
}

void solution(int sum, int start) {
    if(start==n) {
        ansmax = max(ansmax,sum);
        ansmin = min(ansmin,sum);
        return;
    }
    for(int i=0; i<4; i++) {
        if(!oper[i]) {
            continue;
        }
        --oper[i];
        int tmp = sum;
        if(i==0) tmp += arr[start];
        else if(i==1) tmp -= arr[start];
        else if(i==2) tmp *= arr[start];
        else tmp /= arr[start];
        solution(tmp,start+1);
        ++oper[i];
    }
}

void solve() {
    input();
    ansmin = 2e9;
    ansmax = -2e9;
    solution(arr[0],1);
    cout<<ansmax<<'\n'<<ansmin;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

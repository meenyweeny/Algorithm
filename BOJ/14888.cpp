#include<iostream>
using namespace std;

int mini,maxi;
int oper[4];
int nums[12];
int n;

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    for(int i=0; i<4; i++) {
        cin>>oper[i];
    }
}

int calc(int a,int b,int op) {
    if(op==0) {
        return a+b;
    } else if(op==1) {
        return a-b;
    } else if(op==2) {
        return a*b;
    } else {
        return a/b;
    }
}

void run(int op[],int count,int sum) {
    if(count==n) {
        maxi = max(maxi,sum);
        mini = min(mini,sum);
        return;
    }

    for(int i=0; i<4; i++) {
        if(op[i]!=0) {
            --op[i];
            run(op,count+1,calc(sum,nums[count],i));
            ++op[i];
        }
    }
}

void solution() {
    mini = 2e9;
    maxi = -2e9;
    run(oper,1,nums[0]);
    cout<<maxi<<'\n'<<mini;
}

void solve() {
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

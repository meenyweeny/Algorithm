#include<iostream>
using namespace std;

int n;

void solve() {
    cin>>n;

    int answer = 0;
    int cycle = -1;

    if(n==0) {
        cout<<1;
        return;
    }

    cycle = n;

    int sum;

    while(1) {
        sum = (cycle/10) + (cycle%10);
        cycle = (cycle%10)*10 + sum%10;
        ++answer;

        if(cycle == n) {
            cout<<answer;
            break;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

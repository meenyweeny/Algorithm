#include<iostream>
using namespace std;

int n;
int price[1001];
int buy[1001];

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>price[i];
    }
}

void solve() {
    input();
    buy[1] = price[1];
    buy[2] = min(buy[1]*2, price[2]);
    for(int i=3; i<=n; i++) {
        int half = i/2;
        buy[i] = price[i];
        for(int h=1; h<=half; h++) {
            buy[i] = min(buy[i], buy[h]+buy[i-h]);
        }
    }
    cout<<buy[n];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
    return 0;
}

#include<iostream>
using namespace std;

const int sz = 1e5 + 1;
int n;
unsigned long long dist[sz];
unsigned long long price[sz];
unsigned long long answer;

void input() {
    cin>>n;
    for(int i=0; i<n-1; i++) {
        cin>>dist[i];
    }
    for(int i=0; i<n; i++) {
        cin >> price[i];
    }
}

void solution() {
    unsigned long long min_price = 2e9;
    unsigned long long distance = 0;

    for(int i=0; i<n-1; i++) {
        if(min_price>price[i]) {
            answer += (min_price * distance);
            min_price = price[i];
            distance = dist[i];
        } else {
            distance += dist[i];
        }
    }
    answer += (min_price * distance);
    cout<<answer;
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

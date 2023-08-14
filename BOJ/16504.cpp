#include<iostream>
using namespace std;

int n;
unsigned long long answer;
int map[1024][1024];

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
            answer+=map[i][j];
        }
    }
}

void solve() {
    input();
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

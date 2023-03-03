#include<iostream>
using namespace std;

bool arr[101][101];
int n;

void solve() {
    cin>>n;
    int x,y;
    while(n--) {
        cin>>x>>y;
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                arr[x+i][y+j] = true;
            }
        }
    }

    int answer = 0;

    for(int i=1; i<=100; i++) {
        for(int j=1; j<=100; j++) {
            answer += arr[i][j];
        }
    }

    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

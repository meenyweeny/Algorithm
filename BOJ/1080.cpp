#include<iostream>
using namespace std;

int n,m;
bool a[51][51];
bool b[51][51];

void input() {
    cin>>n>>m;
    char ch;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>ch;
            a[i][j] = ch=='1';
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>ch;
            b[i][j] = ch=='1';
        }
    }
}

void change(int x,int y) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            a[i+x][j+y] = !a[i+x][j+y];
        }
    }
}

void solution() {
    int answer = 0;
    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m-2; j++) {
            if(a[i][j]!=b[i][j]) {
                change(i,j);
                ++answer;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i][j]!=b[i][j]) {
                answer = -1;
                break;
            }
        }
    }

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


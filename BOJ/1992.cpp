#include<iostream>
using namespace std;

int n;
char map[64][64];

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
        }
    }
}

void run(int x,int y,int length) {
    if(length==1) {
        cout<<map[x][y];
        return;
    }
    char origin = map[x][y];
    for(int i=0; i<length; i++) {
        int nx = x+i;
        for(int j=0; j<length; j++) {
            int ny = y+j;
            if(map[nx][ny]!=origin) {
                length /= 2;
                cout<<"(";
                run(x,y,length);
                run(x,y+length,length);
                run(x+length,y,length);
                run(x+length,y+length,length);
                cout<<")";
                return;
            }
        }
    }
    cout<<origin;
}

void solve() {
    input();
    run(0,0,n);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

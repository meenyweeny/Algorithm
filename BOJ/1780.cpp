#include<iostream>
#include<cmath>
using namespace std;

const int max_size = 2188;
int n;
int a,b,c;
int map[max_size][max_size];

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>map[i][j];
        }
    }
}

bool check(int x,int y,int width) {
    int tmp = map[x][y];
    for(int i=0; i<width; i++) {
        for(int j=0; j<width; j++) {
            if(map[x+i][y+j]!=tmp) {
                return false;
            }
        }
    }
    return true;
}

void calc(int x,int y) {
    if(map[x][y]==0) {
        ++b;
    } else if(map[x][y]==1) {
        ++c;
    } else {
        ++a;
    }
}

void process(int x,int y,int width) {
    if(width==1) {
        calc(x,y);
        return;
    } else {
        if(check(x,y,width)) {
            calc(x,y);
        } else {
            int sep = width/3;
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    process(x+(i*sep),y+(j*sep),sep);
                }
            }
        }
    }
}

void solve() {
    input();
    process(1,1,n);
    cout<<a<<'\n'<<b<<'\n'<<c;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

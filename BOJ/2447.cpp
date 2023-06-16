#include<iostream>
using namespace std;

int n;
const int sz = 6600;
char map[sz][sz];

bool is_in_range(int x,int y,int length) {
    length/=3;
    return x>=length && x<(length*2) && y>=length && y<(length*2);
}

void process(int x,int y,int length) {
    if(length==3) {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(i==1 && j==1) {
                    map[x+i][y+j] = ' ';
                } else {
                    map[x+i][y+j] = '*';
                }
            }
        }
        return;
    } else {
        for(int i=0; i<length; i++) {
            for(int j=0; j<length; j++) {
                if(map[x+i][y+j]!=NULL) {
                    continue;
                }
                if(is_in_range(i,j,length)) {
                    map[x+i][y+j] = ' ';
                } else {
                    process(x+i,y+j,length/3);
                }
            }
        }
    }
}

void print() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<map[i][j];
        }
        cout<<'\n';
    }
}

void solve() {
    cin>>n;
    process(0,0,n);
    print();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

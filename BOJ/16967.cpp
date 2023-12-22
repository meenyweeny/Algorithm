#include<iostream>
using namespace std;

int map[601][601];
int answer[301][301];
int h,w,x,y;

bool check_range(int x,int y) {
    return x>=0 && x<h && y>=0 && y<w;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>h>>w>>x>>y;
    for(int i=0; i<h+x; i++) {
        for(int j=0; j<w+y; j++) {
            cin>>map[i][j];
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            answer[i][j] = map[i][j];
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(!check_range(i+x,j+y)) {
                continue;
            }
            answer[i+x][j+y] -= answer[i][j];
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cout<<answer[i][j]<<' ';
        }
        cout<<'\n';
    }
}

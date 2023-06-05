#include<iostream>
#include<vector>
using namespace std;

struct Point {
    int x,y;
};

vector<Point> cctv;
int map[9][9];
int n,m;
int answer = 2e9;

void input() {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>map[i][j];
            if(map[i][j]>=1 && map[i][j]<=5) {
                cctv.push_back({i,j});
            }
        }
    }
}

bool is_in_range(int x,int y) {
    return x>=1 && y>=1 && x<=n && y<=m;
}

void process(int index, int arr[9][9]) {
    if(index == cctv.size()) {
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == 0) {
                    ++tmp;
                }
            }
        }
        if(tmp==0) {
            cout<<0;
            exit(0);
        }
        answer = min(answer, tmp);
        return;
    }
    Point p = cctv[index];
    int tv = map[p.x][p.y];
    int init[9][9];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            init[i][j] = arr[i][j];
        }
    }
    int x = p.x; int y= p.y;
    int ax,ay;
        for(int i=0; i<4; i++) {
            x = p.x; y=p.y;
            ax = "2011"[i]-'1';
            ay = "1120"[i]-'1';
            while(1) {
                if(!is_in_range(x,y)) break;
                if(arr[x][y]==6) break;
                if(arr[x][y]==0) arr[x][y] = 9;
                x += ax; y += ay;
            }
            process(index+1,arr);
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=m; j++) {
                    arr[i][j] = init[i][j];
                }
            }
        }
    } else if(tv==2) {
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                ax = i==0 ? 0 : (j==0) ? -1 : 1;
                ay = i==1 ? 0 : (j==0) ? -1 : 1;
                x = p.x; y=p.y;
                while(1) {
                    if(!is_in_range(x,y)) break;
                    if(arr[x][y]==6) break;
                    if(arr[x][y]==0) arr[x][y] = 9;
                    x += ax; y += ay;
                }
            }
            process(index+1,arr);
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=m; j++) {
                    arr[i][j] = init[i][j];
                }
            }
        }
    } else if(tv==3) {
        for(int i=0; i<4; i++) {
            ax=0;
            ay = i>1 ? -1:1;
            x = p.x; y=p.y;
            while(1) {
                if(!is_in_range(x,y)) break;
                if(arr[x][y]==6) break;
                if(arr[x][y]==0) arr[x][y] = 9;
                x += ax; y += ay;
            }
            ax=(i%2==0)?-1:1;
            ay=0;
            x=p.x; y=p.y;
            while(1) {
                if(!is_in_range(x,y)) break;
                if(arr[x][y]==6) break;
                if(arr[x][y]==0) arr[x][y] = 9;
                x += ax; y += ay;
            }
            process(index+1,arr);
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=m; j++) {
                    arr[i][j] = init[i][j];
                }
            }
        }
    } else if(tv==4) {
        for(int i=0; i<4; i++) {
            if(i!=0) {
                x=p.x; y=p.y;
                while(1) {
                    if(!is_in_range(x,y)) break;
                    if(arr[x][y]==6) break;
                    if(arr[x][y]==0) arr[x][y] = 9;
                    --y;
                }
            }
            if(i!=1) {
                x=p.x; y=p.y;
                while(1) {
                    if(!is_in_range(x,y)) break;
                    if(arr[x][y]==6) break;
                    if(arr[x][y]==0) arr[x][y] = 9;
                    ++y;
                }
            }
            if(i!=2) {
                x=p.x; y=p.y;
                while(1) {
                    if(!is_in_range(x,y)) break;
                    if(arr[x][y]==6) break;
                    if(arr[x][y]==0) arr[x][y] = 9;
                    --x;
                }
            }
            if(i!=3) {
                x=p.x; y=p.y;
                while(1) {
                    if(!is_in_range(x,y)) break;
                    if(arr[x][y]==6) break;
                    if(arr[x][y]==0) arr[x][y] = 9;
                    ++x;
                }
            }
            process(index+1,arr);
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=m; j++) {
                    arr[i][j] = init[i][j];
                }
            }
        }
    } else {
        for(int i=0; i<4; i++) {
            ax = "1120"[i]-'1';
            ay = "2011"[i]-'1';
            x = p.x; y=p.y;
            while(1) {
                if(!is_in_range(x,y)) break;
                if(arr[x][y]==6) break;
                if(arr[x][y]==0) arr[x][y] = 9;
                x += ax; y += ay;
            }
        }
        process(index+1,arr);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                arr[i][j] = init[i][j];
            }
        }
    }
}

void solution() {
    process(0,map);
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

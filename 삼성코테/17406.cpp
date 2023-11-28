#include<iostream>
#include<vector>
#include<deque>
using namespace std;

struct info {
    int r,c,s;
};

int n,m,k;
int map[52][52];
int arr[52][52];
int answer = 2e9;
vector<info> turn;

void input() {
    cin>>n>>m>>k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>map[i][j];
        }
    }
    int r,c,s;
    for(int i=0; i<k; i++) {
        cin>>r>>c>>s;
        --r;
        --c;
        turn.push_back({r,c,s});
    }
}

void copy(int a[52][52],int b[52][52]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void rotate(int ax,int ay,int bx,int by) {
    deque<int> dq;
    for(int i=ay; i<=by; i++) {
        dq.push_back(arr[ax][i]);
    }
    for(int i=ax+1; i<=bx; i++) {
        dq.push_back(arr[i][by]);
    }
    for(int i=by-1; i>=ay; i--) {
        dq.push_back(arr[bx][i]);
    }
    for(int i=bx-1; i>=ax+1; i--) {
        dq.push_back(arr[i][ay]);
    }
    dq.push_front(dq.back());
    dq.pop_back();
    for(int i=ay; i<=by; i++) {
        arr[ax][i] = dq.front();
        dq.pop_front();
    }
    for(int i=ax+1; i<=bx; i++) {
        arr[i][by] = dq.front();
        dq.pop_front();
    }
    for(int i=by-1; i>=ay; i--) {
        arr[bx][i] = dq.front();
        dq.pop_front();
    }
    for(int i=bx-1; i>=ax+1; i--) {
        arr[i][ay] = dq.front();
        dq.pop_front();
    }
}

void spin(int startx, int starty, int endx, int endy) {
    while(startx < endx) {
        rotate(startx,starty,endx,endy);
        ++startx;
        ++starty;
        --endx;
        --endy;
    }
}

void make_sequence(bool visited[],vector<int> seq) {
    if(seq.size()==k) {
        copy(arr,map);
        for(auto sk:seq) {
            info i = turn[sk];
            spin(i.r-i.s, i.c-i.s,i.r+i.s,i.c+i.s);
        }
        int sum;
        for(int i=0; i<n; i++) {
            sum = 0;
            for(int j=0; j<m; j++) {
                sum += arr[i][j];
            }
            answer = min(answer,sum);
        }
        return;
    }
    for(int i=0; i<k; i++) {
        if(visited[i]) {
            continue;
        }
        visited[i] = true;
        seq.push_back(i);
        make_sequence(visited,seq);
        visited[i] = false;
        seq.pop_back();
    }
}

void solve() {
    input();
    bool visit[6];
    fill(visit,visit+6,false);
    make_sequence(visit,{});
    cout<<answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

const int inf = 1e9;
int n, m, h, answer = inf;
bool line[12][32];

void input() {
    cin >> n >> m >> h;
    int a, b;
    while (m--) {
        cin >> a >> b;
        line[b][a] = true;
    }
}

bool go(int start) {
    int end = start;
    int point = 1;
    while(point<=h) {
        if(line[end][point]) {
            ++end;
        } else if(line[end-1][point]) {
            --end;
        }
        ++point;
    }
    return start == end;
}

bool check() {
    for(int i=1; i<=n; i++) {
        if(!go(i)) {
            return false;
        }
    }
    return true;
}

void process(int now,int count,int height) {
    if(count>now) {
        return;
    }
    if(check()) {
        answer = min(answer,count);
        return;
    }
    for(int i=1; i<n; i++) {
        for(int j=height; j<=h; j++) {
            if(line[i][j]) {
                continue;
            }
            if(line[i+1][j]) {
                continue;
            }
            line[i][j] = true;
            process(now,count+1,j);
            line[i][j] = false;
        }
    }
}

void solve() {
    input();
    for(int i=0; i<4; i++) {
        process(i,0,1);
    }
    if(answer>=inf) {
        answer = -1;
    }
    cout<<answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}

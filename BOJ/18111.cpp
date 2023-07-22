#include<iostream>
using namespace std;

int n,m,b;
int map[500][500];

int test(int h) {
    int sum = 0;
    int use = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j]>=h) {
                sum += (map[i][j]-h) * 2;
                use += (map[i][j]-h);
            } else {
                sum += (h-map[i][j]);
                use -= (h-map[i][j]);
            }
        }
    }
    if(b+use<0) {
        sum = 2e9;
    }
    return sum;
}

void input() {
    cin>>n>>m>>b;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>map[i][j];
        }
    }
}

void solution() {
    int answer = 2e9;
    int height = 0;
    for(int h=0; h<=256; h++) {
        int now = test(h);
        if(answer>=now) {
            height = h;
            answer = now;
        }
    }
    cout<<answer<<' '<<height;
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

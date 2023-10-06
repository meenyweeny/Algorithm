#include<iostream>
#include<vector>
using namespace std;

int n,m,c,answer=2e9;
int map[50][50];
int dist[13][50][50];
vector<pair<int,int>> chicken;
vector<pair<int,int>> home;
bool pick[13];

void input() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
            if(map[i][j]==2) {
                chicken.push_back({i,j});
            } else if(map[i][j]==1) {
                home.push_back({i,j});
            }
        }
    }
}

int get_dist(pair<int,int> a, pair<int,int> b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

void make_dist() {
    for(int i=0; i<home.size(); i++) {
        pair<int,int> h = home[i];
        for(int j=0; j<chicken.size(); j++) {
            dist[j][h.first][h.second] = get_dist(chicken[j],h);
        }
    }
}

int get_chicken_dist() {
    int ret = 0;
    for(int i=0; i<home.size(); i++) {
        pair<int,int> h = home[i];
        int tmp = 2e9;
        for(int j=0; j<chicken.size(); j++) {
            if(!pick[j]) {
                tmp = min(tmp,dist[j][h.first][h.second]);
            }
        }
        ret += tmp;
    }
    return ret;
}

void fire(int count,int index) {
    if(count>=c-m) {
        answer = min(answer,get_chicken_dist());
    }
    if(count==c-1) {
        return;
    }
    for(int i=index; i<chicken.size(); i++) {
        pick[i] = true;
        fire(count+1,i+1);
        pick[i] = false;
    }
}

void solution() {
    c=chicken.size();
    make_dist();
    fire(0,0);
    cout<<answer;
}

void solve() {
    input();
    solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}

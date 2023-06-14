#include<iostream>
#include<vector>
using namespace std;

struct Point {
    int x,y;
};

int n,m;
int answer;
int map[502][502];

//ㅁ
const vector<vector<Point>> a = {{{0,0},{0,1},{1,0},{1,1}}};

//ㅡ
const vector<vector<Point>> b = {{{0,0},{0,1},{0,2},{0,3}},
                           {{0,0},{1,0},{2,0},{3,0}}};

//ㄴ
const vector<vector<Point>> c = {{{0,0},{1,0},{2,0},{2,1}},
                           {{0,0},{0,1},{0,2},{1,0}},
                           {{0,0},{0,1},{1,1},{2,1}},
                           {{0,0},{0,1},{0,2},{-1,2}},
                           {{0,0},{0,1},{1,0},{2,0}},
                           {{0,0},{1,0},{1,1},{1,2}},
                           {{0,0},{0,1},{0,2},{1,2}},
                           {{0,0},{1,0},{2,0},{2,-1}}};

//ㄹ
const vector<vector<Point>> d = {{{0,0},{1,0},{1,1},{2,1}},
                           {{0,0},{0,1},{1,0},{1,-1}},
                           {{0,0},{1,0},{1,-1},{2,-1}},
                           {{0,0},{0,1},{1,1},{1,2}}};

//ㅗ
const vector<vector<Point>> e = {{{0,0},{1,0},{1,1},{2,0}},
                           {{0,0},{0,1},{0,2},{1,1}},
                           {{0,0},{1,0},{2,0},{1,-1}},
                           {{0,0},{1,0},{1,-1},{1,1}}};

vector<vector<vector<Point>>> shape = {a,b,c,d,e};

void input() {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>map[i][j];
        }
    }
}

bool is_in_range(int x,int y) {
    return x>=1 && y>=1 && x<=n && y<=m;
}

void process() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int sum = 0;
            for(auto sha:shape) {
                for(auto sh:sha) {
                    sum = 0;
                    for(auto s:sh) {
                        if(!is_in_range(i+s.x,j+s.y)) {
                            break;
                        }
                        sum += map[i+s.x][j+s.y];
                    }
                    answer = max(answer,sum);
                }
            }
        }
    }
}

void solution() {
    process();
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

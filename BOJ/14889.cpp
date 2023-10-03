#include<iostream>
#include<vector>
using namespace std;

int n;
int map[20][20];
bool visited[20];
int answer = 2e9;

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
        }
    }
}

pair<int,int> get_score() {
    int a,b;
    a = b = 0;
    vector<int> x,y;
    for(int i=0; i<n; i++) {
        visited[i] ? x.push_back(i) : y.push_back(i);
    }
    for(int i=0; i<n/2; i++) {
        for(int j=0; j<n/2; j++) {
            a += map[x[i]][x[j]];
            b += map[y[i]][y[j]];
        }
    }
    return {a,b};
}

void make_team(int count,int index) {
    if(count==n/2) {
        pair<int,int> score = get_score();
        answer = min(answer,abs(score.first-score.second));
        return;
    }
    for(int i=index; i<n; i++) {
        visited[i] = true;
        make_team(count+1,i+1);
        visited[i] = false;
    }
}

void solution() {
    make_team(0,0);
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

#include<iostream>
#include<vector>
using namespace std;

int n,m;
int deletecount;
int answer = 1e9;

struct Point {
    int x,y;
};

vector<Point> store;
vector<Point> home;

int dist[13][51][51];
bool visited[13];

int get_dist(Point a, Point b) {
    return abs(a.x-b.x) + abs(a.y-b.y);
}

void input() {
    cin>>n>>m;
    int k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>k;
            if(k==1) {
                home.push_back({i,j});
            } else if(k==2) {
                store.push_back({i,j});
            }
        }
    }
}

void run(int start, int count, bool visit[]) {
    if(count>=store.size()) {
        return;
    }

    if(count>=deletecount) {
        int mindist;
        int mini = 0;
        for(int i=0; i<home.size(); i++) {
            mindist = 1e9;
            for(int j=0; j<store.size(); j++) {
                if(visit[j]) {
                    continue;
                }
                mindist = min(mindist,dist[j][home[i].x][home[i].y]);
            }
            mini += mindist;
        }
        answer = min(answer, mini);
    }

    for(int i=start; i<store.size(); i++) {
        if(visit[i]) {
            continue;
        }
        visit[i] = true;
        run(i,count+1,visit);
        visit[i] = false;
    }
}

void solution() {
    deletecount = store.size() - m;
    for(int i=0; i<home.size(); i++) {
        for(int j=0; j<store.size(); j++) {
            dist[j][home[i].x][home[i].y] = get_dist(home[i],store[j]);
        }
    }
    run(0,0,visited);
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

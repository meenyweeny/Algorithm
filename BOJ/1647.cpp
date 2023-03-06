#include<iostream>
#include<vector>
using namespace std;

int n,answer,cnt;
vector<pair<int,pair<int,int>>> edges;
int home[100001];

int find(int x) {
    if(home[x]==x) {
        return x;
    } else {
        return home[x] = find(home[x]);
    }
}

bool merge(int x,int y) {
    int xroot = find(x);
    int yroot = find(y);

    if(xroot==yroot) {
        return true;
    } else {
        home[xroot] = yroot;
        return false;
    }
}

void input() {
    int m,a,b,c;
    cin>>n>>m;
    while(m--) {
        cin>>a>>b>>c;
        edges.push_back({c,{a,b}});
    }
}

void solution() {
    sort(edges.begin(), edges.end());
    for(int i=1; i<=100000; i++) {
        home[i] = i;
    }
    for(auto edge:edges) {
        if(cnt==n-2) {
            break;
        }
        if(merge(edge.second.first, edge.second.second)) {
            continue;
        }
        answer += edge.first;
        ++cnt;
    }
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

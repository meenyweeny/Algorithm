#include<iostream>
#include<vector>
using namespace std;

const string answer[4] = {"No trees.", "There is one tree.", "A forest of ", " trees."};
const int nodesize = 5e2 + 1;
int n,m;
vector<int> graph[nodesize];
bool visited[nodesize];
bool flag = false;

void input() {
    int u,v;
    while(m--) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void traverse(int parent, int start) {
    visited[start] = true;
    for(auto g:graph[start]) {
        if(visited[g] && parent!=g) {
            flag = true;
            continue;
        }
        if(visited[g]) {
            continue;
        }
        traverse(start, g);
    }
}

void solution() {
    int count = 0;
    for(int i=1; i<=n; i++) {
        if(visited[i]) {
            continue;
        }
        flag = false;
        traverse(-1,i);
        if(!flag) {
            ++count;
        }
    }
    if(count>1) {
        cout<<answer[2]<<count<<answer[3];
    } else {
        cout<<answer[count];
    }
}

void init() {
    for(int i=1; i<=n; i++) {
        graph[i].clear();
    }
    fill(visited,visited+nodesize,false);
}

void solve() {
    int tc = 1;
    while(1) {
        cin>>n>>m;
        if(n==0 && m==0) {
            break;
        }
        cout<<"Case "<<tc++<<": ";
        init();
        input();
        solution();
        cout<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}

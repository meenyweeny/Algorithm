#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct edge {
    int vertex;
    int weight;

    bool operator<(const edge & b) const {
        return weight < b.weight;
    }
};

int n,m,s,e;
pair<int,int> dist[1001];
vector<edge> graph[1001];
const int inf = 2e9;

void input() {
    cin>>n;
    cin>>m;
    int d;
    while(m--) {
        cin>>s>>e>>d;
        graph[s].push_back({e,d});
    }
    cin>>s>>e;
}

void solution() {
    pair<int,int> tmp = {0,inf};
    fill(dist,dist+1001,tmp);
    priority_queue<edge> pq;
    pq.push({s,0});
    dist[s] = {-1,0};

    while(!pq.empty()) {
        edge top = pq.top();
        pq.pop();

        if(dist[top.vertex].second < top.weight) {
            continue;
        }

        int length = graph[top.vertex].size();
        for(int i=0; i<length; i++) {
            edge next = graph[top.vertex][i];

            if(dist[next.vertex].second > top.weight + next.weight) {
                dist[next.vertex] = {top.vertex, top.weight + next.weight};
                pq.push({next.vertex, dist[next.vertex].second});
            }
        }
    }
    cout<<dist[e].second<<'\n';

    int front = e;
    vector<int> ans;
    ans.push_back(e);
    while(1) {
        front = dist[front].first;
        if(front==-1) {
            break;
        } else {
            ans.push_back(front);
        }
    }

    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<'\n';
    for(auto i:ans) {
        cout<<i<<' ';
    }
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

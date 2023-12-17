#include<iostream>
#include<vector>
using namespace std;

const int bucketsize = 1e5;
int n;
vector<pair<int,int>> v;
int dist[bucketsize];
unsigned long long sum;
unsigned long long answer = 2e13;

int get_dist(int x,int y,int xx,int yy) {
    return abs(x-xx) + abs(y-yy);
}

void solve() {
    cin>>n;
    int x,y;
    for(int i=0; i<n; i++) {
        cin>>x>>y;
        v.push_back({x,y});
    }
    for(int i=1; i<n; i++) {
        dist[i-1] = get_dist(v[i-1].first, v[i-1].second, v[i].first, v[i].second);
        sum += dist[i-1];
    }
    answer = sum;
    for(int i=1; i<n-1; i++) {
        unsigned long long tmp = sum;
        tmp -= dist[i-1];
        tmp -= dist[i];
        tmp += get_dist(v[i-1].first, v[i-1].second, v[i+1].first, v[i+1].second);
        answer = min(answer, tmp);
    }
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

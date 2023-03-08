#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct Point {
    double x,y;
};

Point star[101];
int arr[101];
int n;
double answer;
vector<pair<double,pair<int,int>>> edges;

double get_distance(Point a, Point b) {
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}

int find(int x) {
    if(arr[x]==x) {
        return x;
    } else {
        return arr[x] = find(arr[x]);
    }
}

bool merge(int x,int y) {
    int xroot = find(x);
    int yroot = find(y);

    if(xroot==yroot) {
        return false;
    } else {
        arr[xroot] = yroot;
        return true;
    }
}

void input() {
    cin>>n;
    double x,y;
    for(int i=1; i<=n; i++) {
        cin>>x>>y;
        star[i]={x,y};
    }
}

void solution() {
    for(int i=0; i<101; i++) {
        arr[i] = i;
    }
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            edges.push_back({get_distance(star[i],star[j]),{i,j}});
        }
    }
    sort(edges.begin(), edges.end());
    int num=1;
    for(auto edge:edges) {
        if(num==n) {
            break;
        }
        if(merge(edge.second.first, edge.second.second)) {
            ++num;
            answer += edge.first;
        }
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

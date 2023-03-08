#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int n,m;
pair<double,double> v[1001];
double answer;
int arr[1001];
vector<pair<double,pair<double,double>>> edges;

double get_distance(pair<double,double> a, pair<double,double> b) {
    return sqrt(pow((a.first-b.first),2)+pow((a.second-b.second),2));
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
    cin>>n>>m;
    double x,y;
    for(int i=1; i<=n; i++) {
        cin>>x>>y;
        v[i] = {x,y};
    }
}

void solution() {
    for(int i=0; i<1001; i++) {
        arr[i] = i;
    }
    int a,b;
    while(m--) {
        cin>>a>>b;
        merge(a,b);
    }
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            edges.push_back({get_distance(v[i],v[j]),{i,j}});
        }
    }
    sort(edges.begin(), edges.end());
    int num=1;
    for(auto edge:edges) {
        if(num==n) {
            break;
        }
        if(merge(edge.second.first, edge.second.second)) {
            answer += edge.first;
            ++num;
        }
    }
    cout<<setprecision(2)<<fixed<<answer;
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

//
// Created by 이경민 on 2023/02/06.
//
#include<iostream>
#include<vector>
using namespace std;

int n,m;
bool map[201][201];
int arr[201];
vector<int> road;

int find(int x) {
    if(arr[x] == x) {
        return x;
    } else {
        return arr[x] = find(arr[x]);
    }
}

void merge(int x,int y) {
    int xroot = find(x);
    int yroot = find(y);

    if(xroot != yroot) {
        arr[xroot] = yroot;
    }
}

bool check_union(int x,int y) {
    int xroot = find(x);
    int yroot = find(y);
    return xroot == yroot;
}

void input() {
    cin>>n;
    cin>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>map[i][j];
        }
    }
    int x;
    for(int i=0; i<m; i++) {
        cin>>x;
        road.push_back(x);
    }
}

void solution() {
    for(int i=1; i<=n; i++) {
        arr[i] = i;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(map[i][j]) {
                merge(i,j);
            }
        }
    }

    int prev = road[0];
    int length = road.size();
    bool flag = true;
    for(int i=1; i<length; i++) {
        if(check_union(prev,road[i])) {
            prev = road[i];
        } else {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}

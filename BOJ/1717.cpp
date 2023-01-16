//
// Created by 이경민 on 2023/01/16.
//
#include<iostream>
using namespace std;

int n,m,a,b;
bool command;
int arr[1000001];

int find(int x) {
    if(arr[x] == x) {
        return x;
    } else {
        return arr[x] = find(arr[x]);
    }
}

bool merge(int x,int y) {
    int a_root = find(x);
    int b_root = find(y);

    if(a_root == b_root) {
        return true;
    } else {
        arr[a_root] = b_root;
        return false;
    }
}

bool check_union(int x,int y) {
    int a_root = find(x);
    int b_root = find(y);
    return a_root == b_root;
}

void input() {
    cin>>n>>m;
}

void solution() {
    for(int i=0; i<=n; i++) {
        arr[i] = i;
    }

    while(m--) {
        cin>>command;
        cin>>a>>b;
        if(!command) {
            merge(a,b);
        } else {
            check_union(a,b) ? cout<<"yes" : cout<<"no";
            cout<<'\n';
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}

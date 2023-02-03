//
// Created by 이경민 on 2023/02/03.
//
#include<iostream>
using namespace std;

int tree[400004];
int n,m;
int height;

void get_height() {
    height = 2;
    while(height<=n) {
        height *= 2;
    }
}

void input() {
    cin>>n>>m;
    get_height();
    for(int i=0; i<n; i++) {
        cin>>tree[height+i];
    }
}

void build() {
    for(int i=height-1; i>0; i--) {
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }
}

int solution(int start, int end) {
    start+=height;
    end+=height;
    --start;
    --end;
    int mini = 2e9;
    while(start<=end) {
        if(start%2==1) {
            mini = min(tree[start], mini);
            ++start;
        }
        if(end%2==0) {
            mini = min(tree[end], mini);
            --end;
        }
        start/=2;
        end/=2;
    }
    return mini;
}

void solve() {
    fill(tree,tree+400004,2e9);
    input();
    build();
    int a,b;
    while(m--) {
        cin>>a>>b;
        cout<<solution(a,b)<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

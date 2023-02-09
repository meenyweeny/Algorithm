//
// Created by 이경민 on 2023/02/08.
//
#include<iostream>
using namespace std;

int n,m;
const int maxsize = 100001;
const int inf = 2e9;
int tree[maxsize*4];
int height;

void get_height() {
    height = 2;
    while(height<=n) {
        height*=2;
    }
}

void build() {
    for(int i=height-1; i>0; i--) {
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }
}

void update(int index, int number) {
    int idx = index;
    idx += height;
    --idx;
    tree[idx] = number;
    idx/=2;
    while(idx>0) {
        tree[idx] = min(tree[idx*2], tree[idx*2+1]);
        idx/=2;
    }
}

int query(int start, int end) {
    start += height;
    end += height;
    --start;
    --end;
    int mini = inf;
    while(start<=end) {
        if(start%2==1) {
            mini = min(mini, tree[start]);
            ++start;
        }
        if(end%2==0) {
            mini = min(mini, tree[end]);
            --end;
        }
        start/=2;
        end/=2;
    }

    return mini;
}

void solve() {
    cin>>n;
    fill(tree, tree+maxsize*4, inf);
    get_height();
    int c,a,b;
    for(int i=0; i<n; i++) {
        cin>>tree[i+height];
    }
    build();
    cin>>m;
    while(m--) {
        cin>>c>>a>>b;
        if(c==1) {
            update(a,b);
        } else {
            cout<<query(a,b)<<'\n';
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

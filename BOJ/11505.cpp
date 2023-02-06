//
// Created by 이경민 on 2023/02/03.
//
#include<iostream>
#include<cstring>
using namespace std;

const int mod = 1000000007;
int n,m,k;
unsigned long long tree[2100000];
int height;

void get_height() {
    height = 2;
    while(height<=n) {
        height *= 2;
    }
}

void input() {
    cin>>n>>m>>k;
    get_height();
    memset(tree, 1, sizeof(tree));
    for(int i=0; i<n; i++) {
        cin>>tree[height+i];
    }
}

void build() {
    for(int i=height-1; i>0; i--) {
        tree[i] = (tree[i*2] * tree[i*2 + 1]) % mod;
    }
}

void update(int index, int number) {
    index += height;
    --index;
    tree[index] = number;
    index/=2;
    while(index>=1) {
        tree[index] = (tree[index*2] * tree[index*2 + 1]) % mod;
        index/=2;
    }
}

unsigned long long query(int start, int end) {
    start += height;
    end += height;
    --start;
    --end;
    unsigned long long ret = 1;

    while(start<=end) {
        if(start%2==1) {
            ret *= tree[start];
            ret%=mod;
            ++start;
        }
        if(end%2==0) {
            ret *= tree[end];
            ret%=mod;
            --end;
        }
        start/=2;
        end/=2;
    }
    return ret;
}

void solve() {
    input();
    build();
    int a,b,c;
    m+=k;
    while(m--) {
        cin>>a>>b>>c;
        if(a==1) {
            update(b,c);
        } else {
            cout<<query(b,c)<<'\n';
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

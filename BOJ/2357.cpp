//
// Created by 이경민 on 2023/02/02.
//
#include<iostream>
#include<vector>
using namespace std;

struct element {
    int maxi;
    int mini;
};

element tree[400004];
int n,m;
int height;

void init() {
    element tmp;
    tmp.maxi = -2e9;
    tmp.mini = 2e9;
    fill(tree,tree+(height*2 + 1),tmp);
}

void input() {
    cin>>n>>m;
    int a;
    height = 2;
    while(height<=n) {
        height *= 2;
    }
    for(int i=0; i<n; i++) {
        cin>>a;
        tree[height+i] = {a,a};
    }
}

element comparison(element a, element b) {
    element ret;
    ret.mini = min(a.mini, b.mini);
    ret.maxi = max(a.maxi, b.maxi);
    return ret;
}

void build() {
    for(int i=height-1; i>0; i--) {
        tree[i] = comparison(tree[i*2], tree[i*2 + 1]);
    }
}

element solution(int start, int end) {
    element ret;
    ret.mini = 2e9;
    ret.maxi = -2e9;
    start+=height;
    end+=height;
    --start;
    --end;
    while(start<=end) {
        if(start%2==1) {
            ret.mini = min(tree[start].mini, ret.mini);
            ret.maxi = max(tree[start].maxi, ret.maxi);
            ++start;
        }
        if(end%2==0) {
            ret.mini = min(tree[end].mini, ret.mini);
            ret.maxi = max(tree[end].maxi, ret.maxi);
            --end;
        }
        start/=2;
        end/=2;
    }
    return ret;
}

void solve() {
    init();
    input();
    build();
    int a,b;
    element answer;
    while(m--) {
        cin>>a>>b;
        answer = solution(a,b);
        cout<<answer.mini<<' '<<answer.maxi<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

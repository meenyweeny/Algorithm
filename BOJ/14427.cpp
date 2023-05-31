#include<iostream>
using namespace std;

int n;
int height;
const int max_size = 1e5 + 1;
const int inf = 2e9;
pair<int,int> tree[max_size<<2];

void get_height() {
    height = 2;
    while(height<=n) {
        height *= 2;
    }
}

void build() {
    pair<int,int> a,b;
    for(int i=height-1; i>0; i--) {
        a=tree[i*2];
        b=tree[i*2+1];
        tree[i]= a.first <= b.first ? a:b;
    }
}

void update(int index,int value) {
    tree[index].first=value;
    index/=2;
    pair<int,int> a,b;
    while(index>0) {
        a=tree[index*2];
        b=tree[index*2+1];
        tree[index]= a.first <= b.first ? a:b;
        index/=2;
    }
}

void init() {
    pair<int,int> tmp = {inf,0};
    fill(tree,tree+(max_size<<2),tmp);
}

void input() {
    cin>>n;
    get_height();
    int k;
    for(int i=0; i<n; i++) {
        cin>>k;
        tree[i+height] = {k,i+1};
    }
}

void process() {
    int m;
    cin>>m;
    int cmd,a,b;
    while(m--) {
        cin>>cmd;
        if(cmd==1) {
            cin>>a>>b;
            update(a+height-1,b);
        } else {
            cout<<tree[1].second<<'\n';
        }
    }
}

void solve() {
    init();
    input();
    build();
    process();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

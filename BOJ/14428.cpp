#include<iostream>
using namespace std;

int n;
const int sz = 100001;
pair<int,int> tree[sz<<2];
int height;

void get_height() {
    height = 2;
    while(1) {
        if(n<=height) {
            break;
        }
        height*=2;
    }
}

void input() {
    cin>>n;
    get_height();
    pair<int,int> tmp = {sz+1, 2e9};
    fill(tree,tree+(sz<<2),tmp);
    int k;
    for(int i=0; i<n; i++) {
        cin>>k;
        tree[i+height]={i+1,k};
    }
}

pair<int,int> get_min(pair<int,int> a, pair<int,int> b) {
    if(a.second==b.second) {
        return a.first < b.first ? a : b;
    } else {
        return a.second < b.second ? a : b;
    }
}

void build() {
    for(int i=height-1; i>0; i--) {
        tree[i] = get_min(tree[i*2], tree[i*2+1]);
    }
}

void update(int index, int num) {
    index+=height;
    --index;
    tree[index] = {tree[index].first, num};
    index/=2;
    while(1) {
        if(index<=0) {
            break;
        }
        tree[index] = get_min(tree[index*2],tree[index*2+1]);
        index/=2;
    }
}

int query(int start, int end) {
    pair<int,int> ret = {sz+1, 2e9};
    start+=height;
    --start;
    end+=height;
    --end;
    while(start<=end) {
        if(start%2==1) {
            ret = get_min(ret,tree[start]);
            ++start;
        }
        if(end%2==0) {
            ret = get_min(ret,tree[end]);
            --end;
        }
        start/=2;
        end/=2;
    }
    return ret.first;
}

void solve() {
    input();
    build();
    int m;
    cin>>m;
    int c,a,b;
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

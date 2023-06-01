#include<iostream>
using namespace std;

const int inf = 2e9;
const int max_size = 1e5 + 1;
pair<int,int> tree[max_size<<2];
int n,height,answer;

void get_height() {
    height = 2;
    while(height<=n) {
        height *= 2;
    }
}

void build() {
    pair<int,int> a,b;
    for(int i=height-1; i>0; i--) {
        a = tree[i*2];
        b = tree[i*2+1];
        tree[i] = a.first <= b.first ? a : b;
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
    for(int i=1; i<=n; i++) {
        cin>>k;
        tree[i+height-1] = {k,i};
    }
}

void process(int start,int end) {

    int s_idx,e_idx;
    s_idx = start - 1 + height;
    e_idx = end - 1 + height;
    int minval, minidx;
    minval = 2e9;

    while(s_idx<=e_idx) {
        if(s_idx%2==1) {
            if(tree[s_idx].first <= minval) {
                minval = tree[s_idx].first;
                minidx = tree[s_idx].second;
            }
            ++s_idx;
        }
        if(e_idx%2==0) {
            if(tree[e_idx].first < minval) {
                minval = tree[e_idx].first;
                minidx = tree[e_idx].second;
            }
            --e_idx;
        }
        s_idx/=2;
        e_idx/=2;
    }
    answer = max(answer, minval * (end-start+1));
    if(start<=minidx-1) {
        process(start,minidx-1);
    }
    if(end>=minidx+1) {
        process(minidx+1, end);
    }
}

void solve() {
    init();
    input();
    build();
    process(1,n);
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

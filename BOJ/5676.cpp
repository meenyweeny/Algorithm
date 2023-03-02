#include<iostream>
using namespace std;

int n;
const int sz = 100001;
int tree[sz*4];
int height;

void init() {
    fill(tree,tree+(sz<<2),1);
}

void get_height() {
    height = 2;
    while(1) {
        if(height>=n) {
            break;
        }
        height *= 2;
    }
}

void build() {
    for(int i=height-1; i>0; i--) {
        tree[i] = tree[i*2] * tree[i*2+1];
    }
}

void update(int index, int num) {
    index+=height;
    --index;
    tree[index] = num;
    index/=2;
    while(1) {
        if(index<=0) {
            break;
        }
        tree[index] = tree[index*2] * tree[index*2+1];
        index/=2;
    }
}

void query(int start, int end) {
    start+=height;
    end+=height;
    --start;
    --end;
    int ret = 1;
    while(start<=end) {
        if(start%2==1) {
            ret*=tree[start];
            ++start;
        }
        if(end%2==0) {
            ret*=tree[end];
            --end;
        }
        start/=2;
        end/=2;
    }
    if(ret==0) {
        cout<<'0';
    } else {
        ret < 0 ? cout<<'-' : cout<<'+';
    }
}

void solve() {
    int k;
    int a,b;
    char c;
    while(cin>>n>>k) {
        get_height();
        init();
        for(int i=0; i<n; i++) {
            cin>>a;
            if(a==0) {
                tree[i+height] = 0;
            } else {
                tree[i+height] = a < 0 ? -1 : 1;
            }
        }
        build();
        while(k--) {
            cin>>c;
            cin>>a>>b;
            if(c=='C') {
                if(b==0) {
                    update(a,0);
                } else if(b<0) {
                    update(a,-1);
                } else {
                    update(a,1);
                }
            } else {
                query(a,b);
            }
        }
        cout<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

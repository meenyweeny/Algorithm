#include<iostream>
using namespace std;

int n;
const int sz = 1000001;
long long tree[sz<<2];
int height;

void get_height() {
    height = 2;
    while(1) {
        if(height>=n) {
            break;
        }
        height*=2;
    }
}

void update(int p, int x) {
    p+=height;
    --p;
    tree[p] += x;
    p/=2;
    while(1) {
        if(p<=0) {
            break;
        }
        tree[p] = tree[p*2] + tree[p*2+1];
        p/=2;
    }
}

long long query(int start,int end) {
    long long ret = 0;
    --start;
    --end;
    start+=height;
    end+=height;
    while(start<=end) {
        if(start%2==1) {
            ret+=tree[start];
            ++start;
        }
        if(end%2==0) {
            ret+=tree[end];
            --end;
        }
        start/=2;
        end/=2;
    }
    return ret;
}

void solve() {
    cin>>n;
    get_height();
    int q,c,a,b;
    cin>>q;
    while(q--) {
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

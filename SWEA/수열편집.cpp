#include<iostream>
#include<deque>
using namespace std;

int n,m,l,x,y;
deque<int> lhs;
deque<int> rhs;

void init() {
    lhs.clear();
    rhs.clear();
}

void input() {
    cin>>n>>m>>l;
    int k;
    for(int i=0; i<n; i++) {
        cin>>k;
        lhs.push_back(k);
    }
}

void make_lhs() {
    if(lhs.size()==x) {
        return;
    }
    if(lhs.size()>x) {
        while(lhs.size()>x && !lhs.empty()) {
            rhs.push_front(lhs.back());
            lhs.pop_back();
        }
    } else {
        while(lhs.size()<x && !rhs.empty()) {
            lhs.push_back(rhs.front());
            rhs.pop_front();
        }
    }
}

void insert() {
    cin>>x>>y;
    make_lhs();
    lhs.push_back(y);
}

void deletion() {
    cin>>x;
    ++x;
    make_lhs();
    lhs.pop_back();
}

void convert() {
    cin>>x>>y;
    if(lhs.size()>x) {
        lhs[x] = y;
    } else {
        rhs[x-lhs.size()] = y;
    }
}

void solution() {
    char cmd;
    while(m--) {
        cin>>cmd;
        if(cmd=='I') {
            insert();
        } else if(cmd=='D') {
            deletion();
        } else {
            convert();
        }
    }
}

int get_answer() {
    if(lhs.size()+rhs.size()<=l) {
        return -1;
    }
    if(lhs.size()<=l) {
        l-=lhs.size();
        return rhs[l];
    } else {
        return lhs[l];
    }
}

void solve() {
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++) {
        init();
        input();
        solution();
        cout<<'#'<<tc<<' '<<get_answer()<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

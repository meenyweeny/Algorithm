#include<iostream>
#include<deque>
using namespace std;

int n,m,x;
deque<int> lhs;
deque<int> rhs;
char cmd;

void init() {
    lhs.clear();
    rhs.clear();
}

void input() {
    int k;
    for(register int i=0; i<n; i++) {
        cin>>k;
        lhs.push_back(k);
    }
}

void make_lhs() {
    if(x==lhs.size()) {
        return;
    }
    if(x<lhs.size()) {
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
    int y,k;
    cin>>x>>y;
    make_lhs();
    for(int i=0; i<y; i++) {
        cin>>k;
        lhs.push_back(k);
    }
}

void append() {
    int y,k;
    cin>>y;
    for(int i=0; i<y; i++) {
        cin>>k;
        rhs.push_back(k);
    }
}

void deletion() {
    int y;
    cin>>x>>y;
    make_lhs();
    while(y-- && !rhs.empty()) {
        rhs.pop_front();
    }
}

void solution() {
    while(m--) {
        cin>>cmd;
        if(cmd=='I') {
            insert();
        } else if(cmd=='D') {
            deletion();
        } else {
            append();
        }
    }
}

void print() {
    int a = lhs.size();
    if(a>=10) {
        for(int i=0; i<10; i++) {
            cout<<lhs[i]<<' ';
        }
    } else {
        for(int i=0; i<a; i++) {
            cout<<lhs[i]<<' ';
        }
        a = (10-a);
        for(int i=0; i<a; i++) {
            cout<<rhs[i]<<' ';
        }
    }
    cout<<'\n';
}

void solve() {
    for(int tc=1; tc<=10; tc++) {
        init();
        cin>>n;
        input();
        cin>>m;
        solution();
        cout<<'#'<<tc<<' ';
        print();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

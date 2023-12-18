#include<iostream>
using namespace std;

string a,b;
bool flag;

void run(string s) {
    if(flag) {
        return;
    }
    if(s.length()<b.length()) {
        return;
    }
    if(s==b) {
        flag = true;
        return;
    }
    if(s.back()=='A') {
        s.pop_back();
        run(s);
    } else {
        s.pop_back();
        reverse(s.begin(), s.end());
        run(s);
    }
}

void solve() {
    cin>>b;
    cin>>a;
    run(a);
    cout<<flag;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

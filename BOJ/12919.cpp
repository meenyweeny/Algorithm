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
    string tmp = s;
    if(s[0]=='B' && s[s.length()-1]=='A') {
        s.pop_back();
        run(s);
        s = tmp;
        reverse(s.begin(), s.end());
        s.pop_back();
        run(s);
    } else if(s[0]=='A' && s[s.length()-1]=='A') {
        s.pop_back();
        run(s);
    } else if(s[0]=='B' && s[s.length()-1]=='B') {
        reverse(s.begin(), s.end());
        s.pop_back();
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

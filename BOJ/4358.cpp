#include<iostream>
#include<map>
using namespace std;

int cnt;
map<string,int> spc;

void input() {
    string str;
    while(getline(cin,str)) {
        auto iter = spc.find(str);
        if(iter==spc.end()) {
            spc.insert({str,1});
        } else {
            ++iter->second;
        }
        ++cnt;
    }
}

void solution() {
    double result;
    for(auto s:spc) {
        result = (double)(s.second)/cnt;
        result*=100;
        cout<<fixed;
        cout.precision(4);
        cout<<s.first<<' '<<result<<'\n';
    }
}

void solve() {
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

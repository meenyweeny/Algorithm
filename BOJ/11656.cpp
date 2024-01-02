#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin>>s;
    string tmp = "";
    vector<string> v;
    reverse(s.begin(), s.end());
    for(auto c:s) {
        tmp = c + tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(auto vv:v) {
        cout<<vv<<'\n';
    }
}

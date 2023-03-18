#include<iostream>
#include<set>
using namespace std;

set<string> s;
int n;

void solve() {
    int n;
    cin>>n;
    string a,b;
    int answer = 1;
    while(n--) {
        cin>>a;
        cin>>b;
        if(a == "ChongChong") {
            s.insert(a);
        }
        if(b == "ChongChong") {
            s.insert(b);
        }
        bool find_a,find_b;
        find_a = (s.find(a) != s.end());
        find_b = (s.find(b) != s.end());
        if(!find_a && find_b) {
            s.insert(a);
            ++answer;
        } else if(find_a && !find_b) {
            s.insert(b);
            ++answer;
        }
    }
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

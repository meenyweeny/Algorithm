#include<iostream>
#include<vector>
using namespace std;

int n,p,answer;
vector<int> fret[7];

void solve() {
    cin>>n>>p;
    int a,b;
    while(n--) {
        cin>>a>>b;
        while(!fret[a].empty()) {
            if(fret[a].back()==b) {
                break;
            } else if(fret[a].back()<b) {
                fret[a].push_back(b);
                ++answer;
                break;
            }
            fret[a].pop_back();
            ++answer;
        }
        if(fret[a].empty()) {
            fret[a].push_back(b);
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

#include<iostream>
#include<vector>
using namespace std;

int n,l;
vector<int> hole;
vector<pair<int,int>> tape;

void input() {
    cin>>n>>l;
    int k;
    for(int i=0; i<n; i++) {
        cin>>k;
        hole.push_back(k);
    }
}

void solution() {
    sort(hole.begin(), hole.end());
    tape.push_back({1,hole[0]});
    for(int i=1; i<n; i++) {
        if(tape.back().first==l) {
            tape.push_back({1,hole[i]});
        } else {
            int gap = tape.back().first + (hole[i]-tape.back().second);
            if(gap <= l) {
                tape.pop_back();
                tape.push_back({gap,hole[i]});
            } else {
                tape.push_back({1,hole[i]});
            }
        }
    }
    cout<<tape.size();
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

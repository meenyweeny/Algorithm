#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> ab,cd;
long long arr[4][4001];
long long answer;

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<4; j++) {
            cin>>arr[j][i];
        }
    }
}

void solve() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ab.push_back(arr[0][i]+arr[1][j]);
            cd.push_back(arr[2][i]+arr[3][j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    int ab_size = ab.size();
    for(int i=0; i<ab_size; i++) {
        int pre = lower_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
        int end = upper_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();

        answer += (end-pre);
    }
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solve();
}

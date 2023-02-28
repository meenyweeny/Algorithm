#include<iostream>
#include<vector>
using namespace std;

int n;
const int lowest = -1e9;
vector<int> arr;
vector<int> revarr;
vector<int> lis;
vector<int> revlis;
int idx[1001];
int revidx[1001];

void input() {
    cin>>n;
    int k;
    for(int i=0; i<n; i++) {
        cin>>k;
        arr.push_back(k);
        revarr.push_back(k);
    }
    reverse(revarr.begin(), revarr.end());
}

void solution() {
    lis.push_back(lowest);
    revlis.push_back(lowest);

    for(int i=0; i<n; i++) {
        if(arr[i]>lis.back()) {
            lis.push_back(arr[i]);
            idx[i]=lis.size()-1;
        } else {
            int backidx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            idx[i] = backidx;
            lis[backidx] = arr[i];
        }
    }

    for(int i=0; i<n; i++) {
        if(revarr[i]>revlis.back()) {
            revlis.push_back(revarr[i]);
            revidx[i]=revlis.size()-1;
        } else {
            int backidx = lower_bound(revlis.begin(), revlis.end(), revarr[i]) - revlis.begin();
            revidx[i] = backidx;
            revlis[backidx] = revarr[i];
        }
    }
    reverse(revidx,revidx+n);
    int answer = -1;
    for(int i=0; i<n; i++) {
        answer = max(answer, idx[i]+revidx[i]);
    }
    cout<<answer-1;
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

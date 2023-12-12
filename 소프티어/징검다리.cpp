#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int bucketsize = 3e3;
int n;
int arr[bucketsize];
vector<pair<int,int>> v;

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
}

bool comp(pair<int,int> a, pair<int,int> b) {
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}

void solution() {
    v.push_back({arr[0],1});
    int answer = 0;
    for(int i=1; i<n; i++) {
        int now = arr[i];
        int count = 1;
        sort(v.begin(), v.end(), comp);
        for(auto vv:v) {
            if(vv.first < now) {
                count = vv.second + 1;
                break;
            }
        }
        v.push_back({now,count});
    }
    for(auto vv:v) {
        answer = max(answer, vv.second);
    }
    cout<<answer;
}

void solve() {
    input();
    solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}

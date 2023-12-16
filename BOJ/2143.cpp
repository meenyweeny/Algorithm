#include<iostream>
#include<vector>
using namespace std;

int t,n,m;
vector<int> a,b;
int arr[1001], brr[1001];

void input() {
    cin>>t;
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    cin>>m;
    for(int i=1; i<=m; i++) {
        cin>>brr[i];
        brr[i]+=brr[i-1];
    }
}

void make_arr() {
    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            a.push_back(arr[i]-arr[j]);
        }
    }
    for(int i=1; i<=m; i++) {
        for(int j=0; j<i; j++) {
            b.push_back(brr[i]-brr[j]);
        }
    }
}

void solution() {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    unsigned long long answer = 0;
    for(auto x:a) {
        int index = lower_bound(b.begin(), b.end(), t-x) - b.begin();
        int count = lower_bound(b.begin(), b.end(), t-x+1) - b.begin();
        answer += (count-index);
    }
    cout<<answer;
}

void solve() {
    input();
    make_arr();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

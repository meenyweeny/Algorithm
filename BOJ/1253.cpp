#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> arr;

void input() {
    cin>>n;
    arr.resize(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
}

void solution() {
    int answer = 0;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++) {
        int now = arr[i];
        int left = 0;
        int right = n-1;
        while(left<right) {
            if(left==i) {
                ++left;
                continue;
            }
            if(right==i) {
                --right;
                continue;
            }
            int sum = arr[left]+arr[right];
            if(sum>now) {
                --right;
            } else if(sum<now) {
                ++left;
            } else {
                ++answer;
                break;
            }
        }
    }
    cout<<answer;
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

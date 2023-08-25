#include<iostream>
using namespace std;

const int sz = 1e6;
int n,m;
int arr[sz];

void input() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
}

unsigned long long get_length(unsigned long long cut) {
    unsigned long long ret = 0;
    for(int i=0; i<n; i++) {
        if(arr[i]<=cut) {
            ret += 0;
        } else {
            ret += (arr[i]-cut);
        }
    }
    return ret;
}

void solution() {
    sort(arr,arr+n);
    unsigned long long start = 1;
    unsigned long long end = arr[n-1];
    unsigned long long answer = 0;
    while(start<=end) {
        unsigned long long mid = (start+end)/2;
        unsigned long long length = get_length(mid);
        if(length>=m) {
            start = mid+1;
            answer = max(answer,mid);
        } else {
            end = mid-1;
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

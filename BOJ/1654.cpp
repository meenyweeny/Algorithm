#include<iostream>
using namespace std;

const int sz = 1e4;
int n,k;
int arr[sz];

void input() {
    cin>>k>>n;
    for(int i=0; i<k; i++) {
        cin>>arr[i];
    }
}

unsigned long long get_unit(int unit) {
    unsigned long long ret = 0;
    for(int i=0; i<k; i++) {
        ret += (arr[i]/unit);
    }
    return ret;
}

void solution() {
    unsigned long long answer = 0;
    sort(arr,arr+k);
    unsigned int start = 1;
    unsigned int end = arr[k-1];
    while(start<=end) {
        unsigned long long mid = (start + end) / 2;
        unsigned long long unit = get_unit(mid);
        if(unit>=n) {
            answer = max(answer,mid);
            start = mid+1;
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

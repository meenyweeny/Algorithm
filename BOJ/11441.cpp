#include<iostream>
using namespace std;

int n,m;
int arr[100001];

void solve() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    cin>>m;
    int i,j;
    while(m--) {
        cin>>i>>j;
        cout<<arr[j]-arr[i-1]<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

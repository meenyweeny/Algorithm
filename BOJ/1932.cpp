#include<iostream>
using namespace std;

int n;
int arr[500][500];

void solve() {
    cin>>n;
    cin>>arr[0][0];
    for(int i=1; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cin>>arr[i][j];
            if(j==0) {
                arr[i][j] += arr[i-1][j];
            } else {
                arr[i][j] += max(arr[i-1][j-1], arr[i-1][j]);
            }
        }
    }
    int answer = 0;
    for(int i=0; i<n; i++) {
        answer = max(answer,arr[n-1][i]);
    }
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

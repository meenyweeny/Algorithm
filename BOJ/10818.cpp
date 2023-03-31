#include<iostream>
#include<algorithm>
using namespace std;

int mini,maxi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    cin>>n;
    mini = 2e9;
    maxi = -2e9;
    for(int i=0; i<n; i++) {
        cin>>k;
        mini = min(mini,k);
        maxi = max(maxi,k);
    }
    cout<<mini<<' '<<maxi;
}

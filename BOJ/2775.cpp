//
// Created by 이경민 on 2022/10/27.
//
#include<iostream>
using namespace std;

int t,n,k;
int map[15][15];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=1; i<15; i++) map[0][i]=i;
    for(int i=1; i<15; i++) map[i][1]=1;
    for(int i=1; i<15; i++) {
        for(int k=2; k<15; k++) {
            map[i][k] = map[i][k-1] + map[i-1][k];
        }
    }

    cin>>t;
    while(t--) {
        cin >> n >> k;
        cout << map[n][k] << "\n";
    }
}

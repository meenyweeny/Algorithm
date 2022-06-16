//
// Created by 이경민 on 2022/06/16.
//
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[1001];
vector<int> v[1001];
int t, n, ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        v[0].push_back(arr[0]);
        ans = arr[0];
        for (int i = 1; i < n; i++) {
            v[i].push_back(arr[i]);
            ans=max(arr[i],ans);
            for (auto k: v[i - 1]) {
                v[i].push_back(arr[i] + k);
                ans = max(arr[i]+k,ans);
            }
        }
        cout<<ans<<"\n";
        for(int i=0; i<n; i++) v[i].clear();
        memset(arr,0,sizeof(int));
    }
}

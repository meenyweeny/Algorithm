//
// Created by 이경민 on 2023/01/25.
//
#include<iostream>
#include<vector>
using namespace std;

int n;
int arr[1000001];
vector<int> lis;

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
    }
}

void solution() {
    lis.push_back(arr[1]);
    for(int i=2; i<=n; i++) {
        if(arr[i] > lis.back()) {
            lis.push_back(arr[i]);
        } else {
            int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[index] = arr[i];
        }
    }

    cout<<lis.size();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}

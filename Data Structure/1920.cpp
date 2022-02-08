//
//  1920.cpp
//  BOJ
//
//  Created by 이경민 on 2022/02/08.
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int n,m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    while(n--){
        cin>>m;
        v.push_back(m);
    }
    sort(v.begin(),v.end());
    cin>>n;
    while(n--){
        cin>>m;
        cout<<binary_search(v.begin(), v.end(), m)<<"\n";
    }
}

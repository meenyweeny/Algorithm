//
//  1026.cpp
//  BOJ
//
//  Created by 이경민 on 2022/02/06.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
vector<int> b;
int n,k,ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>k;
        a.push_back(k);
    }
    
    for(int i=0; i<n; i++){
        cin>>k;
        b.push_back(k);
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(), b.end());
    
    for(int i=0; i<n; i++){
        ans+=(a[i]*b[i]);
    }
    
    cout<<ans;
}

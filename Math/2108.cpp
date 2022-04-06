//
//  2108.cpp
//  BOJ
//
//  Created by 이경민 on 2022/04/05.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int n,k,sum;
vector<int> v;
int arr[8001];
vector<int> common;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    while(n--){
        cin>>k;
        sum+=k;
        ++arr[k+4000];
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    
    if(sum<0){
        sum*=-1;
        int ans = round((double)sum/v.size());
        if(ans==0) cout<<"0\n";
        else cout<<"-"<<round((double)sum/v.size())<<"\n";
    }
    else {
        cout<<round((double)sum/v.size())<<"\n";
    }
    
    cout<<v[v.size()/2]<<"\n";
    int m = 0;
    
    for(int i=0; i<8001; i++) {
        if(arr[i] > m) {
            m=arr[i];
            common.clear();
            common.push_back(i-4000);
        }
        else if(arr[i] == m){
            common.push_back(i-4000);
        }
    }
    (common.size()==1) ? cout<<common[0]<<"\n" : cout<<common[1]<<"\n";
    cout<<v[v.size()-1] - v[0]<<"\n";
}

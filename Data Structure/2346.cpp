//
//  2346.cpp
//  BOJ
//
//  Created by 이경민 on 2022/02/07.
//

#include<iostream>
#include<deque>
using namespace std;

int n,k;
deque<pair<int,int>> a;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>>k;
        a.push_back({i,k});
    }
    
    k=a.front().second;
    cout<<a.front().first<<" ";
    a.pop_front();
    
    while(!a.empty()){
        pair<int,int> p;
        if(k>0){
            while(k--){
                p=a.front();
                a.pop_front();
                a.push_back(p);
            }
            k=a.back().second;
            cout<<a.back().first<<" ";
            a.pop_back();
        }
        else{
            k*=-1;
            while(k--){
                p=a.back();
                a.pop_back();
                a.push_front(p);
            }
            k=a.front().second;
            cout<<a.front().first<<" ";
            a.pop_front();
        }
    }
}

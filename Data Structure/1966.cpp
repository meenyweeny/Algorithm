//
//  1966.cpp
//  BOJ
//
//  Created by 이경민 on 2022/03/30.
//

#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdlib>
#include<functional>
using namespace std;

int t;
int m,n,ans;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>t;
    
    while(t--){
        
        cin>>n>>m;
        
        ans=0;
        
        queue<pair<int,int>> q; //priority, turn
        priority_queue<int> pq;
        
        for(int i=0; i<n; i++){
            int tmp;
            cin>>tmp;
            q.push(make_pair(tmp,i));
            pq.push(tmp);
        }
        
        
        while(!q.empty()){
            int f=q.front().first;
            if(f!=pq.top()){
                int sf=q.front().first;
                int ss=q.front().second;
                q.pop();
                q.push(make_pair(sf,ss));
                continue;
            }
            else{
                int s=q.front().second;
                if(s==m){
                    cout<<++ans<<"\n";
                    break;
                }
                else{
                    pq.pop();
                    q.pop();
                    ++ans;
                    continue;
                }
            }


        }
    }
}



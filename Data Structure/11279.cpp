//
//  11279.cpp
//  BOJ
//
//  Created by 이경민 on 2022/05/11.
//

#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> pq;
int n,x;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    while(n--){
        cin>>x;
        if (x==0) {
            if(pq.empty()) cout<<"0\n";
            else { cout<<pq.top()<<"\n"; pq.pop();}
            continue;
        }
        pq.push(x);
    }
}

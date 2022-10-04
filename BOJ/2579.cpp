//
//  2579.cpp
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
#include<set>
#include<stack>
using namespace std;

int stair[301];
int score[301];

int n;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>stair[i];
    
    score[1]=stair[1];
    score[2]=stair[1]+stair[2];
    score[3]=max(stair[1],stair[2])+stair[3];
    
    for(int i=4; i<=n; i++){
        score[i]=max(score[i-2],score[i-3]+stair[i-1])+stair[i];
    }
    
    cout<<score[n];
}



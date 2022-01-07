//
//  7568.cpp
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
#include<cstring>
using namespace std;

pair<int,int> info[50];
int n;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>info[i].first>>info[i].second;
    }
    
    for(int i=0; i<n; i++){
        int rank=1;
        for(int k=0; k<n; k++){
            if(info[i].first<info[k].first && info[i].second<info[k].second)
                ++rank;
        }
        cout<<rank<<" ";
    }
}


//
// Created by 이경민 on 2022/06/16.
//
#include<iostream>
#include<algorithm>
using namespace std;

int hor[1025][1025];
int ver[1025][1025];

int n,m,x,xx,y,yy;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int k=1; k<=n; k++){
            cin>>hor[i][k];
            hor[i][k]+=hor[i][k-1];
            ver[i][k] = hor[i][k] + ver[i-1][k];
        }
    }
    while(m--){
        cin>>x>>y>>xx>>yy;
        if(x>xx) swap(x,xx);
        if(y>yy) swap(y,yy);
        cout<<ver[xx][yy]-ver[x-1][yy]-ver[xx][y-1]+ver[x-1][y-1]<<"\n";
    }
}

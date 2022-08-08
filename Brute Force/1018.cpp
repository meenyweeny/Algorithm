//
// Created by 이경민 on 2022/08/08.
//
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n,m;
int answer = 2501;
char ch;
bool map[50][50];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int k=0; k<m; k++) {
            cin>>ch;
            map[i][k] = (ch == 'B');
        }
    }

    int count = 0;
    for(int i=0; i<=n-8; i++){
        for(int k=0; k<=m-8; k++){
            count = 0;
            for(int j=0; j<8; j++){
                for(int x=0; x<8; x++){
                    if(map[i+j][k+x] != ((i+j+k+x)%2 == 0)) ++count;
                }
            }
            answer = min(count,answer);
            count=0;
            for(int j=0; j<8; j++){
                for(int x=0; x<8; x++){
                    if(map[i+j][k+x] == ((i+j+k+x)%2 == 0)) ++count;
                }
            }
            answer = min(count,answer);
        }
    }

    cout<<answer;
}

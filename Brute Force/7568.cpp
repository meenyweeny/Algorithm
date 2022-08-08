//
// Created by 이경민 on 2022/08/08.
//
#include<iostream>
using namespace std;

int n;
int weight[50];
int height[50];

bool comp(int wA,int wB, int hA, int hB) { return wA<wB && hA<hB; }

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++) cin>>weight[i]>>height[i];
    for(int i=0; i<n; i++) {
        int rank = 1;
        for(int k=0; k<n; k++) {
            if(comp(weight[i],weight[k],height[i],height[k])) ++rank;
        }
        cout<<rank<< " ";
    }
}

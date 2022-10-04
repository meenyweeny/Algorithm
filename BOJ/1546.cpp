//
// Created by 이경민 on 2022/08/22.
//
#include<iostream>
#include<algorithm>
using namespace std;

int n,sum,x;
float rat = 101;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>x;
        sum+=x;
        if(float(100/((float)x)) < rat) rat = float(100/((float)x));
    }
    cout<< (float)((float)sum / (float)n)*rat;
}

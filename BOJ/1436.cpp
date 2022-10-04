//
// Created by 이경민 on 2022/08/08.
//
#include<iostream>
using namespace std;

int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    int k=665;
    int count = 0;
    while(1){
        ++k;
        if(to_string(k).find("666") != std::string::npos) ++count;
        if(count==n) break;
    }
    cout<<k;
}

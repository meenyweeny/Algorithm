//
// Created by 이경민 on 2023/01/04.
//
#include<iostream>
#include<algorithm>
using namespace std;

string a,b;

int compare_string(int start, string x, string y) {
    int diff = 0;
    for(int i=start; i<x.length(); i++) {
        diff += (x[i]!=y[i]);
    }
    return diff;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>a>>b;

    if(a.length()==b.length()) {
        cout<<compare_string(0,a,b);
    } else {
        string tmp = a;
        int mini = 100;
        string attach = "";

        while(1) {
            mini = min(mini, compare_string(attach.length(), a,b));
            attach += "a";
            if(a.length() == b.length()) {
                cout<<mini;
                break;
            }
            a = "a" + a;
        }
    }
}

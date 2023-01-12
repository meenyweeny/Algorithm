//
// Created by 이경민 on 2023/01/12.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,h,k;
int bottom[500001];
int top[500001];
vector<int> v;

void input() {
    cin>>n>>h;
    for(int i=0; i<n; i++) {
        cin>>k;
        if(i%2 == 0) {
            ++bottom[k];
        } else {
            ++top[k];
        }
    }
}

void solution() {
    for(int i=h-1; i>=1; i--) {
        bottom[i] += bottom[i+1];
        top[i] += top[i+1];
    }
    for(int i=1; i<=h; i++) {
        v.push_back(bottom[i] + top[h-i+1]);
    }
    sort(v.begin(), v.end());
    int count = 1;
    int height = v[0];
    for(int i=1; i<v.size(); i++) {
        if(v[i]==height) {
            ++count;
        } else {
            break;
        }
    }

    cout<<height<<" "<<count;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}

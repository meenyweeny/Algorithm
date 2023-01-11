//
// Created by 이경민 on 2023/01/11.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<int> tree;
int answer;

void input() {
    cin>>n>>m;
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        tree.push_back(x);
    }
}

void solution() {
    sort(tree.begin(), tree.end());
    int end = tree[tree.size() - 1];
    int start = 0;

    while(start<=end) {
        long long total = 0;
        int mid = (start + end) / 2;
        for(int i=0; i<n; i++) {
            if(tree[i]>mid) {
                total += (tree[i] - mid);
            }
        }
        if(total<m) {
            end = mid - 1;
        } else {
            answer = mid;
            start = mid + 1;
        }
    }
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}

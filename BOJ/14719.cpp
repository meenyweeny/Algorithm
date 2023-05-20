#include<iostream>
#include<vector>
using namespace std;

int h,w;
int v[501];
int answer;

void input() {
    cin>>h>>w;
    for(int i=0; i<w; i++) {
        cin>>v[i];
    }
}

void solution() {
    int left_max,right_max,maxi,gap;
    for(int i=1; i<w-1; i++) {
        left_max = max_element(v, v+i) - v;
        right_max = max_element(v+i+1, v+w) - v;
        maxi = v[left_max] < v[right_max] ? left_max : right_max;
        gap = v[maxi] - v[i];
        answer += gap > 0 ? gap : 0;
    }
    cout<<answer;
}

void solve() {
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

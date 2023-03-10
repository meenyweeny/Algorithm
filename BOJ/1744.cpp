#include<iostream>
#include<vector>
using namespace std;

int answer;
vector<int> pos,neg;
int n;
bool zero;

void input() {
    cin>>n;
    int k;
    for(int i=0; i<n; i++) {
        cin>>k;
        if(k>0) {
            pos.push_back(k);
        } else if(k<0) {
            neg.push_back(k);
        } else {
            zero = true;
        }
    }
}

void solution() {
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    reverse(neg.begin(), neg.end());

    while(!pos.empty()) {
        if(pos.size()>1) {
            int front = pos.back();
            pos.pop_back();
            int back = pos.back();
            pos.pop_back();
            if(front+back < front*back) {
                answer += (front*back);
            } else {
                answer += (front+back);
            }
        } else {
            answer += pos.back();
            pos.pop_back();
        }
    }

    while(!neg.empty()) {
        if(neg.size()>1) {
            int front = neg.back();
            neg.pop_back();
            int back = neg.back();
            neg.pop_back();
            answer += (front*back);
        } else {
            if(zero) {
                neg.pop_back();
            } else {
                answer += neg.back();
                neg.pop_back();
            }
        }
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

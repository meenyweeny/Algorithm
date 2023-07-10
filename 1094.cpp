#include<iostream>
#include<vector>
using namespace std;

int x,init=(1<<6),sum;
vector<int> sticks;

void solve() {
    cin>>x;
    sticks.push_back(init);
    sum+=init;
    while(sum!=x) {
        int top = sticks.back();
        int half = top>>1;
        sticks.pop_back();
        if(sum-half>=x) {
            sticks.push_back(half);
            sum-=half;
        } else {
            sticks.push_back(half);
            sticks.push_back(half);
        }
    }
    cout<<sticks.size();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

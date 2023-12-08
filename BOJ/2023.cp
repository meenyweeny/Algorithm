#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int n;
int big,small;
vector<int> answer;

bool is_prime(int num) {
    int sqr = sqrt(num);
    for(int i=2; i<=sqr; i++) {
        if(!(num%i)) {
            return false;
        }
    }
    return true;
}

void run(int num) {
    if(num>=small && num<big) {
        if(is_prime(num)) {
            answer.push_back(num);
        }
        return;
    }
    if(!is_prime(num)) {
        return;
    }
    for(int i=1; i<10; i++) {
        run(num*10+i);
    }
}

void solve() {
    cin>>n;
    big = pow(10,n);
    small = big/10;
    for(auto i : {2,3,5,7}) {
        run(i);
    }
    for(auto a:answer) {
        cout<<a<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

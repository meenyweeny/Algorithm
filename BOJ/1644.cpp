#include<iostream>
#include<deque>
using namespace std;

bool prime[4000001];
int n;
deque<int> dq;
int answer;

void init() {
    for(int i=2; i<=2000; i++) {
        if(prime[i]) {
            continue;
        }
        for(int j=2; j*i<=4000000; j++) {
            prime[i*j] = true;
        }
    }
}

void solution() {
    int sum = 0;
    for(int i=2; i<=n; i++) {
        if(sum>n) {
            while(1) {
                if(sum<=n) {
                    break;
                }
                sum -= dq.front();
                dq.pop_front();
            }
        }
        if(!prime[i]) {
            if(sum==n) {
                ++answer;
            }

            dq.push_back(i);
            sum += i;
        }
    }
    while(!dq.empty()) {
        if(sum==n) {
            ++answer;
        }
        sum -= dq.front();
        dq.pop_front();
    }
    cout<<answer;
}

void solve() {
    cin>>n;
    init();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

#include<iostream>
using namespace std;

int x;

void solve() {
    cin>>x;

    int top,bottom;

    int mid = 0;
    int all = 0;
    bool flag = true;

    while(1) {
        if(all>=x) {
            break;
        }
        all += (1 + 4*mid);
        ++mid;
    }

    --mid;
    int middle = 2*mid + 1;
    top = 1;
    while(1) {
        if(all==x) {
            break;
        }

        if(flag) {
            ++top;
            --all;
        } else {
            --top;
            --all;
        }

        if(top==middle) {
            flag = !flag;
        }
    }

    flag = true;

    all=mid=0;
    while(1) {
        if(all>=x) {
            break;
        }
        all += (3 + 4*mid);
        ++mid;
    }

    --mid;
    middle = 2*mid + 2;
    bottom = 1;
    while(1) {
        if(all==x) {
            break;
        }

        if(flag) {
            ++bottom;
            --all;
        } else {
            --bottom;
            --all;
        }

        if(bottom == middle) {
            flag = !flag;
        }
    }

    cout<<top<<'/'<<bottom;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

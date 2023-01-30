//
// Created by 이경민 on 2023/01/30.
//
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int n;
vector<int> san;
vector<int> al;

void input() {
    cin>>n;
    int k;
    for(int i=0; i<n; i++) {
        cin>>k;
        if(k<0) {
            al.push_back(k);
        } else {
            san.push_back(k);
        }
    }

}

void solution() {
    sort(al.begin(), al.end());
    sort(san.begin(), san.end());

    if(san.size() == 0) {
        cout<<al[al.size()-2]<<' '<<al[al.size()-1];
    } else if(al.size() == 0) {
        cout<<san[0]<<' '<<san[1];
    } else {
        int ans1, ans2;
        ans1 = ans2 = 1e9 + 1;
        if(san.size()>1) {
            ans1 = san[0];
            ans2 = san[1];
        }
        if(al.size()>1) {
            if(ans1 + ans2 > abs(al[al.size()-2] + al[al.size()-1])) {
                ans1 = al[al.size()-2];
                ans2 = al[al.size()-1];
            }
        }

        int maxi = 2e9 + 2;
        maxi = min(abs(ans1 + ans2), maxi);
        maxi = abs(maxi);

        int san_size = san.size();
        int san_front,al_front,idx;
            for(int i=0; i<san_size; i++) {
                san_front = san[i];
                idx = lower_bound(al.begin(), al.end(), -san_front) - al.begin();
                al_front = al[idx];
                if(al_front==0) {
                    al_front = -2e9;
                }
                if(maxi > abs(san_front + al_front)) {
                    ans2 = san_front;
                    ans1 = al_front;
                    maxi = abs(ans1 + ans2);
                }
                if(idx!=0) {
                    al_front = al[idx-1];
                    if(maxi > abs(san_front + al_front)) {
                        ans2 = san_front;
                        ans1 = al_front;
                        maxi = abs(ans1 + ans2);
                    }
                }
                if(maxi == 0) {
                    break;
                }
            }
            if(ans1 > ans2) {
                swap(ans1, ans2);
            }
            cout<<ans1<<' '<<ans2;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}

#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<cstring>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>
using namespace std;

int n, t;
bool swit[101];
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> swit[i];
    cin >> t;
    int gender, switnum;
    while (t--) {
        cin >> gender >> switnum;

        if (gender == 1) {
            int cnt = 1;
            while (switnum * cnt <= n) {
                swit[switnum * cnt] = !swit[switnum * cnt];
                ++cnt;
            }
        }
        else {
            int x = switnum - 1;
            int y = switnum + 1;
            v.clear();

            bool flag = true;
            if (x<1 || y>n) {
                flag = false;
            }

            v.push_back(switnum);

            while (flag) {
                if (x<1 || y>n) {
                    flag = false;
                    continue;
                }
                if (swit[x] != swit[y]) {
                    flag = false;
                    continue;
                }
                v.push_back(x);
                v.push_back(y);
                --x;
                ++y;
            }

            for (int i = 0; i < v.size(); i++) {
                swit[v[i]] = !swit[v[i]];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << swit[i] << " ";
        if (i % 20 == 0)
            cout << "\n";
    }
}

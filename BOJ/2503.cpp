#include<iostream>
#include<vector>
using namespace std;

int answer;
vector<pair<int,pair<int,int>>> v;
int x_pos[10];

void input() {
    int n;
    cin>>n;
    int k,s,b;
    while(n--) {
        cin>>k>>s>>b;
        v.push_back({k,{s,b}});
    }
}

void fill_x(int x) {
    fill(x_pos,x_pos+10,0);
    int count = 1;
    while(x>0) {
        x_pos[x%10] = count;
        x/=10;
        ++count;
    }
}

bool check_right(int x,int s,int b) {
    int count = 1;
    int ball,strike;
    ball=strike=0;
    while(x>0) {
        if(x_pos[x%10]==count) {
            ++strike;
        } else if(x_pos[x%10]>0) {
            ++ball;
        }
        ++count;
        x/=10;
    }
    return s==strike && b==ball;
}

bool check() {
    bool flag = true;
    for(auto now:v) {
        flag &= check_right(now.first,now.second.first,now.second.second);
    }
    return flag;
}

bool is_valid(int x) {
    string str = to_string(x);
    return str[0]!=str[1] && str[1]!=str[2] && str[0]!=str[2] && str[0]!='0'  && str[1]!='0' && str[2]!='0';
}

void solution() {
    for(int i=123; i<1000; i++) {
        if(!is_valid(i)) {
            continue;
        }
        fill_x(i);
        answer += check();
    }
}

void solve() {
    input();
    solution();
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

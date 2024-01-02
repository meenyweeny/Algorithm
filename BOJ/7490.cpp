#include<iostream>
#include<queue>
using namespace std;

int n;

int calc(string str) {
    int sum = 0;
    int before = 0;
    queue<int> st;
    queue<char> cal;
    for(int i=0; i<str.size(); i++) {
        char c = str[i];
        if(c>'0' && c<='9') {
            before = 0;
            before += (c-'0');
            while(1) {
                if(i+1<str.size() && str[i+1]==' ') {
                    i += 2;
                    before *= 10;
                    before += (str[i] - '0');
                } else {
                    break;
                }
            }
            st.push(before);
        } else if(c=='+' || c=='-') {
            cal.push(c);
        }
    }
    sum = st.front();
    st.pop();
    while(!st.empty() && !cal.empty()) {
        if(cal.front()=='+') {
            sum += st.front();
        } else {
            sum -= st.front();
        }
        st.pop();
        cal.pop();
    }
    return sum;
}

void run(int before,string str) {
    int now = before + 1;
    str += to_string(now);
    if(now==n) {
        int sum = calc(str);
        if(sum==0) {
            cout<<str<<'\n';
        }
        return;
    }
    run(now,str+' ');
    run(now,str+'+');
    run(now,str+'-');
}

void solve() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        run(0,"");
        cout<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
    return 0;
}

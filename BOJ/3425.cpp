#include<iostream>
#include<vector>
using namespace std;

int n;
vector<string> program;
vector<long long> st;
vector<long long> nums;

bool check_result(long long result) {
    return abs(result) <= 1e9;
}

void process() {
    cin>>n;
    int k;
    long long cal = 0;
    int num_index;
    bool abnormal;
    while(n--) {
        cin>>k;
        st.push_back(k);
        num_index = 0;
        abnormal = false;
        for(auto p:program) {
            if(abnormal) {
                break;
            }
            if(p=="POP") {
                if(st.empty()) {
                    abnormal = true;
                } else {
                    st.pop_back();
                }
            } else if(p=="INV") {
                if(st.empty()) {
                    abnormal = true;
                } else {
                    long long tmp = st.back();
                    st.pop_back();
                    st.push_back(-tmp);
                }
            } else if(p=="DUP") {
                if(st.empty()) {
                    abnormal = true;
                } else {
                    st.push_back(st.back());
                }
            } else if(p=="SWP") {
                if(st.size()<2) {
                    abnormal = true;
                } else {
                    long long a = st.back();
                    st.pop_back();
                    long long b = st.back();
                    st.pop_back();
                    st.push_back(a);
                    st.push_back(b);
                }
            } else if(p=="ADD") {
                if(st.size()<2) {
                    abnormal = true;
                } else {
                    long long a = st.back();
                    st.pop_back();
                    long long b = st.back();
                    st.pop_back();
                    cal = a+b;
                    if(!check_result(cal)) {
                        abnormal = true;
                    } else {
                        st.push_back(cal);
                    }
                }
            } else if(p=="SUB") {
                if(st.size()<2) {
                    abnormal = true;
                } else {
                    long long a = st.back();
                    st.pop_back();
                    long long b = st.back();
                    st.pop_back();
                    cal = b - a;
                    if(!check_result(cal)) {
                        abnormal = true;
                    } else {
                        st.push_back(cal);
                    }
                }
            } else if(p=="MUL") {
                if(st.size()<2) {
                    abnormal = true;
                } else {
                    long long a = st.back();
                    st.pop_back();
                    long long b = st.back();
                    st.pop_back();
                    cal = b * a;
                    if(!check_result(cal)) {
                        abnormal = true;
                    } else {
                        st.push_back(cal);
                    }
                }
            } else if(p=="DIV") {
                if(st.size()<2 || !st.back()) {
                    abnormal = true;
                } else {
                    long long a = st.back();
                    st.pop_back();
                    long long b = st.back();
                    st.pop_back();
                    int sign = 1;
                    if((a>0 && b<0) || (a<0 && b>0)) {
                        sign = -1;
                    }
                    a = abs(a); b = abs(b);
                    cal = b/a;
                    if(!check_result(cal)) {
                        abnormal = true;
                    } else {
                        st.push_back(cal * sign);
                    }
                }
            } else if(p=="MOD") {
                if(st.size()<2 || !st.back()) {
                    abnormal = true;
                } else {
                    long long a = st.back();
                    st.pop_back();
                    long long b = st.back();
                    st.pop_back();
                    int sign = b < 0 ? -1 : 1;
                    a = abs(a); b = abs(b);
                    cal = b%a;
                    if(!check_result(cal)) {
                        abnormal = true;
                    } else {
                        st.push_back(cal * sign);
                    }
                }
            } else { //NUM
                st.push_back(nums[num_index++]);
            }
        }

        if(st.size()!=1 || abnormal) {
            cout<<"ERROR";
        } else {
            cout<<st.back();
        }
        cout<<'\n';
        st.clear();
    }

    program.clear();
    nums.clear();
    cout<<endl;
}

void solve() {
    string cmd;
    int k;
    while(1) {
        cin>>cmd;
        if(cmd=="QUIT") {
            break;
        }
        if(cmd=="END") {
            process();
            continue;
        } else if(cmd=="NUM") {
            cin>>k;
            nums.push_back(k);
        }
        program.push_back(cmd);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

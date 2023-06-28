#include<iostream>
#include<cmath>
using namespace std;

int n,r,c,answer;

void process(int length,int x,int y) {
    if(x==r && y==c) {
        cout<<answer;
        return;
    }
    if(x<=r && x+length>r && y<=c && y+length>c) {
        length/=2;
        process(length,x,y);
        process(length,x,y+length);
        process(length,x+length,y);
        process(length,x+length,y+length);
    } else {
        answer += (length*length);
    }
}

void solve() {
    cin>>n>>r>>c;
    process(pow(2,n),0,0);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

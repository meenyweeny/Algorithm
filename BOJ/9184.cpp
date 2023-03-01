#include<iostream>
using namespace std;

int dp[21][21][21];

int solution(int x,int y,int z) {
    if(x<=0 || y<=0 || z<=0) {
        return 1;
    }
    if(x>20 || y>20 || z>20) {
        return solution(20,20,20);
    }
    if(dp[x][y][z]!=0) {
        return dp[x][y][z];
    }
    if(x<y && y<z) {
        return dp[x][y][z] = solution(x,y,z-1) + solution(x,y-1,z-1) - solution(x,y-1,z);
    }
    return dp[x][y][z] = solution(x-1,y,z) + solution(x-1,y-1,z) + solution(x-1,y,z-1) - solution(x-1, y-1, z-1);
}

void solve() {
    int a,b,c;
    while(1) {
        cin>>a>>b>>c;
        if(a==-1 && b==-1 && c==-1) {
            break;
        }
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<solution(a,b,c)<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}

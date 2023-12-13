#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int bucketsize = 3e5;
int arr[bucketsize];
int n;
vector<int> lis;
int num[bucketsize];

void input() {
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
}

void solution() {
  lis.push_back(arr[0]);
  num[0] = 1;
  for(int i=1; i<n; i++) {
    int now = arr[i];
    int index = 0;
    if(now>lis.back()) {
      lis.push_back(now);
    } else {
      index = lower_bound(lis.begin(), lis.end(), now) - lis.begin();
      lis[index] = now;
    }
    num[i] = lis.size();
  }
  lis.clear();
  lis.push_back(arr[n-1]);
  ++num[n-1];
  for(int i=n-2; i>=0; i--) {
    int now = arr[i];
    int index = 0;
    if(now>lis.back()) {
      lis.push_back(now);
    } else {
      index = lower_bound(lis.begin(), lis.end(), now) - lis.begin();
      lis[index] = now;
    }
    num[i] += lis.size();
  }
  int answer = 2;
  for(int i=0; i<n; i++) {
    answer = max(answer, num[i]);
  }
  --answer;
  cout<<answer;
}

void solve() {
  input();
  solution();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  
  return 0;
}

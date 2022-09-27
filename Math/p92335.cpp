#include <string>
#include <algorithm>

using namespace std;

string converter(int num, int x) {
    string converted = "";
    while (num != 0) {
        converted += ((num % x) + '0');
        num /= x;
    }
    reverse(converted.begin(), converted.end());
    return converted;
}

bool isPrime(string x) {
    if (x == "") {
        return false;
    }
    unsigned long long num = 0;
    reverse(x.begin(), x.end());
    unsigned long long k = 1;
    for (auto i: x) {
        num += ((i - '0') * k);
        k *= 10;
    }
    if (num < 2) {
        return false;
    }
    for (unsigned long long i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string str = converter(n, k);
    string target = "";

    for (auto i: str) {
        if (i == '0') {
            if (isPrime(target)) {
                ++answer;
            }
            target = "";
        } else {
            target += i;
        }
    }
    if (isPrime(target)) {
        ++answer;
    }

    return answer;
}

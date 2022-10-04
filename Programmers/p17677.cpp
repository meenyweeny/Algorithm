#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isAlphabet(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    } else if (c >= 'A' && c <= 'Z') {
        return true;
    } else {
        return false;
    }
}

string make_upper(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> vec1, vec2, inter;

    str1 = make_upper(str1);
    str2 = make_upper(str2);

    for (int i = 0; i < str1.length() - 1; i++) {
        if (!isAlphabet(str1[i])) {
            continue;
        } else {
            if (!isAlphabet(str1[i + 1])) {
                ++i;
            } else {
                vec1.push_back(str1.substr(i, 2));
            }
        }
    }

    for (int i = 0; i < str2.length() - 1; i++) {
        if (!isAlphabet(str2[i])) {
            continue;
        } else {
            if (!isAlphabet(str2[i + 1])) {
                ++i;
            } else {
                vec2.push_back(str2.substr(i, 2));
            }
        }
    }

    int intersect = 0;
    int in_a = 0;
    int in_b = 0;

    if (vec1.size() == 0 && vec2.size() == 0) {
        answer = 65536;
    } else if (vec1.size() <= vec2.size()) {
        for (auto i: vec1) {
            in_a = in_b = 0;
            if (find(inter.begin(), inter.end(), i) != inter.end()) {
                continue;
            }
            for (auto k: vec1) {
                if (k == i) {
                    ++in_a;
                }
            }
            for (auto k: vec2) {
                if (k == i) {
                    ++in_b;
                }
            }
            if (in_a != 0 && in_b != 0) {
                inter.push_back(i);
                intersect += min(in_a, in_b);
            }
        }
        answer = floor(((double) ((double) (intersect) / (double) (vec1.size() + vec2.size() - intersect))) * 65536);
    } else {
        for (auto i: vec2) {
            in_a = in_b = 0;
            if (find(inter.begin(), inter.end(), i) != inter.end()) {
                continue;
            }
            for (auto k: vec1) {
                if (k == i) {
                    ++in_a;
                }
            }
            for (auto k: vec2) {
                if (k == i) {
                    ++in_b;
                }
            }
            if (in_a != 0 && in_b != 0) {
                inter.push_back(i);
                intersect += min(in_a, in_b);
            }
        }
        answer = floor(((double) ((double) (intersect) / (double) (vec1.size() + vec2.size() - intersect))) * 65536);
    }
    return answer;
}

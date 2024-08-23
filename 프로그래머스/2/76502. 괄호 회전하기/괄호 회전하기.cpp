#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool check(string s) {
    stack<char> st;
    bool isOk = true;
    for (const auto ch : s) {
        if (ch == ']') {
            if (st.top() == '[') {
                st.pop();
            }
            else {
                isOk = false;
                break;
            }
        }
        else if (ch == ')') {
            if (st.top() == '(') {
                st.pop();
            }
            else {
                isOk = false;
                break;
            }
        }
        else if (ch == '}') {
            if (st.top() == '{') {
                st.pop();
            }
            else {
                isOk = false;
                break;
            }
        }
        else {
            st.push(ch);
        }
    }
    if (!st.empty()) isOk = false;
    return isOk;
}

int solution(string s) {
    int answer = 0;
    string ss = s + s;
    for (int i = 0; i < s.size(); i++) {
        if (check(ss.substr(i, s.size()))) answer++;
    }
    
    return answer;
}
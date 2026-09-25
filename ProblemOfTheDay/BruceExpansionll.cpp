#include <bits/stdc++.h>
using namespace std;

class Solution {
    string expression;
    int idx;

    set<string> expr();

    set<string> item() {
        set<string> ret;

        if (expression[idx] == '{') {
            idx++;
            ret = expr();
        } 
        else {
            ret.insert(string(1, expression[idx]));
        }

        idx++;
        return ret;
    }

    set<string> term() {
        set<string> ret;
        ret.insert("");

        while (idx < expression.size() &&
               (expression[idx] == '{' || isalpha(expression[idx]))) {

            set<string> sub = item();
            set<string> temp;

            for (auto &left : ret) {
                for (auto &right : sub) {
                    temp.insert(left + right);
                }
            }

            ret = temp;
        }

        return ret;
    }

    set<string> expr() {
        set<string> ret;

        while (true) {
            set<string> temp = term();

            for (auto &x : temp) {
                ret.insert(x);
            }

            if (idx < expression.size() && expression[idx] == ',') {
                idx++;
            } 
            else {
                break;
            }
        }

        return ret;
    }

public:
    vector<string> braceExpansionII(string expression) {
        this->expression = expression;
        this->idx = 0;

        set<string> ret = expr();

        return vector<string>(ret.begin(), ret.end());
    }
};
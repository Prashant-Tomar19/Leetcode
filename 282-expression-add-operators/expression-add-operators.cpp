class Solution {
public:
    vector<string> ans;

    void solve(string &num, int target, int index, string expr,
               long long value, long long last) {

        if (index == num.size()) {
            if (value == target)
                ans.push_back(expr);
            return;
        }

        long long cur = 0;
        string part = "";

        for (int i = index; i < num.size(); i++) {

            if (i > index && num[index] == '0')
                break;

            part.push_back(num[i]);
            cur = cur * 10 + (num[i] - '0');

            if (index == 0) {
                solve(num, target, i + 1, part, cur, cur);
            } else {

                solve(num, target, i + 1,
                      expr + "+" + part,
                      value + cur,
                      cur);

                solve(num, target, i + 1,
                      expr + "-" + part,
                      value - cur,
                      -cur);

                solve(num, target, i + 1,
                      expr + "*" + part,
                      value - last + last * cur,
                      last * cur);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, "", 0, 0);
        return ans;
    }
};
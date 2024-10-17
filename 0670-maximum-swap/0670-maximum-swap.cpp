class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        while (num != 0) {
            int digit = num % 10;
            digits.push_back(digit);
            num = num / 10;
        }
        reverse(digits.begin(), digits.end());
        vector<int> temp;
        for (auto x : digits) {
            temp.push_back(x);
        }
        sort(temp.begin(), temp.end(), greater<int>());
        map<int, int> mp;
        for (int i = 0; i < digits.size(); i++) {
            mp[digits[i]] = i;
        }
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] != temp[i]) {
                swap(digits[i], digits[mp[temp[i]]]);
                break;
            }
        }
        int ans = 0;
        int count = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            ans += digits[i] * pow(10, count++);
        }
        return ans;
    }
};
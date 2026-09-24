class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" or num2 == "0")
            return "0";

        if (num1.size() < num2.size())
            swap(num1, num2);
        
        int m = num1.size();
        int n = num2.size();

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int carry = 0;
        string res = "";

        for (int i = 0; i < m + n - 1; i++){
            //cout << "begin iter\n";
            int l = max(0, i - m + 1);
            int r = min(i + 1, n);
            for (int j = l; j < r; j++){
                int c1 = (int)(num2[j] - '0');
                int c2 = (int)(num1[i - j] - '0');
                carry += c1 * c2;
                //cout << c1 << ' ' << c2 << '\n';
            }
            //cout << carry << '\n';
            char a = (char)('0' + carry % 10);
            carry /= 10;
            res += a;
        }

        reverse(res.begin(), res.end());
        if (carry)
            res = to_string(carry) + res;
        return res;
    }
};

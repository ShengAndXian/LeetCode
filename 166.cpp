class Solution {
    public:
        string fractionToDecimal(int numerator, int denominator) {
            if (!denominator)
                return "0";
            
            string res;

            if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
                res += "-";
            
            long long num = abs(long long numerator);
            long long den = abs((long long)denominator);

            res += to_string(num / den);
            num = num % den;

            if (!num)
                return res;
            
            res += ".";
            map<long long, long long> m;

            while (num) {
                num *= 10;

                if (m.find(num) != m.end()) {
                    res.insert(m[num], 1, '(');
                    res += ")";
                    break;
                }

                m[num] = res.size();
                res += to_string(num / den);
                num = num % den;
            }

            return res;
        }
};
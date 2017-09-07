class Solution {
    public:
        double myPow(double x, int n) {
            if (n == 0)
                return 1;

            if (n < 0)
                return 1 / (x * myPow(x, -(n + 1)));

            if (n % 2 == 0) {
                double t = myPow(x, n / 2);

                return t * t;
            } else {
                double t = myPow(x, (n - 1) / 2);

                return x * t * t;
            }
        }
};
class Solution {
    public:
        void reverseWords(string &s) {
            deleteSpace(s, 0);
            reverse(s.begin(), s.end());
            deleteSpace(s, 0);

            for (int i = 0;i < s.length();i++) {
                if (s[i] == ' ')
                    deleteSpace(s, i + 1);
            }
            
            int start = 0;
            int end = 0;

            while (end < s.length()) {
                while (end < s.length() && s[end] != ' ')
                    end++;

                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
                end = start;
            }
        }

        void deleteSpace(string& s, int start) {
            int i = 0;

            while (start + i < s.length() && s[start + i] == ' ')
                i++;
            
            s.replace(start, i, "");
        }
};
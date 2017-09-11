class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            vector<int> visited(wordList.size(), 0);
            queue<string> q;
            int length = 0;

            q.push(beginWord);

            while (!q.empty()) {
                length++;

                int num = q.size();

                for (int i = 0;i < num;i++) {
                    string s = q.front();
                    q.pop();

                    for (int j = 0;j < wordList.size();j++) {
                        if (visited[j] == 0 && cmp(s, wordList[j]) == 1) {
                            if (wordList[j] == endWord)
                                return length + 1;

                            q.push(wordList[j]);
                            visited[j] = 1;
                        }
                    }
                }
            }

            return 0;
        }

        int cmp(string s1, string s2) {
            int res = 0;

            for (int i = 0;i < s1.length();i++)
                if (s1[i] != s2[i])
                    res++;
            
            return res;
        }
};
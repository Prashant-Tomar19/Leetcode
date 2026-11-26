class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string,int> mp;
        int ans = 0;

        if(beginWord == endWord) return 1;

        for(int i = 0; i < n; i++) {
            mp[wordList[i]]++;
        }

        if(mp[endWord] == 0) return 0;

        bfs(beginWord, ans, mp, endWord);
        return ans;
    }

    void bfs(string node, int &ans, unordered_map<string,int> &mp, string endWord) {
        queue<string> q;
        ans = 1;
        q.push(node);
        mp[node]--;

        while(!q.empty()) {
            int size = q.size();

            for(int j = 0; j < size; j++) {
                string word = q.front();
                q.pop();

                for(int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for(char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;

                        if(mp[word] == 1) {
                            if(word == endWord) {
                                ans++;
                                return;
                            }

                            q.push(word);
                            mp[word]--;
                        }
                    }

                    word[i] = original;
                }
            }

            ans++;
        }

        ans = 0;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";

        // Extract all words
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                word.push_back(s[i]);
            } else {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            }
        }

        // Store the last word
        if (!word.empty()) {
            words.push_back(word);
        }

        // Build the answer in reverse order
        string ans = "";

        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];

            if (i != 0) {
                ans += " ";
            }
        }

        return ans;
    }
};
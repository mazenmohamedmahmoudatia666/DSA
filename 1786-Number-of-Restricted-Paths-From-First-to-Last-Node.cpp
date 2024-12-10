class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> s;
        for (char& c : allowed) {
            s.insert(c);
        }

        int cnt = 0;
        for (int i = 0; i < words.size(); i++) {
            bool is_consistent = true;
            for (char &k : words[i]) {
                if (s.find(k) == s.end()) {
                    is_consistent = false;
                    break;  // No need to check further if a character is not allowed
                }
            }
            if (is_consistent) cnt++;
        }

        return cnt;
    }
};

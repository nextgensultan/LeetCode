class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        unordered_map<char, int> count;
        set<int> scount;
        for (int i = 0; i < n; i++) {
            if (count.find(s[i]) == count.end())
                count[s[i]] = 0;
            count[s[i]]++;
        }
        int result = 0;
        int cur = count.size();
        for (int i = 0; i < n - 1; i++) {
            scount.insert(s[i]);
            count[s[i]]--;
            if (count[s[i]] == 0)
                cur--;
            if (scount.size() == cur)
                result++;
        }
        return result;
    }
};
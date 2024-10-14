#pragma GCC optimize("Ofast")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = []() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

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
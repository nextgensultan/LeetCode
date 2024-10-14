#pragma GCC optimize("Ofast")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = []() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class Solution {
public:
    long long countVowels(string word) {
        int n = word.size();
        long long result = 0;
        for (int i = 0; i < n; i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                word[i] == 'o' || word[i] == 'u')
                result += (long long)1 * (i + 1) * (n - i);
        }
        return result;
    }
};
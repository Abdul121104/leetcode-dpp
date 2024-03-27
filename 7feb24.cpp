class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> f;
        for (char c : s) {
            f[c]++;
        }
        auto compare = [&](char a, char b) {
            return f[a]>f[b]||(f[a]==f[b]&&a<b);
        };
        sort(s.begin(), s.end(), compare);
        return s;
    }
};

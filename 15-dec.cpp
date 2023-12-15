class Solution {
public:
  string destCity(vector<vector<string>>& paths) {
    unordered_map<string, int> i;
    unordered_map<string, int> o;
    for (const auto& p : paths) {
      o[p[0]]++;
      i[p[1]]++;
    }
    for (const auto& e: i) {
      if (i[e.first] == 1 && o[e.first] == 0){
        return e.first;
      }
    }
    return "";
  }
};

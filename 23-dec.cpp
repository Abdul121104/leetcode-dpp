class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int> visited;
        visited[{0,0}] = 1;
        int x=0,y=0;
        for (char dir : path) {
            switch (dir) {
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
            }
            if (visited[{x, y}]> 0) {
                return true;
            }
            visited[{x, y}] = 1;
        }
        return false;
    }
};

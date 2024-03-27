class Solution {
// private:
//     int solve(int index, vector<int>& h, int bricks, int ladders){
//         if(index == h.size()-1) return 0;
//         if(h[index] >= h[index+1]){
//             return 1 + solve(index+1, h, bricks, ladders);
//         }
//         else{
//             int diff = h[index+1]-h[index];
//             int b = 0, l = 0;
//             if(bricks >= diff){
//                 b = 1 + solve(index+1, h, bricks-diff, ladders);
//             }
//             if(ladders > 0){
//                 l = 1 + solve(index+1, h, bricks, ladders-1);
//             }
//             return max(b, l);
//         }
//     }
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders){
        priority_queue<int> maxBricks;
        int i = 0, diff = 0; 
        for (i = 0; i < heights.size() - 1; i++) { 
            diff = heights[i + 1] - heights[i];
            if (diff <= 0) {
                continue;
            }
            // if(bricks -= diff>=0) bricks -= diff
            bricks -= diff; 
            maxBricks.push(diff); 
            if (bricks < 0) {
                bricks += maxBricks.top(); 
                maxBricks.pop(); 
                ladders--; 
            }
            if (ladders < 0) {
                break;
            }
        }

        return i;
    }
    }
};

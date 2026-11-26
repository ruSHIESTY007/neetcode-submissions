class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Start from edges and figure out the current max..
        // do this by finding the min of both elements and multiplying times the distance (do math for this)
        // keep track and move edge pointers towards teh middle based on which "next" value is bigger.. do ts until they overlap
        // once we get to a point where there are no adjacent bigger ones then give up

        int max = 0, l = 0, r = heights.size() - 1;
        while (l < r) {
            int rH = heights[r];
            int lH = heights[l];
            int curr = (r - l)*min(rH, lH);
            max = curr > max ? curr : max;

            if (lH > rH) {
                r--;
            } else {
                l++;
            }

        }
        return max;
        
    }
};

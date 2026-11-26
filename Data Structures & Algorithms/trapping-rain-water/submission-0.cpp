class Solution {
public:
    int trap(vector<int>& height) {
        // Find maxes coming from left to right
        // find maxes coming from right to left
        // keep track as you go
        int l = 0;
        int fill = 0;
        vector<int> maxPoint = {l, height[l], fill};

        while (l < height.size()) {
            int curr = height[l];
            if (curr >= maxPoint[1]) {
                maxPoint = {l,curr,fill};
            }
            // When we hit the max again ... we store loc and how much
            // we've filled
            fill += maxPoint[1] - curr;
            l++;
        }

        int r = height.size() - 1;
        int fillR = 0;
        int maxR = 0;
        while (r > maxPoint[0]) {
            int curr = height[r];
            maxR = curr > maxR ? curr : maxR;
            fillR += maxR - curr;
            r--;
        }

        return fillR + maxPoint[2];
    }
};

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // Using priority queue approach
        priority_queue<int> pq;

        for (int i = 0; i < heights.size() - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0)
                pq.push(
                    -diff); // Push negative of height difference for max heap

            if (pq.size() > ladders) { // If number of elements in pq exceed
                                       // available ladders
                bricks += pq.top();    // Add the largest difference to bricks
                pq.pop();              // Remove the largest difference from pq
            }

            if (bricks < 0)
                return i; // Return furthest index reached if bricks become
                          // negative
        }

        return heights.size() -
               1; // Return last index if all buildings can be reached
    }
};

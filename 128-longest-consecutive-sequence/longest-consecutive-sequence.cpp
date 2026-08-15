class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> map(nums.begin(), nums.end());
        int longest = 0;
        for (int num : map) {
            if (map.find(num-1) == map.end()) {
                int current = num;
                int streak = 1;
                while (map.find(current+1) != map.end()) {
                    current++;
                    streak++;
                }
                longest = max(streak, longest);
            }
        }
        return longest;
    }
};
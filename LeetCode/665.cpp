// https://leetcode.com/problems/non-decreasing-array/

// Method 1 (Greedy, O(n)):

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool fixed_once = 0;
        for(int i = 0; i<nums.size()-1; i++){
            if(!fixed_once and nums[i] > nums[i+1]){
                fixed_once = 1;
                // fix one time
                if(i == 0 or nums[i-1] <= nums[i+1]){
                    nums[i] = nums[i+1];
                } else {
                    nums[i+1] = nums[i];
                }
            }
        }
        
        // check
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]) return 0;
        }
        return 1;
    }
};

// Method 2 (Greedy, Trial and Error, O(n)):

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int neg = 0, index = -10, i, prev, n = nums.size();
        for(i = 0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                if(neg) return 0;
                neg++;
                index = i;
            }
        }
        
        prev = INT_MIN;
        for(i = 0; i<n; i++){
            if(i == index) continue;
            if(prev > nums[i]) break;
            prev = nums[i];
        }
        if(i == n) return 1;
        
        prev = INT_MIN;
        for(i = 0; i<n; i++){
            if(i == index+1) continue;
            if(prev > nums[i]) break;
            prev = nums[i];
        }
        if(i == n) return 1;
        
        return 0;
    }
};
class Solution {
public:
    int k = 0;
    int countsets(int i, vector<int>& nums, vector<int>& cur) {
        if(i==nums.size())
        {
            return int(bool(cur.size()));
        }
        int res = 0;
        int val1 = nums[i] + k, val2 = nums[i] - k;
        
        if (binary_search(cur.begin(), cur.end(), val1) == false &&
            binary_search(cur.begin(), cur.end(), val2) == false ) {
                cur.push_back(nums[i]);
                res+=countsets(i+1,nums,cur);
                cur.pop_back();
        }
        res+=countsets(i+1,nums,cur);
        return res;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        this->k = k;
        sort(nums.begin(), nums.end());
        vector<int> init = {nums[0]}, init2 = {};
        return countsets(1, nums, init) + countsets(1, nums, init2);
    }
};
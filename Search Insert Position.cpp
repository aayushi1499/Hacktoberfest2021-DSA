    int searchInsert(vector<int>& nums, int target) {
        //return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        
         int low = 0, high = nums.size()-1;

        // Invariant: the desired index is between [low, high+1]
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }

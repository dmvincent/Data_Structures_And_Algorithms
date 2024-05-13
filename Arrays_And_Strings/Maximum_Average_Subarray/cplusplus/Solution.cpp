#include <vector>
#include <iostream>

//class Solution {
//public:
//    double findMaxAverage(vector<int>& nums, int k) {
//        // Initiate the iterator for 'nums', the value for holding current sum ('curr_sum'), and value for holding the answer, which happens to be the maximum average
//        int i {0}, curr_sum {0};
//        double ans{0};
//
//
//        // Load first k values into subarray
//        for(;i < k; i++) {
//            curr_sum += nums[i];
//        }
//        
//        // Initialize 'ans' with our first possible 'maximum average'
//        ans = double(curr_sum)/k;
//
//        // Cycle through remaining values in 'nums'
//        for(;i < nums.size(); i++) {
//            // From the 'cur_sum' remove the value of element nums[i - k] and add the value of element nums[i]
//            curr_sum += nums[i] - nums[i-k];
//            // Validate the condition
//            if(double(curr_sum)/k > ans)
//                ans = double(curr_sum)/k;
//        }
//        // Return the answer
//        return ans;
// 
//    }
//};

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int i {0}, curr_sum {0};
        double ans{0};
        for(;i < k; i++) {
            curr_sum += nums[i];
        }
        ans = double(curr_sum); 
        for(;i < nums.size(); i++) {
            curr_sum += nums[i] - nums[i-k];
            if(curr_sum > ans)
                ans = double(curr_sum);
        }
        return ans/k;
    }
};



int main() {
    // Provide the input
    int k = 4;
    std::vector<int> nums {1,12,-5,-6,50,3};

    // Create the object
    Solution s1;

    // Call the method
    double ans = s1.findMaxAverage(nums, k);
    std::cout << "Average: " << ans << std::endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        unsigned int count = 0U;
        unsigned int countSorted = 0U;
        unsigned int numsSize = nums.size();

        vector<int> numsSorted(numsSize);

        for (int& num : nums)
        {
            
            if(num != val)
            {
                numsSorted[countSorted] = num;
                countSorted++;
            }
            ++count;
        }
        nums = numsSorted;
        return countSorted;
    }
};


int main()
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    Solution solution;

    int result = solution.removeElement(nums, val);

    cout << "countSorted or K: " << result << endl; 
}

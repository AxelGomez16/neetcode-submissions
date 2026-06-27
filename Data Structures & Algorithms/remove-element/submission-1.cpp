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
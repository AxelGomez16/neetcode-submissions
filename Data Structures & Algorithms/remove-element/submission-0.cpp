class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        unsigned int k = 0U;
        unsigned int count = 0U;
        vector<int> nums_(nums.size());
        // std::cout << count << endl;

        for (int& num : nums)
        {
            
            if(num != val)
            {
                k++;
                std::cout << "if count: " << count << endl;
                std::cout << "if num: " << num << "\n" << endl;
//                nums[count] = num;

            }
            else
            {
                std::cout << "else count: " << count << endl;
                std::cout << "else num: " << num << "\n" << endl;
                nums[count] = 0;
            }
            ++count;
            // std::cout << count << endl; nums=[0,1,2,2,3,0,4,2] val=2


        }

        return k;
    }
};
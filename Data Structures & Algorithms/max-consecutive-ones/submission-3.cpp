#include <iostream>
#include <vector>

using namespace std;


class Solution
{
    public:
        unsigned int ONE  = 1U;
        unsigned int ZERO = 0U;

        int findMaxConsecutiveOnes(vector<int>& nums)
        {
            unsigned int streak_1   = 0U;
            unsigned int streak_max = 0U;
            for (const auto& num : nums)
            {
                if (num == ONE)
                {
                    streak_1 += 1;
                }
                else
                {
                    if (streak_1 >= streak_max)
                    {
                        streak_max = streak_1;
                        streak_1 = ZERO;
                    }
                    else
                    {
                        streak_1 = ZERO;
                    }
                }
            }
            if (streak_1 > streak_max)
            {
                streak_max = streak_1;
            }
            return static_cast<int>(streak_max);
        }
};


int main()
{
    vector<int> nums = { 1, 1, 0, 1, 1, 1 };

    Solution solution;
	int result = solution.findMaxConsecutiveOnes(nums);

	cout << "Max consecutive ones: " << result << endl; // Output: 3
	
    return 0;
}
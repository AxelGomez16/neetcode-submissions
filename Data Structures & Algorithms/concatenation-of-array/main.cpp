#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
  public:
    vector<int> getConcatenation(vector<int>& nums)
    {
      unsigned int count = 0U;
      int numsSize = nums.size();

      vector<int> ans(2 * numsSize);

      for (int& num : nums)
      {
        ans[count] = num;
        ans[count + numsSize] = num;
        count++;
      }
      return ans;
    }
};


int main ()
{
  vector<int> nums = {1, 4, 1, 2};

  Solution solution;

  vector<int> result = solution.getConcatenation(nums);
}
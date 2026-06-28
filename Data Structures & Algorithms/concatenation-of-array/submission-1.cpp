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
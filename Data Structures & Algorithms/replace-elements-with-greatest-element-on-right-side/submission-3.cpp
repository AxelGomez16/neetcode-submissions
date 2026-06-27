class Solution {
public:
  vector<int> replaceElements(vector<int>& arr) {
    
    unsigned int count = 0U;
    unsigned int arrSize = arr.size();

    for (int& num : arr)
    {
      if (count == arrSize - 1U)
      {
        arr[count] = -1U;
      }
      else
      {
        int maxNum = arr[count + 1U];

        for (int i = count + 1U; i <= arrSize; i++)
        {
          if (i < arrSize)
          {
            if (arr[i] >= maxNum)
            {
              maxNum = arr[i];
            }
          }
        }
        arr[count] = maxNum;

      }

      count++;
    }
    
    return arr;
  }
};
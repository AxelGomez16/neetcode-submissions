#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;


class Solution {
public:
  int calPoints(vector<string>& operations) 
  {

    vector<int> records;

    for (string& operation : operations)
    {

      if (operation == "+")
      {
        size_t recordsSize = records.size();
        records.push_back(records[recordsSize - 1] + records[recordsSize - 2]);
      }
      else if (operation == "C")
      {
        records.pop_back();
      }
      else if (operation == "D")
      {
        records.push_back(2 * records.back());
      }
      else 
      {
        records.push_back(stoi(operation));
      }
    }

    return accumulate(records.begin(), records.end(), 0);
  }
};


int main ()
{

  // vector<string> ops = {"1","2","+","C","5","D"};

  vector<string> ops = {"5", "2", "C", "D", "+"};

  Solution solution;

  int result = solution.calPoints(ops);

}



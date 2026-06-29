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
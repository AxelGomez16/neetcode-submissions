class Solution {
public:
  int calPoints(vector<string>& operations) 
  {
    int sumOperations = 0U;

    vector<int> records;

    
    for (string& operation : operations)
    {

      if (operation == "+")
      {
        unsigned int recordsSize = records.size();
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

    for (int& record : records)
    {
      sumOperations = sumOperations + record;
    }
  
    return sumOperations;
  }
};
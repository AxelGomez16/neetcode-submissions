class Solution {
public:
  int calPoints(vector<string>& operations) 
  {
    int sumOperations = 0U;
    vector<string> records;

    
    for (string& operation : operations)
    {

      if (operation == "+")
      {
        unsigned int recordsSize = records.size();
        records.push_back(to_string(stoi(records[recordsSize - 1]) + stoi(records[recordsSize - 2])));
      }
      else if (operation == "C")
      {
        records.pop_back();
      }
      else if (operation == "D")
      {
        records.push_back(to_string(2 * stoi(records.back())));
      }
      else 
      {
        records.push_back(operation);
      }
      count++;
    }

    for (string& record : records)
    {
      sumOperations = sumOperations + stoi(record);
    }
  
    return sumOperations;
  }
};
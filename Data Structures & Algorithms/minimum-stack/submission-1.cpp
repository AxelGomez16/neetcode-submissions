class MinStack 
{

  private:
   vector<int> stack;

  public:
    MinStack()
    {

    }
  
    void push(int val)
    {
      stack.push_back(val);
    }
  
    void pop() 
    {
      stack.pop_back();
    }
  
    int top() 
    {
      return stack.back();
    }
  
    int getMin() 
    {    
      if (!stack.empty())
      {
        int minValue = stack.back();
        for (int& num : stack)
        {
          if (num <= minValue) minValue = num;
        }
        return minValue;
      }
    }
};
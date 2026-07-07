#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
  MinStack minStack;


  minStack.push(1);
  minStack.push(2);
  minStack.push(0);
  minStack.push(12);
  minStack.push(1213);
  minStack.getMin(); // return 0
  minStack.pop();
  minStack.top();    // return 2
  minStack.getMin(); // return 1

  cout << "s" << endl;

}

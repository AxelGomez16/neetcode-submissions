#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isValid(string s)
	{
		char bracket_t = '\0';
		vector<char> bracketsNames;
		bool validBracket = true;

		for (char& letter : s)
		{
			if (letter == '(' || letter == '[' || letter == '{')
			{
				bracketsNames.push_back(letter);
			}
			else
			{
				if (bracketsNames.empty())
				{
					validBracket = false;
					break;
				}

				bracket_t = bracketsNames.back();

				if ( (letter == ')' && bracket_t == '(') || 
						 (letter == ']' && bracket_t == '[') || 
						 (letter == '}' && bracket_t == '{') )
				{
					bracketsNames.pop_back();
				}
				else
				{
					validBracket = false;
					break;
				}
			}
		}

		if (!bracketsNames.empty()) validBracket = false;

		return validBracket;

    }
};


int main ()
{
	//string s = "]";
	string s = "[(])";
	//string s = "(){}}{";
	//string s = ")(){}";
	//string s = "[(])";
	//string s = "([{}])";


	Solution solution;
	bool result = solution.isValid(s);

	cout << "result: " << result << endl;

}

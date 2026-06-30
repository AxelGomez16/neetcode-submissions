class Solution {
public:
	bool isValid(string s)
	{
		vector<string> bracketsNames;
		string bracket_t;
		string ParenthesesName = "parentheses";
		string BracketsName = "brackets";
		string BracesName = "braces";
		bool validBracket = false;
		bool atLeastOneElement = false;

		for (char& letter : s)
		{
			if (letter == '(')
			{
				bracketsNames.push_back(ParenthesesName);
				atLeastOneElement = true;
			}
			else if (letter == '[')
			{
				bracketsNames.push_back(BracketsName);
				atLeastOneElement = true;
			}
			else if (letter == '{')
			{
				bracketsNames.push_back(BracesName);
				atLeastOneElement = true;
			}
			else if (letter == ')' && bracketsNames.size() != 0)
			{
				bracket_t = bracketsNames.back();
				if (ParenthesesName == bracket_t)
				{
					bracketsNames.pop_back();
				}
			}
			else if (letter == ']' && bracketsNames.size() != 0)
			{
				bracket_t = bracketsNames.back();
				if (BracketsName == bracket_t)
				{
					bracketsNames.pop_back();
				}
			}
			else if (letter == '}' && bracketsNames.size() != 0)
			{
				bracket_t = bracketsNames.back();
				if (BracesName == bracket_t)
				{
					bracketsNames.pop_back();
				}
			}
			else
			{
				break;
			}
		}

		if (bracketsNames.size() == 0 && atLeastOneElement == true)
		{
			return validBracket = true;
		}

		return validBracket;
    }
};
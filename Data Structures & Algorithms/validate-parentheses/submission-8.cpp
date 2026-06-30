class Solution {
public:
	bool isValid(string s)
	{
		char bracket_t;
		vector<char> bracketsNames;

		for (char& letter : s)
		{
			if (letter == '(' || letter == '[' || letter == '{')
			{
				bracketsNames.push_back(letter);
			}
			else
			{
				if (bracketsNames.empty()) return false;

				bracket_t = bracketsNames.back();

				if ( (letter == ')' && bracket_t == '(') || 
						 (letter == ']' && bracket_t == '[') || 
						 (letter == '}' && bracket_t == '{') )
				{
					bracketsNames.pop_back();
				}
			}
		}

		if (bracketsNames.empty()) return true;

    }
};
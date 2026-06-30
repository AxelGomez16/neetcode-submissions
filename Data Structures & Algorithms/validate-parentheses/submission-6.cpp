class Solution {
public:
	bool isValid(string s)
	{
		vector<char> bracketsNames;
		char bracket_t;

		bool validBracket = false;

		for (char& letter : s)
		{
			if (letter == '(' || letter == '[' || letter == '{')
			{
				bracketsNames.push_back(letter);
			}
			else
			{
				if (bracketsNames.empty()) break;

				bracket_t = bracketsNames.back();

				if ( (letter == ')' && bracket_t == '(') || 
						 (letter == '[' && bracket_t == '[') || 
						 (letter == '}' && bracket_t == '{') )
				{
					bracketsNames.pop_back();
				}
			}
		}

		if (bracketsNames.empty()) validBracket = true;

		return validBracket;
    }
};
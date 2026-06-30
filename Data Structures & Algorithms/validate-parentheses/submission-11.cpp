class Solution {
public:
	bool isValid(string s)
	{
		vector<char> bracketsNames;
		char bracket_t;

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
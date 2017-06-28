#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool matchBracket(const string input) {

	const string prefix = "[{(";
	const string suffix = "]})";

	vector<char> buffer;
	buffer.clear();

	for (int i = 0; i < input.size(); i++)
	{
		if (prefix.find(input[i]) != string::npos)
		{
			buffer.push_back(input[i]);
		}
		else
		{
			if (buffer.empty())
				return false;

			if (suffix.find(input[i]) != prefix.find(buffer.back()))
				return false;

			buffer.pop_back();
		}
	}

	return buffer.empty();
}

int main() {

	int T;

	string input;

	cin >> T;
	cin.ignore();

	for (int z = 0; z < T; z++)
	{
		getline(cin, input);
		
		if (matchBracket(input))
			cout << "YES\n";
		else
			cout << "NO\n";

	}

	return 0;
}
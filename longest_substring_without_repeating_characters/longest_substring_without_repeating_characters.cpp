#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


int lengthOfLongestSubstring(string s) 
{
	int length = 0;
	int stringLength = s.length();
	map<char, int> _map;
    int lastPos = -1;
	for (int i = 0; i < stringLength; i++)
	{
		char c = s[i];
		if (_map.find(c) == _map.end() && (i - 1) == lastPos)
		{
            lastPos = i;
			_map[c] = i;
		}
        else
        {
            length = max(length, (int)_map.size());
            _map.clear();
            lastPos = i;
            _map[c] = i;
        }
	}
    length = max(length, (int)_map.size());
	return length;
}

int main()
{
	cout << "Longest Substring Without Repeating Characters" << endl;
	string str1 = "abcabcbb"; // the answer is "abc", which the length is 3.
	string str2 = "bbbbb";// the answer is "b", with the length of 1.
	string str3 = "pwwkew";// the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

	int l1, l2, l3;
	l1 = lengthOfLongestSubstring(str1);
	cout << "str1 length : " << l1 << endl;

	l2 = lengthOfLongestSubstring(str2);
	cout << "str2 length : " << l2 << endl;

	l3 = lengthOfLongestSubstring(str3);
	cout << "str3 length : " << l3 << endl;

    return 0;
}


// longest_substring_without_repeating_characters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

int lengthOfLongestSubstring(string s) 
{
	int length = 0;
	int stringLength = s.length();
	map<char, int> _map;
	//length = stringLength;
	for (int i = 0; i < stringLength; i++)
	{
		char c = s[i];
		if (_map.find(c) != _map.end())
		{
			_map[c] = i;
		}
	}


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

	getchar();
    return 0;
}


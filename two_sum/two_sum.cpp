#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
https://leetcode.com/problems/two-sum/#/description

Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

vector<int> twosum(vector<int>& num, int target)
{
	vector<int> res;
	int i;
	int j;
    int run_num = 0;	
	for (i = 0; i < num.size(); i++)
	{
		for (j = i + 1; j < num.size(); j++)
		{
            ++run_num;
			if ((num[i] + num[j]) == target)
			{
				res.push_back(i);
				res.push_back(j);
                cout<<"run number : " << run_num <<endl;
                return res;
			}
		}
	}
    cout<<"run number : " << run_num <<endl;
	return res;
}

vector<int> twosumUseMap(vector<int>& num, int target)
{
	vector<int> res;
	map<int, int> _map;
	int i;
    int run_num = 0;
	for (i = 0; i < num.size(); i++)
	{
        ++run_num;
		if (_map.find((target - num[i])) != _map.end())
		{
			res.push_back(i);
			res.push_back(_map[(target - num[i])]);
            cout<<"run number : " << run_num <<endl;
            return res;
		}
		else 
		{
			_map[num[i]] = i;
		}
	}
    cout << "run number : "<< run_num <<endl;
	return res;
}

void printVector(vector<int>& v)
{
	cout << "-------------------------------" << endl;
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl << "-------------------------------" << endl;
}

int main()
{
	int _nums[4] = { 2,7,11,15 };
	vector<int> nums(_nums, _nums + 4);
	printVector(nums);

	int target = 9;
    cout<< "input target "<<endl;
    cin >> target;

	vector<int> res;
	res = twosumUseMap(nums, target);
	printVector(res);

	vector<int> res2;
	res2 = twosum(nums, target);
	printVector(res2);

    return 0;
}


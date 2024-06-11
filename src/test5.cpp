#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> nums;
	nums.insert(nums.begin(), 99);
	nums.insert(nums.begin(), 34);
	nums.insert(nums.end(), 1000);
	nums.push_back(669);

	cout << "\n当前nums中元素为: " << endl;
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " " ;

	cout << nums.at(2);
	nums.erase(nums.begin());
	nums.pop_back();

	cout << "\n当前nums中元素为: " << endl;
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " " ;

	return 0;
}

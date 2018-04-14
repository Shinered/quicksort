#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
using namespace std;
int numofcompa = 0;
//选取第一个数作为主轴元素
void get_data(vector<int> &numbers);
void Partition(vector<int> &numbers, int l, int r);
void print(vector<int> number);
int ChoosePivot(vector<int> &numbers);
int main()
{
	clock_t start, end;
	start = clock();
	vector<int> numbers;
	get_data(numbers);
	print(numbers);
	int n = numbers.size(), l;
	l = ChoosePivot(numbers);
	Partition(numbers, 0, n);
	print(numbers);
	end = clock();
	cout << "running time:" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
	cout << "comparison times:" << numofcompa << endl;
	return 0;
}
void get_data(vector<int> &numbers)
{
	fstream f("QuickSort.txt");
	string line;
	long int temp;
	stringstream ss;
	while(getline(f, line))
	{
		long int temp;
		stringstream ss;
		ss << line;
		ss >> temp;
		numbers.push_back(temp);
	}
}

int ChoosePivot(vector<int> &numbers)
{
	return 0;
}


void Partition(vector<int> &numbers, int l, int r)
{
	int pivot = numbers[l];
	int i = l + 1;
	int temp;
	if(r == 1) return;
	if(r-1 == l) return;
	for(int j = l+1; j < r; j++)
	{
		if(numbers[j] < pivot)
		{
			temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
			i++;	
		}
	}
	numofcompa += r - l - 1;
	numbers[l] = numbers[i-1];
	numbers[i-1] = pivot;
	if(i-l == 1) {
		Partition(numbers, i, r);
	} else if(i == r) {
		Partition(numbers, l, i-1);
	} else {
		Partition(numbers, l, i-1);
		Partition(numbers, i, r);
	}
}
void print(vector<int> number)
{
	for(int i = 0; i < number.size(); i++)
	{
		cout << number[i] << ",";
	}
	cout << endl;
}
 


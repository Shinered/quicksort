#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
using namespace std;
int numofcompa = 0;
//选取最后一个值作为主轴元素
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
	Partition(numbers, 0, l);
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
	return numbers.size()-1;
}


void Partition(vector<int> &numbers, int l, int r)
{
	if(r == l) return;
	int pivot = numbers[r];
	int i = r-1, temp;
	for(int j = i; j >=l; j-- )
	{
		if(numbers[j] > pivot)
		{
			temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
			i--;
		}
	}
	numofcompa += r-l;
	numbers[r] = numbers[i+1];
	numbers[i+1] = pivot;
	if(i+1 == l)
	{
		Partition(numbers, i+2, r);
	} else if(i == r-1) {
		Partition(numbers, l, i);
	} else {
		Partition(numbers, l, i);
		Partition(numbers, i+2, r);
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
 


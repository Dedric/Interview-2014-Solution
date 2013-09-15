/*
Huawei 2014 Campus Interview Sample Problem
problem1
Author: Dedric
Email: dedric.xu@gmail.com
*/

# include "iostream"
using namespace std;

void problem2()
{
	int i=0, N;
	cin>>N;

	bool* lamp = new bool[N];
	int lamp_index, lamp_on=0;
	memset(lamp, true, N);

	for(i=2;i<=N;i++)
	{
		lamp_index = i;
		while(lamp_index<=N)
		{
			lamp[lamp_index-1] = !lamp[lamp_index-1];
			lamp_index = lamp_index*i;
		}
	}

	for(i=0;i<N;i++)
	{
		if (lamp[i])
			lamp_on++;
	}

	cout<<lamp_on<<endl;

} 

void main()
{
	problem2();
}



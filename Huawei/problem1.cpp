/*
Huawei 2014 Campus Interview Sample Problem
problem1
Author: Dedric
Email: dedric.xu@gmail.com
*/

# include "iostream"
using namespace std;

void problem1()
{
	int i=0, j=0, N = 10, min_val=110;
	int a[10];

	// input value and check valid
	while(i<10 && cin>>a[i])
	{
		if (0 < a[i] && a[i] < 100)
			if (a[i] <  min_val)
				min_val = a[i];
			i++;
	}

	if (min_val>60)
	{
		cout<<60<<endl;
		return;
	}	
	
	int pass_score, count;
	for(i=0;i<11;i++)
	{
		pass_score = (10-i)*10;
		count = 0;
		for(j=0;j<10;j++)
		{
			if (a[j]>pass_score)
				count++;
			if (count>=6)
			{
				cout<<pass_score<<endl;
				break;
			}
		}
		if (count>=6)
			break;
	}
}

void main()
{
	problem1();
}



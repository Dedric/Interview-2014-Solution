# include <iostream>
# include <queue>

using namespace std;

int main()
{
	int N=0; // the number of vehicle
	int i=0;
	int count=0; //
	int coach_count=0; // the maixmum count of coach one time, should be less than 5.
	int* vehicle = new int[N]; // the type of the vehicle (can only be 0 or 1)
	int* order = new int[N];
	cin>>N;

	while(i<N)
	{
		cin>>vehicle[i];
		if(1==vehicle[i] || 0==vehicle[i])
		{
			i++;
		}
		else
		{
			cout<<"Wrong input, value should be 0 or 1."<<endl;
		}
	}

	queue<int> type;
	queue<int> lorry;

	for(i=0;i<N;i++)
	{
		//cout<<vehicle[i]<<" ";
		if (coach_count<4)
		{
			if (0==vehicle[i])
			{
				order[i] = count;
				count++;
				coach_count++;
			}
			else
			{
				type.push(vehicle[i]);
				lorry.push(i);
			}
			if (i==N-1)
			{
				while(!type.empty())
				{
					type.pop();
					order[lorry.front()] = count;
					lorry.pop();
					count++;
				}
			}
		}
		else
		{
			if (!type.empty())
			{
				type.pop();
				order[lorry.front()] = count;
				lorry.pop();
				count++;
				coach_count=0;
			}

		}
	}

	// Output the order
	for(i=0;i<N;i++)
	{
		cout<<order[i]<<" ";
	}
	cout<<endl;
	return 1;
}
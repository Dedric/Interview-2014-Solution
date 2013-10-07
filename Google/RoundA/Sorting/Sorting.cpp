# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

bool CompDec(const int &a, const int &b)
{
	return a>b;
}

bool CompInc(const int &a, const int &b)
{
	return a<b;
}

int main()
{
	int T = 0; // Number of Test Cases
	cin>>T;
	int N = 0;
	vector<int> Alex,Bob;
	int tmp_value;
	int Alex_index=0, Bob_index=0;
	for(int i =0;i<T;i++)
	{
		cin>>N;
		int *order = new int[N];
		Alex.clear();
		Bob.clear();
		for(int j=0;j<N;j++)
		{
			cin>>tmp_value;
			if (0==tmp_value%2) // even value
			{
				order[j] = 0;
				Bob.push_back(tmp_value);
			}
			else // odd value
			{
				order[j] = 1;
				Alex.push_back(tmp_value);
			}
		}

		// sort the books
		// Alex's books: odd values (increasing order)
		// Bob's books: even values (decreasing order)
		sort(Alex.begin(),Alex.end(),CompInc);
		sort(Bob.begin(),Bob.end(),CompDec);

		// Output the result
		cout<<"Case #"<<(i+1)<<":";
		Alex_index=0;
		Bob_index=0;
		for(int j=0;j<N;j++)
		{
			//if (Bob_index>=Bob.size() || Alex_index>=Alex.size())
			//	break;
			if (order[j] == 0) // even values
			{
				cout<<" "<<Bob[Bob_index++];
			}
			else // odd values
			{
				cout<<" "<<Alex[Alex_index++];
			}
		}
		cout<<endl;
	}
	return 1;
}

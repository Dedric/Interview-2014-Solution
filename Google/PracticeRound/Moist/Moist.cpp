# include <iostream>
# include <string>

using namespace std;

int main()
{
	int T=0, N=0, iter=0, count=0;
	string maxstr="";
	string *namelist;
	cin>>T;
	for (iter=0; iter<T;iter++)
	{
		cin>>N;
		getline(cin, maxstr); // inputstr is \n; refresh the input cache;
		maxstr = "";
		count = 0;
		for (int i=0;i<N;i++)
		{
			namelist = new string[N];
			getline(cin,namelist[i]);
			if (i==0)
			{
				maxstr = namelist[i];
			}
			else
			{
				if (namelist[i]<maxstr) count++;
				else maxstr = namelist[i];
			}
		}

		cout<<"Case #"<<(iter+1)<<": "<<count<<endl;
		delete []namelist;
		namelist = NULL;

	}
	return 1;
	
}
# include <iostream>
# define ull unsigned long long
using namespace std;

ull getN(ull p, ull q)
{
	if (p>q)
	{
		return 2*getN(p-q,q)+1;
	}
	else if (p<q)
	{
		return 2*getN(p,q-p);
	}
	else
	{
		return 1;
	}
}

ull* getpq(ull N)
{
	ull* a = new ull[2];
	if (N==1)
	{
		a[0] = 1;
		a[1] = 1;
		return a;
	}
	if (0==N%2) // even value
	{
		a = getpq(N/2);
		a[1] = a[0]+a[1];
	}
	else // odd value
	{
		a = getpq(N/2);
		a[0] = a[0]+a[1];
	}
	return a;
}


int main()
{
	int T = 0; // Number of Test Case
	cin>>T;
	int id = 0;
	ull N=0,p=0,q=0;
	ull *pq;
	for (int i=0;i<T;i++)
	{
		cin>>id;
		cout<<"Case #"<<(i+1)<<":";
		if (1==id) // problem id 1
		{
			cin>>N;
			pq = getpq(N);
			cout<<" "<<pq[0]<<" "<<pq[1]<<endl;
		}
		else // problem id 2
		{
			cin>>p;
			cin>>q;
			cout<<" "<<getN(p,q)<<endl;
		}

	}
	
	return 1;
}

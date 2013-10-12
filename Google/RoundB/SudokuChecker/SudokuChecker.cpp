# include <iostream>
# include <string>
# include <map>
# include <vector>
using namespace std;

int main()
{
	int T = 0;
	cin>>T;
	int N=0;
	int **a=NULL;
	bool Sudoku = true;
	map<int,bool> sudoku;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		a = new int*[N*N];
		for(int j=0;j<N*N;j++)
			a[j] = new int[N*N];

		sudoku.clear();
		Sudoku = true;

		for(int j=0;j<N*N;j++)
		{
			sudoku.clear();
			for(int k=0;k<N*N;k++)
			{
				cin>>a[j][k];
				if (a[j][k]>N*N || a[j][k]<0)
				{
					Sudoku = false;
					continue;
				}
				if (sudoku.find(a[j][k]) == sudoku.end())
					sudoku[a[j][k]] = true;
				else
					Sudoku = false;
			}
		}

		cout<<"Case #"<<(i+1)<<": ";
		if (Sudoku == false)
			cout<<"No"<<endl;
		else
		{
			for(int j=0;j<N*N;j++)
			{
				sudoku.clear();
				for(int k=0;k<N*N;k++)
				{
					if (sudoku.find(a[k][j]) == sudoku.end())
					{	
						sudoku[a[k][j]] = true;
					}
					else
					{
						Sudoku = false;
						cout<<"No"<<endl;
					}
				}
			}
			cout<<"Yes"<<endl;
		}

		// delete
		for(int j=0;j<N*N;j++)
			 delete []a[j];
		delete []a;
	}
	return 1;
}
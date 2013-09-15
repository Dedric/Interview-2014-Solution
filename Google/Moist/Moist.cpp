# include <iostream>
# include <fstream>
# include <string>

using namespace std;

int Charge(string *FirstName, string *MiddleName, string *LastName, int N)
{
	int count=0;
	string tmpstr;
	for (int i=1;i<N;i++)
	{
		for (int j=0;j<N-i;j++)
		{
			if (FirstName[j]>FirstName[j+1])
			{
				count++;
				tmpstr = FirstName[j];
				FirstName[j] = FirstName[j+1];
				FirstName[j+1] = tmpstr;

				tmpstr = MiddleName[j];
				MiddleName[j] = MiddleName[j+1];
				MiddleName[j+1] = tmpstr;
				
				tmpstr = LastName[j];
				LastName[j] = LastName[j+1];
				LastName[j+1] = tmpstr;

			}
			else
			{
				if (FirstName[j]==FirstName[j+1])
				{
					if (MiddleName[j]>MiddleName[j+1])
					{
						count++;
						tmpstr = MiddleName[j];
						MiddleName[j] = MiddleName[j+1];
						MiddleName[j+1] = tmpstr;

						tmpstr = LastName[j];
						LastName[j] = LastName[j+1];
						LastName[j+1] = tmpstr;
					}
					else
					{
						if (MiddleName[j]==MiddleName[j+1])
						{
							if (LastName[j]>LastName[j+1])
							{
								count++;
								tmpstr = LastName[j];
								LastName[j] = LastName[j+1];
								LastName[j+1] = tmpstr;
							}
						}
					}
					
				}
				
			}
		}
	}		
	return count;
}

int main()
{
	int T, N;

	ifstream readfile;
	string line;
	string src = "C-small-practice-2.in";

	readfile.open(src.c_str(),ios::in);

	getline(readfile,line);
	T = atoi(line.c_str());

	ofstream ocout;
	ocout.open("C-small-practice-2.out");

	int *output = new int[T]; // output
	string *FirstName,*MiddleName,*LastName;

	int i = 0, j=0;
	for(i=0;i<T;i++)
	{
		getline(readfile,line);
		N = atoi(line.c_str());
		FirstName = new string[N];
		MiddleName = new string[N];
		LastName = new string[N];
		for(j=0;j<N;j++)
		{
			getline(readfile,line);
			string::size_type index = line.find_first_of(" ",0);
			FirstName[j] = line.substr(0,index);

			if (line.find_last_of(" "))
			{
				MiddleName[j] = line.substr(index+1);
				LastName[j] = line.substr(line.find_last_of(" ")+1);
			}
			else
			{
				MiddleName[j] = line.substr(index+1);
				LastName[j] = "";
			}
		}
		output[i] = Charge(FirstName, MiddleName, LastName, N);
	}

	// output result
	for(i=0;i<T;i++)
	{
		ocout<<"Case #"<<(i+1)<<": "<<output[i]<<endl;
	}

	ocout.close();

	return 1;
}
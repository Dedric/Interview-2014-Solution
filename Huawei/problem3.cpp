/*
Huawei 2014 Campus Interview Sample Problem
problem1
Author: Dedric
Email: dedric.xu@gmail.com
*/

# include "iostream"
# include "hash_map"
# include "string"
# include "map"
# include "math.h"

using namespace std;

int* distanceA(int A_value)
{
	int *distance =new int[2];
	distance[0] = (A_value > 13)?(A_value-7):((A_value > 9)?(A_value-8):(A_value-11));
	distance[1] = (A_value > 13)?(A_value-12):((A_value > 9)?(A_value-15):(A_value-16));
	return distance;
}

int* distanceB(int B_value)
{
	int *distance = new int[2];
	distance[0] = (B_value > 10)?(B_value-3):((B_value > 5)?(B_value-4):(B_value-7));
	distance[1] = (B_value > 10)?(B_value-9):((B_value > 5)?(B_value-12):(B_value-13));
	return distance;
}

template <class T>
void swap(T *cur_array)
{
	T tmp = cur_array[0];
	cur_array[0] = cur_array[1];
	cur_array[1] = tmp;
}

int problem3()
{
	enum Line{A=18,B=15,T=2};
	map<char,Line> linemap;
	linemap['A']=A;
	linemap['B']=B;
	linemap['T']=T;

	string str[2], tmp_str;
	int pos[2], i=0, tmp_pos;
	char linetype[2];

	// Input value ,check and save valid value
	while(cin>>str[i])
	{
		tmp_str = str[i];
		if (tmp_str[0]=='A' || tmp_str[0]=='B' || tmp_str[0]=='T')
		{
			tmp_pos = atoi(tmp_str.substr(1,string::npos).c_str());
			if (tmp_pos>0 && tmp_pos <= (int)linemap[tmp_str[0]])
			{
				pos[i] = tmp_pos;
				linetype[i] = tmp_str[0];
				i++;
			}
		}
		if (i==2) break;
	}

	if (linetype[0]>=linetype[1])  // sort linetype and pos
	{
		swap(linetype);
		swap(pos);
	}

	int *distance1, *distance2;
	int distance;
	
	if (linetype[0]==linetype[1]) // same line
	{
		if (linetype[0] == 'T')
			return (abs(pos[0]-pos[1])==0)?1:6;
		else if (linetype[0] == 'A')  // line A
		{
			distance1 = distanceA(pos[0]);
			distance2 = distanceA(pos[1]);
			
			if (distance1[0]*distance2[0]<0)
				distance = abs(distance1[0]-distance2[0])-1;
			else
				distance = abs(distance1[0]-distance2[0])+1;

			return min(distance, 22-distance);
		}
		else // line B
		{
			distance1 = distanceB(pos[0]);
			distance2 = distanceB(pos[1]);
			
			if (distance1[0]*distance2[0]<0)
				distance = abs(distance1[0]-distance2[0])-1;
			else
				distance = abs(distance1[0]-distance2[0])+1;

			return distance;
		}
	}
	else if (linetype[1] == 'T') // because linetype already sorted
	{ // only one of the station is 'Tx'
		if (linetype[0] == 'A')
		{
			distance1 = distanceA(pos[0]);
			distance = abs(distance1[pos[1]-1]);
			return min(distance, 22-distance);
		}
		else
		{
			distance1 = distanceB(pos[0]);
			distance = abs(distance1[pos[1]-1]);
			if ((pos[0]>10 && pos[1]==1) || (pos[0]<6 && pos[1]==2))
				return distance-1;
			else
				return distance;
		}
	}
	else
	{ // the two station is 'Ax' and 'Bx' respectively
		distance1 = distanceA(pos[0]);
		distance2 = distanceB(pos[1]);

		// find transition point
		int trans = (pos[1]>10)?2:((pos[1]<5)?1:0);
		if (trans==0)
		{
			for(int i=0;i<2;i++)
				distance1[i] = abs(distance1[i])+abs(distance2[i])-1;
			distance = min(distance1[0],distance1[1]);
		}
		else
		{
			distance = abs(distance1[trans-1]);
			distance = min(distance, 22-distance);
			distance += abs(distance2[trans-1]);

		}
		return distance;
	}
}
void main()
{
	cout<<problem3()<<endl;
}



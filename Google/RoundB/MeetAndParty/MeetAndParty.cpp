# include <iostream>
# include <string>
# include <map>
# include <vector>
# include <algorithm>
# define ll long long

using namespace std;

typedef struct point
{
	ll x;
	ll y;
}point;

ll getDistance(point a, point b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}

int main()
{
	int T =0;
	cin>>T;

	int B = 0;
	ll x1=0,y1=0,x2=0,y2=0;
	vector<point> people;
	point a;
	ll num=0;
	ll min_distance = 0,distance=0;

	for(int i=0;i<T;i++)
	{
		cin>>B;
		people.clear();

		for(int j=0;j<B;j++)
		{
			cin>>x1>>y1>>x2>>y2;
			for(ll tmp_x=x1;tmp_x<=x2;tmp_x++)
			{
				for(ll tmp_y=y1;tmp_y<=y2;tmp_y++)
				{
					a.x = tmp_x;
					a.y = tmp_y;
					people.push_back(a);
				}
			}
		}

		num = people.size();
		for(ll tmp_x=0;tmp_x<num;tmp_x++)
		{
			distance=0;
			for(ll tmp_y=0;tmp_y<num;tmp_y++)
			{
				if (people[tmp_x].x == people[tmp_y].x && people[tmp_x].y == people[tmp_y].y)
				{
					continue;
				}
				else
				{
					distance += getDistance(people[tmp_x], people[tmp_y]);
				}
			}

			if (tmp_x==0)
			{
				min_distance = distance;
				a = people[tmp_x];
			}
			else
			{
				if (min_distance>distance)
				{
					min_distance = distance;
					a = people[tmp_x];
				}
				else
				{
					if (min_distance==distance)
					{
						if (a.x>people[tmp_x].x)
							a = people[tmp_x];
						else
						{
							if (a.x == people[tmp_x].x && a.y>people[tmp_x].y)
								a = people[tmp_x];
						}
					}
				}


			}
		}

		cout << "Case #"<<(i+1)<<": "<<a.x<<" "<<a.y<<" "<<min_distance<<endl;
	}
	
	return 1;
}

// unfinished solution
# include <iostream>
# include <map>
# include <string>
# include <vector>

using namespace std;

int vec_min(vector<int> result)
{
	vector<int>::iterator iter;
	for(iter = result.begin(); iter != result.end();) // delete -1 in result
	{
		if(*iter == -1)
		{
			iter = result.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	int vec_size = result.size();
	
	if (vec_size == 0)
		return -1;

	int tmp_min = result[0];
	for(int i=1;i<vec_size;i++)
	{
		tmp_min = min(tmp_min,result[i]);
	}
	return tmp_min;
}

int getDistance(int p, int q, string *room_color, int** room_distance, bool *visited, int N)
{
	vector<int> result_vec;
	int tmp_distance1, tmp_distance2;

	if (p==q)
		return room_distance[p-1][q-1];

	if (room_color[p-1] == room_color[q-1]) // same color
		return 0;
	else // different color
	{
		result_vec.clear();
		result_vec.push_back(room_distance[p-1][q-1]);
		// find the room that connect with room q
		for(int i=1;i<=N;i++)
		{
			if (i==p || i == q)
				continue;

			if (room_color[i-1] == room_color[p-1] || room_color[i-1] == room_color[q-1])
				continue;

			if (visited[i-1]==1)
				continue;

			if (room_distance[i-1][q-1]!=-1)
			{
				visited[i-1]=1;
				tmp_distance1 = getDistance(p,i,room_color,room_distance,visited,N);
				tmp_distance2 = getDistance(i,q,room_color,room_distance,visited,N);
				if (tmp_distance1 == -1 || tmp_distance2 == -1)
					continue;
				else
					result_vec.push_back(tmp_distance1+tmp_distance2);
			}
			visited[i-1]=0;
		}
		return vec_min(result_vec);
	}
}

class SpaceDefense
{
public:
	SpaceDefense()
	{
		Initial();
		Run();
		delete_pointer();
	}

	~SpaceDefense(){}

	int Initial()
	{
		cin>>N;

		// define the distance between rooms
		room_distance = new int*[N];
		for(int i=0;i<N;i++)
		{
			room_distance[i] = new int[N];
			// set the distance at -1, where -1 represents that the two rooms are dis-connected
			for(int j=0;j<N;j++)
			{
				if (i==j)
				{
					room_distance[i][j]=0;
				}
				else
				{
					room_distance[i][j]=-1;
				}
			} 
		}

		//// output room distance
		//for(int i=0;i<N;i++)
		//{
		//	for(int j=0;j<N;j++)
		//	{
		//		cout<<room_distance[i][j]<<" ";
		//	}
		//	cout<<endl;
		//}

		room_color = new string[N];
		color_room.clear();
		
		for(int i=0;i<N;i++)
		{
			cin>>room_color[i];
			//cout<<room_color[i]<<endl;
			room_vec.clear();
			if (color_room.find(room_color[i]) != color_room.end()) // color exists!
			{
				room_vec = color_room[room_color[i]];
			}
			room_vec.push_back(i+1);
			color_room[room_color[i]] = room_vec; // update room vector of the same color
		}

		// room distance assignment
		cin>>M;
		for(int i=0;i<M;i++)
		{
			cin>>ai;
			cin>>bi;
			cin>>tmp_distance;

			if (room_distance[ai-1][bi-1]!=-1)
				tmp_distance = min(tmp_distance,room_distance[ai-1][bi-1]);

			a = color_room[room_color[ai-1]];
			b = color_room[room_color[bi-1]];
			
			for(int x=0;x<a.size();x++)
			{
				for(int y=0;y<b.size();y++)
					room_distance[a[x]-1][b[y]-1] = tmp_distance;
			}
		}

		// set the distance between the same color rooms at 0
		for(iter = color_room.begin();iter!=color_room.end();iter++)
		{
			room_vec = iter->second;
			room_vec_size = room_vec.size();
			for(int i=0;i<room_vec_size-1;i++)
			{
				for(int j=i+1;j<room_vec_size;j++)
				{
					room_distance[room_vec[i]-1][room_vec[j]-1]=0;
					room_distance[room_vec[j]-1][room_vec[i]-1]=0;
				}
			}
		}

		//// output room distance
		//for(int i=0;i<N;i++)
		//{
		//	for(int j=0;j<N;j++)
		//	{
		//		cout<<room_distance[i][j]<<" ";
		//	}
		//	cout<<endl;
		//}

		visited = new bool[N];

		return 1;
	}

	int Run()
	{
		cin>>S;
		for(int i=0;i<S;i++)
		{
			cin>>pj;
			cin>>qj;
			memset(visited,0,N); // set all values false
			visited[pj-1]=1; // set true
			visited[qj-1]=1; // set true
			cout<<getDistance(pj,qj,room_color,room_distance,visited,N)<<endl;
		}
		return 1;
	}

	int delete_pointer()
	{
		// delete 
		delete []room_color;
		for(int i=0;i<N;i++)
			delete []room_distance[i];
		delete []room_distance;
		return 1;
	}

private:
	int N; // number of rooms in the spaceship
	int M; // number of turbolifts in the spaceship
	int S; // number of soliders
	int ai, bi; // room ai, bi;
	int pj, qj; 

	string *room_color; // room ---- color
	map<string,vector<int> > color_room; // color ---- room
	map<string,vector<int> >::iterator iter;
	vector<int> room_vec;
	vector<int> a, b;
	int room_vec_size;
	int tmp_distance;
	int** room_distance;
	bool *visited;
};

int main()
{
	int T = 0; // number of test cases
	cin>>T;

	for(int k=0;k<T;k++)
	{
		cout<<"Case #"<<(k+1)<<":"<<endl;
		SpaceDefense();
	}

	return 1;
}

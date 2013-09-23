// better used in bash/term, g++ compiled, use file pipe as input

# include <iostream>
# include <string>
# include <queue>
# include <map>

using namespace std;

class MemberSeparable
{
public:
	MemberSeparable(string* NameList,int Len):namelist(NameList),len(Len){}
	~MemberSeparable(){}
	bool separable(); // check whether case # separable; 
	bool chechin(string name1, string name2); // check whether name1 and name2 exist in separable_map;
	int queuepop(); // pop queue1 and queue2;

private:
	string* namelist; // store input names
	int len; // equal to two times of input names
	queue<string> queue1, queue2; // queue1 and queue2 are used to store two input names respectively
	map<string,bool> separable_map; // store all the names into map (similar to hash map) for the purpose of finding
	map<string,bool>::iterator iter1, iter2; // use two iterator to find two input names.
};

int MemberSeparable::queuepop() // pop queue1 and queue2
{
	queue1.pop();
	queue2.pop();
	return 1;
}

bool MemberSeparable::chechin(string name1, string name2)
{
	// check whether name1 and name2 exist in separable_map
	iter1 = separable_map.find(name1);
	iter2 = separable_map.find(name2);

	if(iter1 !=  separable_map.end() && iter2 !=  separable_map.end())
	{
		// already exist
		if (separable_map[name1] == separable_map[name2])
			return false;
	}
	else if (iter1 !=  separable_map.end() && iter2 ==  separable_map.end())
	{
		// name1 exists, name2 does not exist
		separable_map.insert(pair<string,bool>(name2,!separable_map[name1]));
	}
	else if (iter1 ==  separable_map.end() && iter2 !=  separable_map.end())
	{
		// name1 does not exist, name2 exists
		separable_map.insert(pair<string,bool>(name1,!separable_map[name2]));
	}
	else
	{
		// both name1 and name2 do not exist
		queue1.push(name1);
		queue2.push(name2);
	}
	return true;
}

bool MemberSeparable::separable()
{
	// check whether case # separable
	if (len == 2)
		return true;
	
	// insert first-input two names
	separable_map.insert(pair<string,bool>(namelist[0],true));
	separable_map.insert(pair<string,bool>(namelist[1],false));

	// traverse the input names 
	for(int i=1;i<len/2;i++)
	{
		if (!chechin(namelist[2*i], namelist[2*i+1]))
			return false;
	}

	// check namelist in the queues
	int queue_size = queue1.size();
	queue_size = queue_size*(queue_size+1)/2; // This value is important !!!
	while(queue_size>0)
	{
		if (!chechin(queue1.front(), queue2.front()))
		{
			return false;
		}
		queuepop();
		queue_size--;
		if (queue1.size()==0)
			break;
	}

	// check redundant names
	if (queue1.size()>0)
	{
		int M = queue1.size();
		string* subnamelist = new string[2*M];
		for(int j=0;j<M;j++)
		{
			subnamelist[j*2] = queue1.front();
			subnamelist[j*2+1] = queue2.front();
			queuepop();
		}

		MemberSeparable subresult(subnamelist,2*M);
		return subresult.separable();

	}

	return true;

}

int main()
{
	int T, M;

	cin>>T;
	string* output = new string[T]; // output
	string* namelist;
	
	int i = 0, j=0;
	for(i=0;i<T;i++)
	{
		cin>>M;
		namelist = new string[2*M];
		for(j=0;j<M;j++)
		{
			cin>>namelist[j*2];
			cin>>namelist[j*2+1];
		}

		MemberSeparable result(namelist,2*M);
		if (result.separable())
		{
			output[i]= "Yes";
		}
		else
		{
			output[i]= "No";
		}
	}

	// output result
	for(i=0;i<T;i++)
	{
		cout<<"Case #"<<(i+1)<<": "<<output[i]<<endl;
	}

	//icin.close();
	//ocout.close();

	return 1;
}
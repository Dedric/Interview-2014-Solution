# include <iostream>
# include <string>
# include <cstdlib>
# include <vector>
# include <map>

using namespace std;

class readphone
{
public:
	
	readphone(string tele,string format):telephone(tele),readformat(format)
	{
		output = "";
		alphabetic();
		split(format);
		read_out(tele);
	}
	~readphone(){}

	int alphabetic()
	{
		phone.insert(pair<char,string>('0',"zero"));
		phone.insert(pair<char,string>('1',"one"));
		phone.insert(pair<char,string>('2',"two"));
		phone.insert(pair<char,string>('3',"three"));
		phone.insert(pair<char,string>('4',"four"));
		phone.insert(pair<char,string>('5',"five"));
		phone.insert(pair<char,string>('6',"six"));
		phone.insert(pair<char,string>('7',"seven"));
		phone.insert(pair<char,string>('8',"eight"));
		phone.insert(pair<char,string>('9',"nine"));

		count.insert(pair<int,string>(1,""));
		count.insert(pair<int,string>(2,"double "));
		count.insert(pair<int,string>(3,"triple "));
		count.insert(pair<int,string>(4,"quadruple "));
		count.insert(pair<int,string>(5,"quintuple "));
		count.insert(pair<int,string>(6,"sextuple "));
		count.insert(pair<int,string>(7,"septuple "));
		count.insert(pair<int,string>(8,"octuple "));
		count.insert(pair<int,string>(9,"nonuple "));
		count.insert(pair<int,string>(10,"decuple "));
		return 1;
	}

	int split(string format)
	{
		index_num = 1;
		index_list = new int[telephone.length()];
		while(true)
		{
			index = format.find("-");
			if (-1 == index)
			{
				index_list[index_num-1] = atoi(format.substr(0,format.length()).c_str());
				break;
			}
			
			index_list[index_num-1] = atoi(format.substr(0,index).c_str());
			index_num++;
			format.erase(0,index+1);
		}
		return 1;
	}

	int read_out(string tele)
	{
		int start = 0;
		string tele_sub;
		for (int i=0;i<index_num;i++)
		{
			tele_sub = tele.substr(start,index_list[i]);
			start = start+index_list[i];
			read_sub(tele_sub, index_list[i]);
		}
		return 1;
	}

	int read_sub(string tele_sub, int len)
	{
		if (len == 1)
		{
			cout<<" "<<phone[tele_sub[0]];
		}
		else
		{
			int consective=1;
			char cur = tele_sub[0];
			string tmp;

			cur = tele_sub[0];

			for (int i=0;i<len-1;i++)
			{
				if (cur == tele_sub[i+1])
				{
					consective++;
				}
				else
				{
					if (consective>10)
					{
						while(consective--)
							cout<<" "<<phone[cur];
					}
					else
					{
						cout<<" "<<count[consective]<<phone[cur];
					}
					consective=1;
					cur = tele_sub[i+1];
				}

				if (i==len-2)// last one
				{
					if (consective>10)
					{
						while(consective--)
							cout<<" "<<phone[cur];
					}
					else
					{
						cout<<" "<<count[consective]<<phone[cur];
					}
				}
			}
		}
		
		return 1;
	}

private:
	map<char,string> phone;
	map<int,string> count;
	string telephone;
	string readformat;
	int index_num, index;
	int *index_list;
	string output;
};



int main()
{
	int num=0;
	cin>>num;
	//cout<<num<<endl;
	string tele, format;
	getline(cin,tele);
	string tmp="";

	int index_num=0, index;
	int index_list[3];
	for (int i=0;i<num;i++)
	{
		cin>>tele;
		cin>>format;
		//cout<<tele<<" "<<format<<endl;
		cout<<"Case #"<<i+1<<":";
		readphone result(tele,format);
		cout<<endl;
	}
	return 1;
}
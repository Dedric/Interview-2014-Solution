#define _USE_MATH_DEFINES
# include <iostream>
# include <cmath>

using namespace std;

int main()
{
	double gravity = 9.8;
	int T = 0; // T lines
	double Velocity = 0; // Velocity
	double Distance = 0; // destination distance
	double theta=0; // takeoff angle
	double tmp = 1.0;
	cin >> T;
	for (int i=0;i<T;i++)
	{
		cin>>Velocity;
		cin>>Distance;
		tmp = gravity*Distance/pow(Velocity,2);
		if (tmp<=1.0)
		{
			theta = asin(tmp)*180/M_PI/2;
		}
		else
		{
			if (tmp-1<1.0e-3) theta = asin(1.0)*180/M_PI/2;
			else cout<<"Error"<<endl;
		}
		cout<<"Case #"<<(i+1)<<": ";
		cout.precision(10);
		cout<<theta<<endl;
	}
	return 1;
}

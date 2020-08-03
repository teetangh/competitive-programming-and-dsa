#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r" , stdin);
	freopen("output1.txt", "w" ,stdout);
	#endif

	float a , b, c;
	cin >> a >> b >> c;

	queue <pair<string,int>> mq;
	
	while( a != 0 | b != 0 | c != 0)
	{
		if(a - b == b -c)
			mq.push(std::make_pair("AP",c + (b - a )));
		else 
			// if( b * b == a * c  )
			mq.push(std::make_pair("GP",((c * b)/a)));
		cin >> a >> b >> c;
	}

	while(!mq.empty())
	{
		pair<string,int> temp = mq.front();
		mq.pop();
		cout <<temp.first <<" "<< temp.second << endl;
	}
	return 0;
}
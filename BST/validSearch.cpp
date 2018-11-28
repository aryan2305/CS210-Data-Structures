#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int prev=a[0],now=a[1];
	char direct=a[0]<a[1] ? 'R' : 'L';
	int flag=0;
	for (int i = 2; i < n; ++i)
	{
		if(direct=='L')
		{
			if(a[i]==now)
			{
				flag=1;
				break;
			}
			else if(a[i]<now)
			{
				prev=now;
				now=a[i];
			}
			else
			{
				if(a[i]>=prev)
				{
					flag=1;
					break;
				}
				else{
					prev=now;
					now=a[i];
					direct='R';
				}
			}
		}
		else
		{
			if(a[i]==now)
			{
				flag=1;
				break;
			}
			else if(a[i]>now)
			{
				prev=now;
				now=a[i];
			}
			else
			{
				if(a[i]<=prev)
				{
					flag=1;
					break;
				}
				else{
					prev=now;
					now=a[i];
					direct='L';
				}
			}
		}
	}
	if(flag)
		cout<<"Invalid"<<endl;
	else
		cout<<"Valid"<<endl;
	return 0;
}
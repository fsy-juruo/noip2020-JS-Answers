#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(;  isdigit(c); c = getchar()) x = (x << 3) + (x << 1) +  c - '0';
	x *= f;
}



int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);

	int n;
	read(n);
	cout<<"NOIP 2020 rp++"<<endl;
	cout<<"keep a promising future"<<endl;
 	return 0;
}


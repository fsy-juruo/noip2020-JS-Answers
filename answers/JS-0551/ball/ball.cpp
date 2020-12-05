#include <bits/stdc++.h>
using namespace std;
stack <int> a1, a2, a3;
int n, m, n1, n2, n3, step[3][100001], sp, i = 1;
int main()
{
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    cin >> n >> m;
	for (int j = 1; j <= m; j++)
    {
    	cin >> sp;
    	a1.push(sp);
    }
    for (int j = 1; j <= m; j++)
    {
    	cin >> sp;
    	a2.push(sp);
    }
	sp = 0;
	n1 = n2 = m;
	n3 = 0;
	if (n == 2)
	{
	    if (a1.top() == 1)
		{
		    while (1)
		    {
			    if (n3 == m)
				{
					break;
				}    
				while (a1.empty() == 0 and a1.top() == 1)	
				{
					a3.push(a1.top());
					n3++;
					a1.pop();
				    step[1][++sp] = 1;
				    step[2][sp] = 3;
				}
				while (a2.empty() == 0 and a2.top() == 1)	
				{
					a3.push(a2.top());
					n3++;
					a2.pop();
				    step[1][++sp] = 2;
				    step[2][sp] = 3;
				}
				while (a2.empty() == 0 and a2.top() == 2)	
				{
					a1.push(a2.top());
					a2.pop();
				    step[1][++sp] = 2;
				    step[2][sp] = 1;
				}
				while (a2.empty() == 0 and a2.top() == 1)	
				{
					a3.push(a2.top());
					n3++;
					a2.pop();
				    step[1][++sp] = 2;
				    step[2][sp] = 3;
				}
				while (a1.empty() == 0 and a1.top() == 2)	
				{
					a2.push(a1.top());
					a1.pop();
				    step[1][++sp] = 1;
				    step[2][sp] = 2;
				}
			}
			while (!a1.empty())	
			{
				a2.push(a1.top());
				a1.pop();
				step[1][++sp] = 1;
				step[2][sp] = 2;
			}
		}
		if (a1.top() == 2)
		{
		    while (1)
		    {
			    if (n3 == m)
				{
					break;
				}    
				while (a1.empty() == 0 and a1.top() == 2)	
				{
					a3.push(a1.top());
					n3++;
					a1.pop();
				    step[1][++sp] = 1;
				    step[2][sp] = 3;
				}
				while (a2.empty() == 0 and a2.top() == 2)	
				{
					a3.push(a2.top());
					n3++;
					a2.pop();
				    step[1][++sp] = 2;
				    step[2][sp] = 3;
				}
				while (a2.empty() == 0 and a2.top() == 1)	
				{
					a1.push(a2.top());
					a2.pop();
				    step[1][++sp] = 2;
				    step[2][sp] = 1;
				}
				while (a2.empty() == 0 and a2.top() == 2)	
				{
					a3.push(a2.top());
					n3++;
					a2.pop();
				    step[1][++sp] = 2;
				    step[2][sp] = 3;
				}
				while (a1.empty() == 0 and a1.top() == 1)	
				{
					a2.push(a1.top());
					a1.pop();
				    step[1][++sp] = 1;
				    step[2][sp] = 2;
				}
			}
			while (!a1.empty())	
			{
				a2.push(a1.top());
				a1.pop();
				step[1][++sp] = 1;
				step[2][sp] = 2;
			}
		}	
	}
	cout << sp << endl;
	for (int i = 1; i <= sp; i++)
	{
		cout << step[1][i] << " " << step[2][i] << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
char ch[1005];
char c[5005];
int s[5005];
int main (){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int T;
	cin >> T;
	while (T--){
		string a;
		cin >> a;
		for (int i=2;i<a.size();++i){
			int w=i;
			while (a[w]==a[w-i]&&w<a.size()) w++;
			if (w==a.size()) w--;
		//	if ((w-i)/i>=1){
				for (int j=0;j<i;++j)
					ch[j]=a[j];
				for (int k=1;k<=(w-i)/i+1)
				for (int j=((w-i)/i+1)*i;j<a.size();++j)
					c[j-w]=a[j];
					for (int j=0;ch[j];++j)
				cout << ch[j];
					cout << endl;
				for (int j=0;c[j];++j)
					cout << c[j];
				cout << endl;
		//	}
		}
	}
	return 0;
}


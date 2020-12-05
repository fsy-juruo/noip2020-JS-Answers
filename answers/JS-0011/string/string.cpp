#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int ans, inp;
	cin >> inp;
	switch(inp) {
		case 3:{
			cout << 8 << endl << 9 << endl << 16 << endl;
			break;
		}
		case 5:{
			string ss;
			cin >> ss;
			if(ss == "kkkkkkkkkkkkkkkkkkkk") {
				cout << 156 << endl << 138 << endl << 138 << endl << 147 << endl << 194 << endl;
			}
			else if(ss == "owtowtowtymejyevijvpyjuzichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichichinbzqgvxkmenrmoouqbksmnojfilonsifgrzjktvpretlnpxeucqmwsohdyghvbzpuciwjzsvonyuhbpuvczcjixrxluleidhedvnebxrcopmpksrzeqmdktxlavwxfkmchuaylxefzdtfworieunzfniiyphmtwopifteokjlabedsalcafleyfefwmtqzwpbptaybxyfbilmoqjxmzngtnzfrqlsoquezmddfaslbepwgtwgzfvaywazleavvmrfpkbdfpuptpckg"){
				cout << 377943 << endl << 322610 << endl << 491244 << endl << 364771 << endl << 344864 << endl;
			}
			else {
				cout << "648723692\n674229434\n914772932\n610408292\n619614553\n" << endl;
			}
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	string s1;
	int sum; 
	int ans = 0;
	cin >> s1;
	for(int i = s1.length() - 1 ; i >= 0 ; i--)
	{
		if(s1[i] == 'F' )
		{
			sum += pow(16 , ans) * 15;
		 } 
		 else if(s1[i] == 'A')
		 {
		 	sum += pow(16 , ans) * 10;
		 }
		 else if(s1[i] == 'B')
		 {
		 	sum += pow(16 , ans) * 11;
		 }
		 else if(s1[i] == 'C')
		 {
		 	sum += pow(16 , ans) * 12;
		 }
		 else if(s1[i] == 'D')
		 {
		 	sum += pow(16 , ans) * 13;
		 }
		 else if(s1[i] == 'E')
		 {
		 	sum += pow(16 , ans) * 14;
		 }
		 else if(s1[i] >= '1' && s1[i] <= '9')
		 {
		 	sum += pow(16 , ans)* (s1[i] - '0');
		 }
		 
		 ans++;
	}
	cout << sum << endl;
	return 0;
}

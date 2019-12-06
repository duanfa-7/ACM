#include <bits/stdc++.h>
using namespace std;
int main()
{
	int h1 , m1 , h2 , m2 , h3 , m3;
	scanf("%d:%d" , &h1 , &m1);
	scanf("%d:%d" , &h2 , &m2);
	if((h2-h1)%2 == 1)
	{
		h3 = (h2+h1)/2;
		m3 = (m1+m2)/2+30;
		if(m3 > 59)
		{
			h3 += 1;
			m3 -= 60;
		}
	}
	else
	{
		h3 = (h1 + h2)/2;
		m3 = (m1+m2)/2;
	}
	printf("%02d:%02d\n" , h3 , m3); 
	return 0;
}

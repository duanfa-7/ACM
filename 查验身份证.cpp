#include <iostream>
#include <string>
using namespace std;
int main()
{    
  string s1 , s2 ;
  int num = 0;
  int sum , N ,flag = 0 , wq = 0;
  s2 = "";
   for(int i = 0 ; i <= 10 ; i++)
  {
  	switch(i)
  	{
  		case '0':s2 += '1';break;
  		case '1':s2 += '0';break;
  		case '2':s2 += 'X';break;
  		case '3':s2 += '9';break;
  		case '4':s2 += '8';break;
  		case '5':s2 += '7';break;
  		case '6':s2 += '6';break;
  		case '7':s2 += '5';break;
  		case '8':s2 += '4';break;
  		case '9':s2 += '3';break;
  		case '10':s2 += '2';break;	
	  }
  }
  scanf("%d" , &N);
   while(N--)
   {
   		
	   	cin >> s1;
	   	flag = 0;
	   	for(int i = 0 ; i <= 16 ; i++)
	   	{
	   		if((s1[i] - '0') <= 9 &&(s1[i] - '0') >= 0)
	   		{
	   			continue;
			}
			else
			{
				flag = 1;
			}
	   		
		}
		cout <<s2[6] << endl;
		printf("s2[6] - '0' = %d" ,(s2[6] - '0' ) );
		printf("flag = %d\n" , flag);
		printf("(s1[17] - '0' ) = %d\n" , s1[17] - '0' );
		printf("s2[s1[17] - '0'] - '0' = %d\n" , s2[s1[17] - '0'] - '0');
	//	if(flag == 1)
	//	{
	//	cout << s1 << endl;
//		}
//		else
		if(flag == 0)
		{
				if((s1[17] - '0' ) == (s2[s1[17] - '0'] - '0'))
			{
				wq++;
			//	
			}
			else
			{
				cout << s1 << endl;
			}
		}
	
	  // 	b[num] = s1;
	   //	num++;
	}
	
	   if(wq == N)
	   {
	   	printf("All passed\n");
	   }
   
    return 0;
}
/*4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
*/


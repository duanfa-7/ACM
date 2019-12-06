 #include <bits/stdc++.h>
 using namespace std;
 int main()
 {
     int t , n , x , y;
     scanf("%d" , &t);
     while(t--)
     {
         string a , b;
         int cnt = 0;
         scanf("%d %d %d" , &n , &x , &y);
        cin >> a >> b;
        for(int i = 0 ; i < n ; i++)
        {
            if(a[i] != b[i])
            {
                cnt++;
            }
        }
       // printf("cnt = %d\n" , cnt);
        if(abs(x-y) <= cnt && (x+y) <= (2*n-cnt) )
        {
            printf("Not lying\n");
        }
        else 
        {
            printf("Lying\n");
        }
     }
     return 0;
 }
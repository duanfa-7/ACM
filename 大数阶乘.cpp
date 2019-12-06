#include <stdio.h>
int carry,n,j;
int a[40001];
int digit;
int temp,i; 
void solve(int n)
{
        a[0]=1;digit=1;
        for(i=2; i<=n; i++)
        {
            for(carry=0,j=1; j<=digit; ++j)                   
            {
                temp=a[j-1]*i+carry;
                a[j-1]=temp%10;
                carry=temp/10;
            }
            while(carry)
            {
                //digit++;
                a[++digit-1]=carry%10;
                carry/=10;
            }
        }
    
        for(int k=digit; k>=1; --k)
            printf("%d",a[k-1]);
        printf("\n");
}
int main()
{
     int a , b;
     scanf("%d %d" , &a , &b);
     int c = min(a , b);
     solve(c);
    
    return 0;
}

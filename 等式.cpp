#include <stdio.h>
int main()
{
    int T , n;
    scanf("%d" , &T);
    while(T--)
    {
        scanf("%d" , &n);
        int ans = 0;
        int i = 2;
        int sum = 1;
        int flag = 0;
        if(n == 1)
        {
            sum = 1;
        }
        else
        {
            flag = 1;
        }
        while(n != 1)
        {
            while(1)
            {
                if(n % i == 0)
                {
                    ans++;
                    n = n / i;
                //  printf("ans = %d n = %d i = %d\n" , ans , n , i);
                }
                else
                {
                    break;
                }
            }
                 
                    sum *= (1 + 2 *ans);//注意我们要求的是n*n = a * b（n*n)的因子数 ， 而此时是n，因此为（1 + 2 * ans)
                //  printf("sum = %d\n" , sum);
                 
                ans = 0 ;
                i++;
             
        }
        printf("%d\n" , (sum + 1)/2 );//sum + 1 的原因是 有当a == b 的时候，原先的sum求的是a , b的个数而一对a*b是一个解，
        //因此需要除以 2；
    }
    return 0;
}

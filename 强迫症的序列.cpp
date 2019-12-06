#include <stdio.h>
int main()
{
    int T , n;
    int a[100050];
    scanf("%d" , &T);
    while(T--)
    {
        scanf("%d" , &n);
        int min = 99999;
        int sum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d" , &a[i]);
            sum +=a[i];
            if(a[i] < min)
            {
                min = a[i];
            }
        }
        printf("%d %d\n" , sum - min * n , sum - min * n + min );
    }
    return 0;
    //莫名其妙的规律
	//将该式翻过来看 将原来小的数加1改为大的数减一
	//最大的数之和减去最小数之和 ，  

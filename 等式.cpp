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
                 
                    sum *= (1 + 2 *ans);//ע������Ҫ�����n*n = a * b��n*n)�������� �� ����ʱ��n�����Ϊ��1 + 2 * ans)
                //  printf("sum = %d\n" , sum);
                 
                ans = 0 ;
                i++;
             
        }
        printf("%d\n" , (sum + 1)/2 );//sum + 1 ��ԭ���� �е�a == b ��ʱ��ԭ�ȵ�sum�����a , b�ĸ�����һ��a*b��һ���⣬
        //�����Ҫ���� 2��
    }
    return 0;
}

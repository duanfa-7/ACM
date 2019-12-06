#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
int main(void)
{
    freopen("d://duipai//data.txt","w",stdout);
    srand(time(NULL));
    int n=2000;
    while(n--)
    {
        printf("%d\n",rand() % 2000);
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
const int eps = 1e-8;
int main()
{
    double H , L;
    scanf("%lf %lf" , &H , &L);
    double h = (L*L-H*H)/(2*H) + eps;
    printf("%.13f\n" , h);
    return 0;
}
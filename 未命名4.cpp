#include<iostream>   
using namespace std;      
const long N = 200000;     
long prime[N] = {0},num_prime = 0;      
int isNotPrime[N] = {1, 1};//先将0，1排除 
int main()      
{        
        for(long i = 2 ; i < N ; i ++)         
        {              
        if(! isNotPrime[i])     //isNotPrime==0            
            prime[num_prime ++]=i;//自己在前面打好了标记。 
        //关键处1           
/*i为合数时也要参与循环*/       for(long j = 0 ; j < num_prime/*小于已经求出的质数个数*/ && i * prime[j]/*乘以其它质数，且质数比自己小或者是自己（已经求出来了），所以不可能重复*/ <  N ; j ++)  
            {                 
                isNotPrime[i * prime[j]] = 1;//乘以其它素数得到的一定是合数，之所以不重复是因为质数间不等 
            if( !(i % prime[j] ) )  //关键处2 i%prime==0  根据“关键处2”的定义，当p1==prime[j] 的时候，
            //筛除就终止了(从最小质数开始所以本句话成立），            
                break;             
        }          
    }          
    return 0;
    //我们可以直观地举个例子。i=2*3*5*3，补大 

//此时能筛除 2*i ,不能筛除 3*i

//如果能筛除3*i 的话，当 i' 等于 i'=3*3*5 加小       时，筛除2*i' 就和前面重复了。（顺序性） 
    
 }

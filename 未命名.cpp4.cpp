#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

bool isoperator(char op);       // 判断是否为运算符
int priority(char op);          // 求运算符优先级
void postfix(char pre[]);       // 把中缀表达式转换为后缀表达式

int main()
{
    char exp[100];
    char post[100];
    memset(post, '\0', sizeof(exp));
    cin >> exp;

    postfix(exp);
    return 0;
}

bool isoperator(char op)
{
    switch(op)
    {
	    case '+':
	    case '-':
	    case '*':
	    case '/':
	    case '|':
		case '&':
	        return 1;
	    default :
	        return 0;
    }
}


int priority(char op)
{
    switch(op)
    {
	    case '#':
	        return -1; 
		case '|':
	    case '&':
	    	return 0;
	    case '(':
	        return 1;
	    case '+':
	    case '-':
	        return 2;
	    case '*':
	    case '/':
	        return 3;
	   
	    default :
	        return -1;
    }
}

//把中缀表达式转换为后缀表达式
void postfix(char pre[])
{
    int i = 0;
    stack<char> OPTR;   //运算符栈
    stack<char> OPND;   //数据栈

    OPTR.push('#');    // 首先把结束标志‘#’放入栈底
    while(pre[i]!='#')
    {
        if((pre[i]>='0' && pre[i] <='9')) // 遇到点直接写入后缀表达式
        {
            OPND.push(pre[i]);
        }
        else if (pre[i]=='(')    // 遇到“（”不用比较直接入栈
            OPTR.push(pre[i]);
        else if(pre[i] ==')')  // 遇到右括号将其对应左括号后的操作符（操作符栈中的）全部写入后缀表达式
        {
            while(OPTR.top()!='(')
            {
                OPND.push(OPTR.top());
                OPTR.pop();
            }
            OPTR.pop(); // 将“（”出栈，后缀表达式中不含小括号
        }
        else if (isoperator(pre[i]))
        {
            while(!OPTR.empty() && priority(pre[i]) <= priority(OPTR.top()))
            {
                // 当前的操作符小于等于栈顶操作符的优先级时，将栈顶操作符写入到后缀表达式，重复此过程
                OPND.push(OPTR.top());
                OPTR.pop();
            }
            OPTR.push(pre[i]);    // 当前操作符栈为空或者当前操作符优先级大于栈顶操作符的优先级，将该操作符入栈
        }

        i++;
    }
    while(OPTR.top() != '#') // 将所有的操作符加入后缀表达式
    {
        OPND.push(OPTR.top());
        OPTR.pop();
    }
    OPTR.pop();

    //利用操作符栈逆序即可得到后缀表达式
    while(!OPND.empty())
    {
        OPTR.push(OPND.top());
        OPND.pop();
    }
    while(!OPTR.empty())
    {
        cout << OPTR.top();
        OPTR.pop();
    }
    cout << endl;
}


#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

bool isoperator(char op);       // �ж��Ƿ�Ϊ�����
int priority(char op);          // ����������ȼ�
void postfix(char pre[]);       // ����׺���ʽת��Ϊ��׺���ʽ

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

//����׺���ʽת��Ϊ��׺���ʽ
void postfix(char pre[])
{
    int i = 0;
    stack<char> OPTR;   //�����ջ
    stack<char> OPND;   //����ջ

    OPTR.push('#');    // ���Ȱѽ�����־��#������ջ��
    while(pre[i]!='#')
    {
        if((pre[i]>='0' && pre[i] <='9')) // ������ֱ��д���׺���ʽ
        {
            OPND.push(pre[i]);
        }
        else if (pre[i]=='(')    // �������������ñȽ�ֱ����ջ
            OPTR.push(pre[i]);
        else if(pre[i] ==')')  // ���������Ž����Ӧ�����ź�Ĳ�������������ջ�еģ�ȫ��д���׺���ʽ
        {
            while(OPTR.top()!='(')
            {
                OPND.push(OPTR.top());
                OPTR.pop();
            }
            OPTR.pop(); // ����������ջ����׺���ʽ�в���С����
        }
        else if (isoperator(pre[i]))
        {
            while(!OPTR.empty() && priority(pre[i]) <= priority(OPTR.top()))
            {
                // ��ǰ�Ĳ�����С�ڵ���ջ�������������ȼ�ʱ����ջ��������д�뵽��׺���ʽ���ظ��˹���
                OPND.push(OPTR.top());
                OPTR.pop();
            }
            OPTR.push(pre[i]);    // ��ǰ������ջΪ�ջ��ߵ�ǰ���������ȼ�����ջ�������������ȼ������ò�������ջ
        }

        i++;
    }
    while(OPTR.top() != '#') // �����еĲ����������׺���ʽ
    {
        OPND.push(OPTR.top());
        OPTR.pop();
    }
    OPTR.pop();

    //���ò�����ջ���򼴿ɵõ���׺���ʽ
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


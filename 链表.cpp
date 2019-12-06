#include<iostream>
 
using namespace std;
typedef int DataType;//使用DataType代替int
//构建一个节点
typedef struct Node
{
	int data; //数据域
	struct  Node *next;  //指针域
}Node, *PNode;
 
//构建一个单链表类
class LinkList
{
public:
	LinkList();                      //构建一个单链表;
	~LinkList();                  //销毁一个单链表;
	void CreateLinkList(int n);   //创建一个单链表
	void TravalLinkList();        //遍历线性表
	int GetLength();              //获取线性表长度
	bool IsEmpty();               //判断单链表是否为空
	PNode Find(DataType data); //查找节点
	void InsertElemAtEnd(DataType data);            //在尾部插入指定的元素
	void InsertElemAtIndex(DataType data, int n);    //在指定位置插入指定元素
	void InsertElemAtHead(DataType data);           //在头部插入指定元素
	void DeleteElemAtEnd();       //在尾部删除元素
	void DeleteAll();             //删除所有数据
	void DeleteElemAtPoint(DataType data);     //删除指定的数据
	void DeleteElemAtHead();      //在头部删除节点
private:
	PNode head;//定义头结点
};
 
 
//初始化单链表
LinkList::LinkList()
{
	head = new Node;//申请一个节点空间
	head->data = 0;  //将头结点的数据域定义为0
	head->next = NULL;  //头结点的下一个定义为NULL
}
 
//销毁一个单链表
LinkList::~LinkList()
{
	delete head;
}
 
//创建一个链表
void LinkList::CreateLinkList(int n)
{
	PNode ptemp=NULL;  //当前节点
	PNode pnew=NULL;   //新的节点
	ptemp = head;//将当前节点设置为头结点
	//ptemp->next = NULL;
	if (head == NULL)
	{
		printf("创建节点失败\n");
		exit(-1);
	}
	if (n < 0)//当输入的节点个数有异时，异常处理
	{
		cout << "输入的节点个数有误" << endl;
		exit(EXIT_FAILURE);
	}
	//将一个个的节点值插入到链表中
	for (int i = 0; i < n; i++)
	{
		pnew = new Node;//为新节点声明一个空间
		cout << "请输入第" << i + 1 << "个值：";
		cin >> pnew->data; //输入节点的值
		ptemp->next = pnew;  //将当前的节点指向下一个新的节点
		pnew->next = NULL;  //将新的节点指向空
		ptemp = pnew; //将新的节点设置成当前节点
	}
}
 
//遍历链表
void LinkList::TravalLinkList()
{
	if (head == NULL || head->next == NULL)
	{
		cout << "链表为空" << endl;
	}
	PNode p = head;//声明一个指针指向头结点
	while (p ->next != NULL)
	{	
		p = p->next;//指向下一个节点,就是有数据的节点
		cout << p->data << " ";//打印数据
	}
}
 
//获取单链表的长度
int LinkList::GetLength()
{
	int count=0;
	if (head == NULL || head->next == NULL)//如果链表为空的话，返回0
	{
		return 0;
	}
	PNode p = head;//声明一个指针指向头结点
	while (p->next != NULL)
	{
		p = p->next;//指向第一个节点
		count++;//计数加1
	}
	return count;
}
 
//判断单链表是否为空
bool LinkList::IsEmpty()
{
	if (head->next == NULL)//如果第一个节点为空的话
	{
		return true;
	}
	return false;
}
 
//在链表的尾部插入节点
void LinkList::InsertElemAtEnd(DataType data)
{
	PNode pnewNode = new Node;//声明一个要插入的节点
	pnewNode->data = data;//尾节点的数据域
	pnewNode->next = NULL;//尾节点的指针域指向空
	PNode p = head;//声明一个指针指向头结点
 
	if (head == NULL)//如果链表是空的话
	{
		head = pnewNode;//将新节点作为头结点
	}
	else
	{
		while (p->next != NULL)//如果第一个节点不为空的话
		{
			p = p->next;//循环找到尾节点
		}
		p->next = pnewNode;//将新的节点插入到尾节点中
	}
}
 
 
//在链表的头部插入节点
void LinkList::InsertElemAtHead(DataType data)
{
	PNode pnewNode = new Node;//声明一个要插入的节点
	pnewNode->data = data;//尾节点的数据域
	PNode p = head;//声明一个指针指向头结点
	if (head == NULL)//如果头结点为空的话
	{
		head= pnewNode;//将新的节点当做是头结点
	}
	pnewNode->next = p->next;//将原先第一个节点的位置赋值给新节点的指针域
	p->next = pnewNode; //将新节点指向头结点的指针域
 
}
 
//在尾部删除数据
void LinkList::DeleteElemAtEnd()
{
	PNode p = head;//声明一个指针指向头结点
	PNode preNode = NULL;//声明一个尾节点的前面一个节点
	if (head->next == NULL)
	{
		cout << "链表为空";
	}
	else
	{
		while (p->next != NULL)//如果第一个节点不为空的话
		{
			preNode = p;//循环找到尾节点的前面一个节点
			p = p->next;//循环找到尾节点
		}
		delete p;//删除尾节点
		preNode->next = NULL;//将倒数第二个节点指向NULL
	}	
}
 
 
//删除所有的数据
void LinkList::DeleteAll()
{
	PNode p = head->next;//声明一个指针指向第一个节点
	PNode ptemp = new Node;//声明一个临时的变量存储要删除的节点
	//如果不是空链表
	while (p!=NULL)//每次都删除第一个节点
	{
		ptemp = p;//先将第一个节点存储起来
		p = p->next;//将下一个节点重新赋给p
		head->next = p;//将第二个节点连接上头结点
		ptemp->next = NULL;//将第一个节点指向空
		delete ptemp;//删除第一个节点
	}
	head->next = NULL;//删除完了之后将头结点指向空
}
 
//在头部删除节点
void LinkList::DeleteElemAtHead()
{
 
	PNode p = head->next;//声明一个指针指向第一个节点
	PNode ptemp = new Node;//声明一个临时的变量存储要删除的节点
	//如果是空链表的话
	if (p == NULL)
	{
		cout << "链表为空" << endl;
	}
	else//链表不为空
	{
		ptemp = p;//先将第一个节点存储起来
		p = p->next;//将下一个节点重新赋给p
		head->next = p;//将第二个节点连接上头结点
		ptemp->next = NULL;//将第一个节点指向空
		delete ptemp;//删除第一个节点
	}
}
 
//在指定的位置插入指定的元素,这里不包括头尾
void LinkList::InsertElemAtIndex(DataType data, int n)
{
	int len = GetLength();//获取链表的长度
	if (n<1 || n>(len + 1))
	{
		cout << "输入的值有错误" << endl;
	}
	//如果插入到链表的头部
	else if (n == 1)
	{
		InsertElemAtHead(data);//调用写好的函数
	}
 
	else if (n == (len + 1))//插入到尾部
	{
		InsertElemAtEnd(data);
	}
	//在中间插入的情况
	else
	{
		PNode ptemp = new Node;        //创建一个新的节点
		ptemp->data = data;                     //定义数据域
		PNode  p = head;                    //创建一个指针指向头结点
		int i = 1;
		while (n>i)//遍历到指定的位置,如果n=2的话，那么p就是遍历到第一个节点
		{
			p = p->next;
			i++;
		}
		ptemp->next = p->next;
		p->next = ptemp;
	}
}
 
//查找指定的元素的位置
PNode LinkList::Find(DataType data)
{
	PNode p = head;//将头结点赋值给p
	if (p == NULL)
	{
		cout << "此链表为空链表" << endl;
		return NULL;
	}
	else
	{
		while (p->next!=NULL)//循环判断每一个节点
		{
			if (p->data == data)
			{
				return p;
			}
			p = p->next;
		}
		return NULL;//未查询到结果
	}
 
}
//删除指定的节点,在原来的节点中没有重复元素的情况下
void LinkList::DeleteElemAtPoint(DataType data)
{
	PNode ptemp = Find(data);//找到指定元素的节点位置
	if (ptemp == NULL)
	{
		cout << "没有找到要删除的节点元素" << endl;
	}
	else if(ptemp==head->next)//如果是第一个节点元素
	{
		DeleteElemAtHead();
	}
	else
	{
		PNode p = head;//声明一个指针域指向头结点
		while (p->next != ptemp)//p循环到指定节点的前面一个节点
		{
			p = p->next;
		}
		p->next = ptemp->next;
		ptemp->next = NULL;
		delete ptemp;
	}
}
int main()
{
	LinkList list;//实例化
	cout << "请输入单链表的长度：";
	int n;
	cin >> n;
	list.CreateLinkList(n);//创建链表
	list.TravalLinkList();//打印链表
	cout << endl;
	//cout << "链表的长度是："<< list.GetLength()<<endl;
	//list.DeleteElemAtEnd();
	//list.TravalLinkList();//打印链表
	//list.InsertElemAtEnd(6);//将6插入到链表的尾部
	//list.TravalLinkList();//打印链表
	//list.InsertElemAtHead(4);//将4插入到链表的头
	//list.TravalLinkList();//打印链表
	//list.DeleteAll();//删除所有的节点
	//list.DeleteElemAtHead();//删除头部节点
	//list.TravalLinkList();//打印链表
	//list.InsertElemAtIndex(6, 3);//在指定的位置插入指定的节点
	//list.TravalLinkList();//打印链表
	//PNode temp = list.Find(2);//查询指定节点
	//cout << temp->data << endl;
	list.DeleteElemAtPoint(2);
	list.TravalLinkList();
	return 0;
}
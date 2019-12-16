#include<iostream>		
#include<set>
#include<string>
using namespace std;
struct Node {
	char C;			//代表编码符号
	double times;	//该字符出现的频率
	Node*Left, *Right;
	bool operator<(const Node A)const{	//重载运算符<
		 return this->times==A.times?this->C<A.C:this->times<A.times;
	}
};
typedef Node*HuffTree;
HuffTree init(HuffTree H, Node N) {	//用Node类型初始化HuffTree类型变量
	H->C = N.C;
	H->times = N.times;
	H->Left = N.Left;
	H->Right = N.Right;
	return H;
}
void MakeHuffCode(HuffTree &H,string S) {	//递归编码
	if (!H)return;
	if (H->C != '-')cout << H->C << " " << S<<endl;
	MakeHuffCode(H->Left, S + "0");
	MakeHuffCode(H->Right, S + "1");
}
int main() {
	set<Node>S;
	int N;		//需编码的元素个数;
	cout << "请输入要编码的元素个数\n";
	cin >> N;
	Node tmp;
	cout << "请输入"<<N<<"组要编码的符号以及该符号对应的频率，中间以空格分开\n";
	for (int i = 0; i < N; i++) {
		/*tmp = new Node();*/
		tmp.Left = NULL;
		tmp.Right = NULL;
		cin >> tmp.C>>tmp.times;
		S.insert(tmp);
	}
	HuffTree R = NULL;//标记最终结果结点;
	while (S.size()>1) {
		HuffTree H = new Node();
		HuffTree tmp1 = new Node(); tmp1=init(tmp1, *S.begin());//取S的前两个元素分别为tmp1,tmp2
		HuffTree tmp2 = new Node(); tmp2=init(tmp2, *(++S.begin()));
		S.erase(S.begin());
		S.erase(S.begin());
		H->Left = tmp1;
		H->Right = tmp2;
		H->times = tmp1->times + tmp2->times;
		H->C = '-';
		Node T;
		T.C = H->C;
		T.times = H->times;
		T.Left = H->Left;
		T.Right = H->Right;
		S.insert(T);	//哈弗曼方法创建的新节点插回原序列
		R = H;
	}
	cout << "编码结果为：" << endl;
	// author: 201700671 wangfuzhen  jike 11702
	MakeHuffCode(R, "");	//递归编码；
	return 0;
}

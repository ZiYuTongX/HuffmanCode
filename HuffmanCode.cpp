#include<iostream>		
#include<set>
#include<string>
using namespace std;
struct Node {
	char C;			//����������
	double times;	//���ַ����ֵ�Ƶ��
	Node*Left, *Right;
	bool operator<(const Node A)const{	//���������<
		 return this->times==A.times?this->C<A.C:this->times<A.times;
	}
};
typedef Node*HuffTree;
HuffTree init(HuffTree H, Node N) {	//��Node���ͳ�ʼ��HuffTree���ͱ���
	H->C = N.C;
	H->times = N.times;
	H->Left = N.Left;
	H->Right = N.Right;
	return H;
}
void MakeHuffCode(HuffTree &H,string S) {	//�ݹ����
	if (!H)return;
	if (H->C != '-')cout << H->C << " " << S<<endl;
	MakeHuffCode(H->Left, S + "0");
	MakeHuffCode(H->Right, S + "1");
}
int main() {
	set<Node>S;
	int N;		//������Ԫ�ظ���;
	cout << "������Ҫ�����Ԫ�ظ���\n";
	cin >> N;
	Node tmp;
	cout << "������"<<N<<"��Ҫ����ķ����Լ��÷��Ŷ�Ӧ��Ƶ�ʣ��м��Կո�ֿ�\n";
	for (int i = 0; i < N; i++) {
		/*tmp = new Node();*/
		tmp.Left = NULL;
		tmp.Right = NULL;
		cin >> tmp.C>>tmp.times;
		S.insert(tmp);
	}
	HuffTree R = NULL;//������ս�����;
	while (S.size()>1) {
		HuffTree H = new Node();
		HuffTree tmp1 = new Node(); tmp1=init(tmp1, *S.begin());//ȡS��ǰ����Ԫ�طֱ�Ϊtmp1,tmp2
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
		S.insert(T);	//�����������������½ڵ���ԭ����
		R = H;
	}
	cout << "������Ϊ��" << endl;
	// author: 201700671 wangfuzhen  jike 11702
	MakeHuffCode(R, "");	//�ݹ���룻
	return 0;
}

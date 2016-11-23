/*
�ۼ���: ���Ǵ��б� ����Ʈ�����к� ���� 20150279 ������
������: 2016.11.24
Graph Coloring Problem with Backtracking Algorithm
��: ��ü ��� �� n, ���� �� m, �������W[n][n]
��: ���� vcolor[1]~vcolor[n]�� ����
Problem: m���� ���� ����Ͽ�, �׷����� ������ ���� �Ҵ��� �� �ִ� ��� ����� �����϶�. ��, ������ ������ ���� ���� ���� ���� �� ����.
Inputs: n(������ ��), m(���� ��), W[1..n][1..n](�׷���,W[i][j] = 1(TRUE) = > i������ j�������̿� ������ ����)
Outputs: vcolor[1..n]
*/

#include <iostream>
using namespace std;

void m_coloring(int i);
bool promising(int i);

#define n 4
int m = 1;	//���� �ʱ�ȭ
int e = 0;	//���� �ʱ�ȭ
int x, y = 0;	//�ε���
bool W[n+1][n+1];
int vcolor[n+1];
int cases = 0;	//�� ����� ��
bool cs;	//���� stop ����


int main()
{
	cout << "����� ���� 25�� graph coloring ����" << endl;
	cout << "������ 25���� ����(�ʿ� �� ��ȣ��� ������ ����)" << endl;
	cout << "�� ������ 1������ ����" << endl << endl;

	cout << "���� ���� �Է� =  ";
	cin >> e;
	cout << endl << "���� �Է� (���� ���� - [��][space][��]) :" << endl;

	for (int i = 0; i < e; i++) {
		cin >> x >> y;
		W[x][y] = W[y][x] = true;
	}
	cout << "�Է� �Ϸ�(������ �ε��� ���� ��� 0)" << endl;
	
	cs = false;
	while (!cs) {
		m_coloring(0);
		m++;
	}

	cout << endl << endl << "�� ����� �� = " << cases << endl;
	cout << endl  << " �ּ� ���� �� = " << m - 1 << endl << endl;


	return 0;
}

void m_coloring(int i) {
	if (promising(i)) 
		if (i == n) {
			cs = true;
			cases++;
/*
			for (int L = 1; L <= n; L++) {
				cout << "vcolor[" << L << "] = " << vcolor[L] << endl;
			}
*/
		}
		else 
			for (int color = 1; color <= m; color++) {
				vcolor[i + 1] = color;
				m_coloring(i+1);
			}
}

bool promising(int i) {
	int j = 1; 
	bool s = true;
	
	while (j<i && s) {
		if (W[i][j] && vcolor[i] == vcolor[j]) 
			s = false;		
		j++;
	}
	return s;
}
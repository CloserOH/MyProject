/*
작성자: 숭실대학교 소프트웨어학부 나반 20150279 조현하
제출일: 2016.11.24
Graph Coloring Problem with Backtracking Algorithm
入: 전체 노드 수 n, 색깔 수 m, 인접행렬W[n][n]
出: 색깔 vcolor[1]~vcolor[n]의 조합
Problem: m개의 색을 사용하여, 그래프의 정점의 색을 할당할 수 있는 모든 방법을 결정하라. 단, 인접한 정점은 서로 같은 색을 가질 수 없다.
Inputs: n(정점의 수), m(색의 수), W[1..n][1..n](그래프,W[i][j] = 1(TRUE) = > i정점과 j정점사이에 간선이 있음)
Outputs: vcolor[1..n]
*/

#include <iostream>
using namespace std;

void m_coloring(int i);
bool promising(int i);

#define n 4
int m = 1;	//색깔 초기화
int e = 0;	//간선 초기화
int x, y = 0;	//인덱스
bool W[n+1][n+1];
int vcolor[n+1];
int cases = 0;	//총 경우의 수
bool cs;	//색상 stop 조건


int main()
{
	cout << "서울시 지도 25구 graph coloring 문제" << endl;
	cout << "정점은 25개로 고정(필요 시 기호상수 값에서 변경)" << endl;
	cout << "색 개수는 1개부터 시작" << endl << endl;

	cout << "간선 개수 입력 =  ";
	cin >> e;
	cout << endl << "간선 입력 (패턴 참조 - [행][space][열]) :" << endl;

	for (int i = 0; i < e; i++) {
		cin >> x >> y;
		W[x][y] = W[y][x] = true;
	}
	cout << "입력 완료(나머지 인덱스 값은 모두 0)" << endl;
	
	cs = false;
	while (!cs) {
		m_coloring(0);
		m++;
	}

	cout << endl << endl << "총 경우의 수 = " << cases << endl;
	cout << endl  << " 최소 색의 수 = " << m - 1 << endl << endl;


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
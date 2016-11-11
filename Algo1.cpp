//알고리즘 과제1 2016.09.22 제출
//소프트웨어학부 나반 20150279 조현하

#include <iostream>
#define N 100
#define L 2000
using namespace std;

void seqsearch(int n, const int S[], int x, int &location);
void binsearch(int n, const int S[], int x, int &location);
int fib1(int n);
int fib2(int n);
void mergesort(int n, int S[]);
void merge(int h, int m, const int U[], const int V[], int S[]);

//void quicksort(int arr[], int left, int right);
void quicksort(int low, int high, int S[]);
void partition(int low, int high, int &pivotpoint, int S[]);


int iter = 0;	//시간복잡도 측정 전역 변수

int main()
{
	int i;
	cout << "****알고리즘 선택 시 결과값과 시간복잡도 출력****" << endl;
	cout << "1.순차탐색 2.이원탐색 3.재귀피보나치 4.반복피보나치 5.합병정렬 6.퀵정렬" << endl;
	cout << "실행 알고리즘 번호 입력 : ";
	cin >> i;

	if (i == 1) {
		int n;
		int search[N] = { 0 };
		cout << endl << "***순차탐색 실행***" << endl;
		cout << "탐색 값 입력 : ";
		cin >> n;
		cout << "크기 입력 : ";

		seqsearch(N, search, n, i);
		cout << endl << n << "값 탐색 실패" << endl;
	}

	else if (i == 2) {
		int n;
		int search[N] = { 0 };
		cout << endl << "***이원탐색 실행***" << endl;
		cout << "탐색 값 입력 : ";
		cin >> n;
		binsearch(N, search, n, i);
		cout << endl << n << "값 탐색 실패" << endl;
	}

	else if (i == 3) {
		int n;
		cout << endl << "***재귀피보나치 실행***" << endl;
		cout << "n번째 항 입력 : ";
		cin >> n;
		cout << endl << "f(" << n << ") = " << fib1(n-1) << endl;
	} 

	else if (i == 4) {
		int n;
		cout << endl << "***반복피보나치 실행***" << endl;
		cout << "n번째 항 입력 : " << endl;
		cin >> n;
		cout << endl << "f(" << n << ") = " << fib2(n-1) << endl;
	}

	else if (i == 5) {
		int sort[L];
		for (int i = 0; i < L; i++) 
			sort[i] = L-i;
		/*
		cout << endl << "***합병정렬 실행***" << endl;
		cout << endl << "정렬이전 : " << endl;
		for (int i = 0; i < L; i++)
			cout << sort[i] << " ";
		cout << endl;
		*/
		mergesort(L, sort);
		/*
		cout << endl << "정렬이후 : " << endl;
		for (int i = 0; i < L; i++)
			cout << sort[i] << " ";
		cout << endl;
		*/
	}

	else if (i == 6) {
		int sort[L];
		for (int i = 0; i < L; i++)
			sort[i] = L-i;
		/*
		cout << endl << "***퀵정렬 실행***" << endl;
		cout << endl << "정렬이전 : " << endl;
		for (int i = 0; i < L; i++)
			cout << sort[i] << " ";
		cout << endl;
		*/
		quicksort(0, L - 1, sort);
		/*
		cout << endl << "정렬이후 : " << endl;
		for (int i = 0; i < L; i++)
			cout << sort[i] << " ";
		cout << endl;
		*/
	}

	else return -1;

	cout << endl << "시간복잡도 : " << iter << endl << endl;

	return 0;
}

void seqsearch(int n, const int S[], int x, int &location) {
	location = 0;
	while (location < n && S[location] != x) {
		location++;
		iter++;
	}

	if (location >= n)
		location = 0;
}

void binsearch(int n, const int S[], int x, int &location) {
	int low = 0, high = n-1, mid;
	location = 0;
	while (low <= high && location == 0) {
		mid = (low + high) / 2;// 정수나눗셈
		iter++;
		if (x == S[mid]) 
			location = mid;
		else if (x < S[mid]) 
			high = mid - 1;
		else 
			low = mid + 1;
	}
}

int fib1(int n) {
	iter++;
	if (n <= 1)
		return n;
	else
		return fib1(n - 1) + fib1(n - 2);
}

int fib2(int n) {
	int i;
	int f[N];
	f[0] = 0;
	if (n > 0) {
		f[1] = 1;
		for (i = 2; i <= n; i++) {
			f[i] = f[i - 1] + f[i - 2];
			iter++;
		}
	}
	return f[n];
}

void mergesort(int n, int S[]) {
	if (n > 1) {
		const int h = n / 2, m = n - h;	
		int *U = new int[h];
		int *V = new int[m];

		//copy S[1] through S[h] to U[1] through U[h];
		for (int i = 0; i < h; i++)
			U[i] = S[i];
		//copy S[h + 1] through S[n] to V[1] through V[m];
		for (int i = 0; i < m; i++)	
			V[i] = S[h+i];
		mergesort(h, U);
		mergesort(m, V);
		merge(h, m, U, V, S);
	}
}

void merge(int h, int m, const int U[], const int V[], int S[]) {
	int i, j, k;
	i = 0; j = 0; k = 0;
	while (i <= h && j <= m) {
		if (U[i] < V[j]) {
			S[k] = U[i];
			i++;
		}
		else {
			S[k] = V[j];
			j++;
		}
		k++;
		iter++;
	}
	if (i > h)
		//copy V[j] through V[m] to S[k] through S[h + m];
		while (j < m) {
			S[k++] = V[j++];
			iter++;
		}
	else
		//copy U[i] through U[h] to S[k] through S[h + m];
		while (i < h) {
			S[k++] = U[i++];
			iter++;
		}	
}

void quicksort(int low, int high, int S[]) {
	int pivotpoint;
	if (high > low) {
		partition(low, high, pivotpoint, S);
		quicksort(low, pivotpoint - 1, S);
		quicksort(pivotpoint + 1, high, S);
	}
}

void partition(int low, int high, int &pivotpoint, int S[]) {
	int i, j, tmp;
	int pivotitem;
	pivotitem = S[low];//pivotitem을위한첫번째항목을고른다
	j = low;
	for (i = low + 1; i <= high; i++)
		if (S[i] < pivotitem) {
			j++;
			//exchange S[i] and S[j]
			tmp = S[i];
			S[i] = S[j];
			S[j] = tmp;
			iter++;
		}
	pivotpoint = j;
	//exchange S[low] and S[pivotpoint] // pivotitem 값을pivotpoint에
	tmp = S[low];
	S[low] = S[pivotpoint];
	S[pivotpoint] = tmp;
}

/*
void quicksort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	//partition 
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
		iter++;
	}

	// recursion 
	if (left < j)
		quicksort(arr, left, j);
	if (i < right)
		quicksort(arr, i, right);
}
*/
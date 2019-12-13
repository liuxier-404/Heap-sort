#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int heap[10000];
int nowlength;
void swap(int*a, int*b) {
	int m = *a;
	*a = *b;
	*b = m;
}
void sort_dad(int dad, int nw) {
	int lchild = dad * 2;
	int rchild = dad * 2 + 1;
	if (lchild > nw)
		return;
	else if (rchild > nw) {
		if (heap[lchild] > heap[dad])
			swap(&heap[lchild], &heap[dad]);
		return;
	}
	else {
		if (heap[dad] >= heap[lchild] && heap[dad] >= heap[rchild])
			return;
		int* max;
		if (heap[dad] < heap[rchild])
			max = &heap[rchild];
		else max = &heap[dad];
		if (*max < heap[lchild])
			max = &heap[lchild];
		swap(max, &heap[dad]);
		sort_dad(lchild, nw);
		sort_dad(rchild, nw);
		return;
	}
}
void heap_sort(int nw) {
	int lastdad = nw / 2;
	for (int i = lastdad; i >= 1; i--) {
		sort_dad(i, nw);
	}
}
void printHeap(int nw) {
	for (int i = 1; i <= nw; i++)
		printf("%d ", heap[i]);
	printf("\n");
}
int main() {
	int total;
	scanf("%d", &total);
	nowlength = total;
	for (int i = 0; i < total; i++) {
		scanf("%d", &heap[i + 1]);
	}
	int times = 1;
	while (nowlength > 1) {
		heap_sort(nowlength);
		if (times++<= 3)
			printHeap(nowlength);
		swap(&heap[1], &heap[nowlength]);
		nowlength--;
	}
}

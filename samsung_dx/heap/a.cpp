#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_INPUT 10000
#define MAX_NUM 30000
#define HEAP_SIZE 100001

extern void init();
extern void addUser(int uID, int income);
extern int getTop10(int result[10]);

static int input[MAX_INPUT];

static unsigned int seed = 13410;

static unsigned int pseudoRand() {
	seed = seed * 214013 + 2531011;
	return (unsigned int)(seed >> 11) % MAX_NUM;
}

static void makeInput(int inputLen) {
	for (int i = 0; i < inputLen; i++) {
		input[i] = pseudoRand();
	}
}

static int run() {
	int N, userNum, uID = 0;
	int score = 100, result[10], cnt;
	int sum, check;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &userNum);
		makeInput(userNum);
		for (int j = 0; j < userNum; j++) {
			addUser(uID++, input[j]);
		}
		cnt = getTop10(result);

		sum = 0;
		for (int j = 0; j < cnt; j++)
			sum += result[j];
		scanf("%d", &check);
		if (check != sum)
			score = 0;
	}
	return score;
}

struct element {
	int uid;
    int income;

    bool operator < (element e) {
     	if(income == e.income) {
         	return uid > e.uid;
        }
        return income < e.income;
    }

        bool operator > (element e) {
     	if(income == e.income) {
         	return uid < e.uid;
        }
        return income > e.income;
    }
};

typedef struct {
	element heap[HEAP_SIZE];
	int heapSize;
} Heap;

void heapPush(Heap* h, element item)
{
	int idx = ++(h->heapSize);

	while ((idx != 1) && (h->heap[idx / 2] < item))
	{
		h->heap[idx] = h->heap[idx / 2];
		idx /= 2;
	}

	h->heap[idx] = item;
}

element heapPop(Heap *h)
{
	element item = h->heap[1];
	element temp = h->heap[(h->heapSize)--];
	int parent = 1;
	int child = 2;

	while (child <= h->heapSize)
	{
		if (child < h->heapSize && h->heap[child] < h->heap[child + 1])
			child++;
		if (temp > h->heap[child]) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}

	h->heap[parent] = temp;
	return item;
}

element heapPeek(Heap* h) { return h->heap[1]; }
int heapSize(Heap* h) { return h->heapSize; }
bool isHeapEmpty(Heap* h) { return h->heapSize == 0; }
void heapInit(Heap* h) { h->heapSize = 0; }
Heap h;

void init()
{
	heapInit(&h);
}

void addUser(int uID, int height)
{
	element e;
    e.uid = uID;
    e.income = height;
    heapPush(&h, e);
}

int getTop10(int result[10])
{
    int k = 10;
    element tmp[10];
    while(!isHeapEmpty(&h) && k--) {
    	element maxValue = heapPop(&h);
			 result[10-k] = maxValue.uid;
       tmp[10-k] = maxValue;
    }

    for(int i = 0; i < 10 - k; i++) {
        heapPush(&h,tmp[i]);
    }

    return 10 - k;
}

int main(void) {
	setbuf(stdout, NULL);
	// freopen("partial_sort_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		init();
		printf("#%d %d\n", tc, run());
	}
	return 0;
}

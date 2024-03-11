#define _CRT_SECURE_NO_WARNINGS
#define INF 0x3f3f3f3f
#include <iostream>
#include <math.h>

using namespace std;

struct Info {
	int A;
	int idx;

	bool operator<(Info right) const {
		if (A < right.A) return true;
		if (A > right.A) return false;

		if (idx <= right.idx) return true;
		else return false;
	}
};

// 2^ceil(log2(100000)+1) 262144
int N, Q;
int arr[100001];
Info tree[400001];

//Info min(Info x, Info y) {
//	if (x.A != y.A) return (x.A < y.A) ? x : y; 
//	else return (x.idx < y.idx) ? x : y; 
//}

Info init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = { arr[start],start };
	}
	else {
		int mid = (start + end) / 2;
		tree[node] = min(init(node * 2, start, mid),init(node * 2 + 1, mid + 1, end));
		return tree[node];
	}
}

void update(int node, int start, int end, int target) {
	if (target < start || target > end) return;

	
	if (start == end) {
		if (start == target)
			tree[node] = { arr[target],target };
		return;
	}
	

	
	int mid = (start + end) / 2;
	update(node * 2, start, mid,target);
	update(node * 2 + 1, mid + 1, end,target);
	
	tree[node] = min(tree[node*2],tree[node*2+1]);
}

Info search(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return { INF,INF };

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	Info l = search(node * 2, start, mid, left, right);
	Info r = search(node * 2 + 1, mid + 1, end, left, right);

	return min(l, r);
}

int main() {

	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	
	init(1, 1, N);

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int command;
		cin >> command;

		if (command == 1) {
			int ai, v;
			cin >> ai >> v;
			arr[ai] = v;
			update(1, 1, N,ai);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << search(1, 1, N, l, r).A << "\n";
		}
	}

}
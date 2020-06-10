#ifndef REDBLACK_H
#define REDBLACK_H

const int black = 0;
const int red = 1;

#define	MAX_STRKEY_LEN	20

class Node {
public:
	Node(int bb, int k, int i, Node *ll, Node *rr) {
		b = bb, key = k; index = i, l = ll, r = rr;
		//b는 노드의 색깔. Red=1 or black=0 으로 표시한다.  key는 노드에 저장되어 있는 값을 말한다. index는 출력시 번호를 매기기 위한 변수. l은 노드의 왼쪽 자식노드, r은 노드의 오른쪽 자식 노드 
	};
	int b;			// 노드 색깔을 나타내는 변수
	int key;		// 키 값을 나타내는 변수
	int index; //출력시 번호를 매기기 위한 변수
	Node *l, *r; //자식노드. 포인터로 연결
};

class IntRBTree {
public:
	IntRBTree(); //RB 트리를 초기화하는 함수
	Node *search(int search_key); //RB 트리를 탐색하는 함수
	void insert(int v, int index); //노드를 삽입하는 함수
	void split(int v, int index); //트리를 수선하는 함수
	Node *rotate(int v, Node *y,int index); //노드들을 회전시키는 함수. 
	void print_tree_fun(Node *root, int space,int flag); //트리를 출력하는 함수
	void print_tree(Node *root); //트리 출력을 위한 설정을 하는 함수
	
private:
	Node *head, *z, *gg, *g, *p, *x; //head: root노드 z: leaf노드, gg: 삽입된 노드의 부모노드의 부모노드, p: 삽입된 노드의 부모노드, x: 현재 노드 
};

#endif

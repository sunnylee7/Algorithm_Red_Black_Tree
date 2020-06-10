#ifndef REDBLACK_H
#define REDBLACK_H

const int black = 0;
const int red = 1;

#define	MAX_STRKEY_LEN	20

class Node {
public:
	Node(int bb, int k, int i, Node *ll, Node *rr) {
		b = bb, key = k; index = i, l = ll, r = rr;
		//b�� ����� ����. Red=1 or black=0 ���� ǥ���Ѵ�.  key�� ��忡 ����Ǿ� �ִ� ���� ���Ѵ�. index�� ��½� ��ȣ�� �ű�� ���� ����. l�� ����� ���� �ڽĳ��, r�� ����� ������ �ڽ� ��� 
	};
	int b;			// ��� ������ ��Ÿ���� ����
	int key;		// Ű ���� ��Ÿ���� ����
	int index; //��½� ��ȣ�� �ű�� ���� ����
	Node *l, *r; //�ڽĳ��. �����ͷ� ����
};

class IntRBTree {
public:
	IntRBTree(); //RB Ʈ���� �ʱ�ȭ�ϴ� �Լ�
	Node *search(int search_key); //RB Ʈ���� Ž���ϴ� �Լ�
	void insert(int v, int index); //��带 �����ϴ� �Լ�
	void split(int v, int index); //Ʈ���� �����ϴ� �Լ�
	Node *rotate(int v, Node *y,int index); //������ ȸ����Ű�� �Լ�. 
	void print_tree_fun(Node *root, int space,int flag); //Ʈ���� ����ϴ� �Լ�
	void print_tree(Node *root); //Ʈ�� ����� ���� ������ �ϴ� �Լ�
	
private:
	Node *head, *z, *gg, *g, *p, *x; //head: root��� z: leaf���, gg: ���Ե� ����� �θ����� �θ���, p: ���Ե� ����� �θ���, x: ���� ��� 
};

#endif

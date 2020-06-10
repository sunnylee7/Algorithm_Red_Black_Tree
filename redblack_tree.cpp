#include <stdio.h>
#include <string>
#include "redblack_tree.h"
using namespace std;
#define BLANK 14 //공백(트리간 간격)을 출력하기 위한 변수

//작성자:1812313 이현선

int main()
{
	printf("Red Black Tree 삽입 프로젝트 시작합니다\n 10, 15, 30, 52, 40, 35, 38, 39, 7, 9, 6를 차례대로 삽입합니다.\n\n");
	printf("트리의 모양은 옆으로 뉘어진 형태로 출력됩니다.\n노드 옆의 [R]은 노드의 색이 red를, [B]은 노드의 색이 black이라는 정보를 나타냅니다.\n\n");
	printf("트리 구축과정을 단계별로 출력합니다(트리에 변화 있을 시 출력).\n 더 자세한(알고리즘 수행과정과 코드 상세 설명)은 파일 코드 내의 주석을 참고해주세요\n\n");

	int index = 0;
	IntRBTree rbt; //IntRBTree 객체 생성
	
	printf("첫번째 단계: 초기화하기\n\n");
	//IntRBTree(); RB 트리 초기화 자동으로 수행

	printf("<<<숫자 10 삽입하기>>>\n");
	rbt.insert(10, 0); // RB트리에 숫자 10을 삽입

	printf("<<<숫자 15 삽입하기>>>\n");
	rbt.insert(15, 0); // RB트리에 숫자 15을 삽입


	printf("<<<숫자 30 삽입하기>>>\n");
	rbt.insert(30, 0); // RB트리에 숫자 30을 삽입
	
	printf("<<<숫자 52 삽입하기>>>\n");
	rbt.insert(52, 0); // RB트리에 숫자 52을 삽입
	

	printf("<<<숫자 40 삽입하기>>>\n");
	rbt.insert(40, 0); // RB트리에 숫자 40을 삽입
	

	printf("<<<숫자 35 삽입하기>>>\n");
	rbt.insert(35, 0); // RB트리에 숫자 35을 삽입
	

	printf("<<<숫자 38 삽입하기>>>\n");
	rbt.insert(38, 0); // RB트리에 숫자 38을 삽입
	

	printf("<<<숫자 39 삽입하기>>>\n");
	rbt.insert(39, 0); // RB트리에 숫자 39을 삽입
	

	printf("<<<숫자 7 삽입하기>>>\n");
	rbt.insert(7, 0); // RB트리에 숫자 7을 삽입
	

	printf("<<<숫자 9 삽입하기>>>\n");
	rbt.insert(9, 0); // RB트리에 숫자 9을 삽입
	

	printf("<<<숫자 6 삽입하기>>>\n");
	rbt.insert(6, 0); // RB트리에 숫자 6을 삽입
	

	/*삽입 알고리즘 수행과정
<10 삽입>
	 1. x는 head를 가리키므로, x노드가  루트이다.
	 2. x = (x->key > v) ? x->l : x->r;  x 의 키가 v(10) 보다 작으므로 , x에 x의 오른쪽 자식노드를 저장한다. 즉, 오른쪽으로 이동
	 3. (x->l->b && x->r->b)에 해당하지 않으므로 다음단계 수행
	 4. x = new Node(red, v, index, z, z);  삽입된 숫자로 새 노드를 만든다.
	 5. if (p->key > v) p->l = x; 부모노드는 루트노드. p의 key값은 0이므로, v의 값이 더 크다. 따라서 x노드를 루트의 오른쪽자식으로 삽입한다.
	 6. head->r->b = black; 루트노드가 red이므로 black으로 바꿔준다.
	 *spilt함수는 들어가지만, 조건에 해당하지 않아 빠져나온다.
	
<15 삽입>
	 1.  x = (x->key > v) ? x->l : x->r;  x의 key값(10)이 v(15)보다 작으므로, x에 x의 오른쪽 자식노드를 저장한다. 즉, 오른쪽으로 이동
	 2.  x = new Node(red, v, index, z, z);  삽입된 숫자로 새 노드를 만든다.
	 3.  if (p->key > v) p->l = x; 부모노드의 key값은 10이므로, 15의 값이 더 크다. 따라서 15 노드를 10노드의 오른쪽자식으로 삽입한다.
	 4. head->r->b = black;  루트노드가 black이므로 해당사항 없다.

<30삽입>
	 1.  x = (x->key > v) ? x->l : x->r;  x의 key값(10)이 v(30)보다 작으므로, x에 x의 오른쪽 자식노드를 저장한다. 즉, 오른쪽으로 이동 또, 15가 30보다 작으므로, 오른쪽으로 이동
	 2.  x = new Node(red, v, index, z, z);  삽입된 숫자로 새 노드를 만든다.
	 3. if (p->key > v) p->l = x; 부모노드의 key값은 15이므로, 30의 값이 더 크다. 따라서 30 노드를 15노드의 오른쪽자식으로 삽입한다.
	 4. this->split(v,index); spilt 함수로 들어간다.
	 5. if (p->b) 30의 부모노드(15)가 red이므로 red인 노드가 연속하여 RB tree의 규칙에 어긋난다 *Case 4 인경우(교재에서는 Case 2-2)
	 6. 두노드의 상위노드인 10노드의 색을 red로 바꾼다.
	 7. Case4이므로, 15를 중심으로 왼쪽으로 회전한다.
	 8. 15의 색을 black으로 바꿔준다.


<52삽입>
	 1. x = (x->key > v) ? x->l : x->r;  x의 key값(15)이 v(52)보다 작으므로, x에 x의 오른쪽 자식노드를 저장한다. 즉, 오른쪽으로 이동 또, 30이 52보다 작으므로 또, 오른쪽으로 이동한다.
	 2. if (x->l->b && x->r->b) 이므로, 즉, 삽입하려는 노드의 부모와 부모의 형제가 red인 경우로, Case 2에 해당(교재에서는 Case1)
	 3. this->split(v, index); spilt 함수로 들어간다.
	 4.  (x->b == black) 15노드의 색이 black이므로, 
		x->b = red; x->l->b = black; x->r->b = black;  수행. 15노드를 red로 바꾸고, 왼쪽과 오른쪽 자식노드의 색을 black으로 바꾼다.  
	 5. x = new Node(red, v, index, z, z);  삽입된 숫자로 새 노드를 만든다.
	 6. if (p->key > v) p->l = x; 부모노드의 key값은 30이므로, 52의 값이 더 크다. 따라서 52 노드를 30노드의 오른쪽자식으로 삽입한다.
	 7. head->r->b = black; 루트노드는 현재 red인데, RB tree의 규칙에 의해 루트노드는 항상 black이어야 하므로, black으로 바꿔준다.
		
<40삽입>
	 1. x = (x->key > v) ? x->l : x->r;  x의 key값(15)이 v(40)보다 작으므로, x에 x의 오른쪽 자식노드를 저장한다. 즉, 오른쪽으로 이동, 30이 40보다 작으니 오른쪽으로 이동, 
	 2. 52가 40보다 크므로 왼쪽으로 이동, 즉 x에 x의 왼쪽 자식노드를 저장
	 3.  x = new Node(red, v, index, z, z);  삽입된 숫자로 새 노드를 만든다.
	 4. if (p->key > v) p->l = x; 부모노드의 key값은 52이므로, 52의 값이 40보다 더 크다. 따라서 40 노드를 52노드의 왼쪽자식으로 삽입한다.
	 5. this->split(v,index); spilt 함수로 들어간다.
	 6. if (p->b) 40의 부모노드(52)가 red이므로 red인 노드가 연속하여 RB tree의 규칙에 어긋난다 *Case 3인경우(교재에서는 Case 2-1)
	 7. 두노드의 상위노드인 30노드의 색을 red로 바꾼다.
	 8. Case3이므로, 52를 중심으로 오른쪽으로 회전한다.
	 9. Case3(교재 Case2-1)은 회전하고 다시 Case4(교재 Case2-2)를 수행하므로,
		이번에는 40을 중심으로 왼쪽으로 회전한다.
	 10. head->r->b = black; 루트노드는 현재 red인데, RB tree의 규칙에 의해 루트노드는 항상 black이어야 하므로, black으로 바꿔준다.


<35삽입>
	 1.  x = (x->key > v) ? x->l : x->r;   15, 40이 35보다 작으므로, 오른쪽으로 이동, 
	 2. 52가 35보다 크므로 왼쪽으로 이동, 즉 x에 x의 왼쪽자식노드를 저장(30으로 감)-> 30보다 35가 더 크므로 오른쪽으로 이동
	 3. x = new Node(red, v, index, z, z);  삽입된 숫자로 새 노드를 만든다.
	 4. if (p->key > v) p->l = x; 부모노드의 key값은 30이므로, 35의 값이 30보다 더 크다. 따라서 35 노드를 30노드의 오른쪽자식으로 삽입한다.

<38삽입>
	 1.  x = (x->key > v) ? x->l : x->r;  15가 35보다 작으므로 오른쪽으로 이동. 40이 38보다 크므로 왼쪽으로 이동, 30, 35가 38보다 작으므로, 오른쪽으로 이동
	 2. x = new Node(red, v, index, z, z);  삽입된 숫자로 새 노드를 만든다.
	 3. if (p->key > v) p->l = x; 부모노드의 key값은 35이므로, 38의 값이 35보다 더 크다. 따라서 38 노드를 35노드의 오른쪽자식으로 삽입한다.
	 4. this->split(v,index); spilt 함수로 들어간다.
	 5. if (p->b) 38의 부모노드(35)가 red이므로 red인 노드가 연속하여 RB tree의 규칙에 어긋난다 *Case 4인경우(교재에서는 Case 2-2)
	 6. 두노드의 상위노드인 30노드의 색을 red로 바꾼다.
	 7. Case4이므로, 35를 중심으로 왼쪽으로 회전한다.
	 8.  35의 색을 black으로 바꿔준다.

<39삽입>
	 1. x = (x->key > v) ? x->l : x->r;  15가 39보다 작으므로 오른쪽으로 이동. 40이 39보다 크므로 왼쪽으로 이동, 35, 30이 39보다 작으므로, 오른쪽으로 이동
	 2.  if (x->l->b && x->r->b) 이므로, 즉, 삽입하려는 노드의 부모와 부모의 형제가 red인 경우로, Case 2에 해당(교재에서는 Case1)
	 3. this->split(v, index); spilt 함수로 들어간다.
	 4.  (x->b == black) 35노드의 색이 black이므로, 
		x->b = red; x->l->b = black; x->r->b = black;  수행. 35노드를 red로 바꾸고, 왼쪽과 오른쪽 자식노드의 색을 black으로 바꾼다.  
	 5.  if (p->b) 35의 부모노드(40)가  red이므로 red인 노드가 연속하여 RB tree의 규칙에 어긋난다 *Case 3인경우(교재에서는 Case 2-1)
	 6. 두노드의 상위노드인 15노드의 색을 red로 바꾼다.
	 7. Case3이므로, 40를 중심으로 오른쪽으로 회전한다.
	   이 때 이진트리의 특성(부모보다 작은 수는 왼쪽 자식, 큰 수는 오른쪽 자식)을 만족시키기 위해
	   회전된 52의 자식인 38이 회전 후 40의 왼쪽 자식이 된다.
	 9. Case3(교재 Case2-1)은 회전하고 다시 Case4(교재 Case2-2)를 수행하므로,
		이번에는 35을 중심으로 왼쪽으로 회전한다.
		이 때 이진트리의 특성(부모보다 작은 수는 왼쪽 자식, 큰 수는 오른쪽 자식)을 만족시키기 위해
	   회전된 35의 자식인 30과 회전된 10이 회전 후 15의 자식이 된다.
	10. 35의 색을 black으로 바꿔준다.
	 11. x = new Node(red, v, index, z, z);  삽입된 숫자로 새 노드를 만든다.
	 12. if (p->key > v) p->l = x; 부모노드의 key값은 38이므로, 39의 값이 더 크다. 따라서 39 노드를 38노드의 오른쪽자식으로 삽입한다.

<7삽입>
	 1. x = (x->key > v) ? x->l : x->r;  35가 7보다 크므로 왼쪽으로 이동. 15, 10이 7보다 크므로 왼쪽으로 이동
	 2.  if (x->l->b && x->r->b) 이므로, 즉, 삽입하려는 노드의 부모와 부모의 형제가 red인 경우로, Case 2에 해당(교재에서는 Case1)
	 3. this->split(v, index); spilt 함수로 들어간다.
	 4.  (x->b == black) 35노드의 색이 black이므로, 
		x->b = red; x->l->b = black; x->r->b = black;  수행. 35노드를 red로 바꾸고, 왼쪽과 오른쪽 자식노드의 색을 black으로 바꾼다.  
	 5.  x = new Node(red, v, index, z, z);  삽입된 숫자로 새 노드를 만든다.
	 6. if (p->key > v) p->l = x; 부모노드의 key값은 10이므로, 7의 값이 더 작다. 따라서 7 노드를 10노드의 왼쪽자식으로 삽입한다.
	 7. head->r->b = black; 루트노드는 현재 red인데, RB tree의 규칙에 의해 루트노드는 항상 black이어야 하므로, black으로 바꿔준다.

<9삽입>
	 1.  x = (x->key > v) ? x->l : x->r;  35, 15, 10이 7보다 크므로 왼쪽으로 이동. 7이 9보다 작으므로 오른쪽으로 이동
	 2. x = new Node(red, v, index, z, z);  삽입된 숫자로 새 노드를 만든다.
	 3. if (p->key > v) p->l = x; 부모노드의 key값은 7이므로, 9의 값이 더 크다. 따라서 9 노드를 7노드의 오른쪽자식으로 삽입한다.
	 4. if (p->b) 9의 부모노드(7)가  red이므로 red인 노드가 연속하여 RB tree의 규칙에 어긋난다 *Case 3인경우(교재에서는 Case 2-1)
	 5. 두노드의 상위노드인 10노드의 색을 red로 바꾼다.
	 6. Case3이므로, 7을 중심으로 왼쪽으로 회전한다.
	 7. Case3(교재 Case2-1)은 회전하고 다시 Case4(교재 Case2-2)를 수행하므로,
		이번에는 9을 중심으로 오른쪽으로 회전한다.
	 8. 9노드의 색을 black으로 바꿔준다.

<6삽입>
	 1. x = (x->key > v) ? x->l : x->r;  35, 15, 9,7이 6보다 크므로 왼쪽으로 이동.
	 2. x = new Node(red, v, index, z, z);  삽입된 숫자로 새 노드를 만든다.
	 3. if (p->key > v) p->l = x; 부모노드의 key값은 7이므로, 6의 값이 더 작다. 따라서 6 노드를 7노드의 왼쪽자식으로 삽입한다.
*/

	
}

//트리를 초기화하는 함수
IntRBTree::IntRBTree() {
	z = new Node(black, 0, 0, 0, 0); //key 값과 index값이 0이고, 자식노드가 없는 블랙노드를 생성한다.->z노드는 leaf 노드가 된다.
	z->l = z; z->r = z; //새로 만든 노드 z는, 왼쪽과 오른쪽 자식노드가 없고, 자신에 연결되어 있다.
	head = new Node(black, 0, 0, 0, z); //root노드인 head노드를 생성한다.  head노드는, key값과 index값이 0이고, 오른쪽 자식노드를 갖는 블랙노드이다.
}

//RB 트리 탐색하는 함수
Node *IntRBTree::search(int search_key)
{
	Node *x = head->r; //x노드는 루트의 오른쪽 자식노드부터 시작
	while (x != z) { //말단노드까지 탐색을 반복
		if (x->key == search_key) return x; //찾고자하는 값이 x노드의 key값이면 x노드를 return
		x = (x->key > search_key) ? x->l : x->r;
		//x노드(탐색노드)의 key값이 찾고자하는 값보다 크면 찾고자하는 값이 x노드의 왼쪽에 있는 것이므로, 왼쪽 자식 노드를 탐색 즉, x=x의 왼쪽 자식노드로 바꿔 다시 탐색 수행
		//x노드(탐색노드)의 key값이 찾고자하는 값보다 작으면 찾고자하는 값이 x노드의 오른쪽에 있는 것이므로,  오른쪽 자식 노드를 탐색 즉, x=x의 오른쪽 자식노드로 바꿔 다시 탐색 수행
	}
	return NULL; //말단 노드까지 탐색을 끝내면 NULL을 return
}

void IntRBTree::insert(int v, int index)
{
	/*레드블랙트리에서의 삽입의 경우의 수는 4가지

	1. 삽입된 노드(x)의 부모노드(p)의 색이 블랙인 경우-> 문제 없음

	2. 삽입된 노드의 부모노드(p)의 색이 레드이고, 부모노드의 형제노드(s)가 레드일 경우
	   -> 부모노드(p)와 그 형제노드(s)의 색을 black으로 바꿈. 부모노드의 부모노드(g)가  루트면, g의 색상을 black으로 바꿈. 만약 g의 색상이 레드이면, recursion으로 같은 과정 반복

	3. 삽입된 노드의 부모노드(p)의 색이 레드이고, 부모노드의 형제노드(s)가 블랙,
	   *3-1) 삽입된 노드가 부모노드(p)의 오른쪽 자식이고, 삽입된 노드의 부모노드가 g(부모노드의 부모노드)의 왼쪽 자식일때 : 부모노드(p)를 중심으로 왼쪽으로 회전->4번으로 넘어감
	   *3-2) 삽입된 노드가 부모노드(p)의 왼쪽 자식이고, 삽입된 노드의 부모노드가 g(부모노드의 부모노드)의 오른쪽 자식일때 : 부모노드(p)를 중심으로 오른쪽으로 회전->4번으로 넘어감   (3-1)과 대칭인 경우

	  4. 삽입된 노드의 부모노드의 색이 레드이고, 부모노드의 형제노드(s)가 블랙,
		*4-1) 삽입된 노드가 부모노드(p)의 왼쪽 자식이고, 삽입된 노드의 부모노드가 g(부모노드의 부모노드)의 왼쪽 자식일때 : g를 중심으로 오른쪽 회전, p와 g의 색상을 맞바꿈
		*4-2) 삽입된 노드가 부모노드의 오른쪽 자식이고,  삽입된 노드의 부모노드가 g(부모노드의 부모노드)의 오른쪽 자식일 때 : g를 중심으로 왼쪽 회전, p와 g의 색상을 맞바꿈  (4-1)과 대칭인 경우
	*/

	//삽입 전 트리 출력
	printf("\n삽입 전 트리 출력\n");
	print_tree(head->r);

	x = head; p = head; g = head; //x: head, p: 삽입된 노드의 parent노드, g: 삽입된 노드의 parent의 parent노드
	while (x != z) { //x가 z(leaf노드)이 될 때까지 while문 수행
		gg = g; g = p; p = x; //gg(g의 parent)에 g를 저장 즉 각각의 g, p, x의 부모노드를 gg, g, p로 정하고, 연결시킨다.
		//즉, x의 부모는 p가 되고, p의 부모는 g가, g의 부모는 gg가 된다. gg는 g를 가리키고, g는 p를, p는 g를 가리킴


		//v가 들어갈 곳 찾기
		if (x->key == v)
		{
			printf("(x->key == v\n");
			return;
		}// x가 key값이 v이면, 즉 삽입된 숫자와 같으면, x를 리턴한다. 

		//삽입하는 값(v)이 들어갈 위치 찾기
		x = (x->key > v) ? x->l : x->r;
		//x의 key값(현재값)이 v(삽입하려는 값)보다 크면, x에 x의 왼쪽 자식노드를 저장한다. 즉, 왼쪽으로 이동. 이 때, x가 자신의 자식노드를 가리키므로 p,g, gg도 그 자식노드를 가리키게 됨
		//x의 key값(현재값)이 v(삽입하려는 값)보다 작으면, x에 x의 오른쪽 자식노드를 저장한다. 즉, 오른쪽으로 이동. 

		if (x->l->b && x->r->b)  //x가 가리키고 있는 자식들의 색이 모두 red인 경우, 수선한다.
			//b는 노드 색깔 black은 0, red=1
		{
			index++;
			printf("%d) 삽입하려는 노드의 부모와 부모의 형제가 red인 경우 Case 2에 해당하므로 두 노드의 상위노드인\n", index);
			this->split(v, index); //split는 트리를 RB트리의 특성에 맞게 수선하는 함수.
			
		}
			
	}
	//x가 z(leaf노드)가 되면 새 노드를 삽입(노드 삽입은 항상 말단 노드에서 시작하므로)
	x = new Node(red, v, index, z, z); //삽입된 숫자로 새 노드를 만든다.  새 노드의 색은 항상 red 여야한다. (RB Tree 성질)
	
	if (p->key > v)
	{
		p->l = x; //부모노드의 key 값이 삽입된 숫자 v 보다 크면, 이진트리의 특성에 따라 v 값을 가리키고 있는 x노드를 p의 왼쪽 자식으로 삽입한다.
		index++;
		printf("\n %d) 새 노드를 만들어 삽입한다. 이진 트리의 성질에 따라, %d가 부모노드(%d)보다 값이 작으므로 왼쪽에 삽입\n", index, v, p->key);
	}
		
	else
	{
		p->r = x; // 부모노드의 key 값이 삽입된 숫자 v 보다 작으면, 이진트리의 특성에 따라 v 값을 가리키고 있는 x노드를 p의 오른쪽 자식으로 삽입한다.
		index++;
		printf("\n %d) 새 노드를 만들어 삽입한다. 이진 트리의 성질에 따라, %d가 부모노드(%d)보다 값이 크므로 오른쪽에 삽입\n" ,index, v, p->key);
	}
	
	//삽입된 결과를 나타내는 트리 출력
	print_tree(head->r);

	this->split(v,index);
	if (head->r->b != black)//루트노드의 색은 black이어야한다. 만약 루트노드의 색이 black이 아니면,
	{
		index++;
		printf("%d) 루트노드의 색을 black으로 바꿔준다.  \n", index);
		head->r->b = black; //head(루트노드)의 색을 black으로 바꾼다.
		print_tree(head->r);
	}

	//트리를 화면에 출력
	printf("\n최종 결과트리\n");
	printf("*****************************************************************************\n\n");
	print_tree(head->r);
	printf("\n________________________________________________________________________\n\n\n\n\n");
	
}

void IntRBTree::split(int v, int index)
{
	if (x->b == black)//case2(교재에서는 Case1)의 경우
	{
		x->b = red; x->l->b = black; x->r->b = black; //x의 노드를 red로 바꾸고, 왼쪽과 오른쪽 자식노드의 색을 black으로 바꾼다.  
		printf("%d의 노드를 red로 바꾸고, 왼쪽과 오른쪽 자식노드의 색을 black으로 바꾼다.\n ",  x->key);
		print_tree(head->r);
		
	}
	
	//Case3 or Case4(교재에서는 Case2-1, Case2-2인 경우)
	if (p->b) { //만약 x의 부모노드가 red인 경우
		{
			g->b = red; //x의 부모노드의 부모노드의 색을 red로 바꾼다. 
			index++;
			printf("%d) %d 와 부모노드인 %d의 노드의 색이 둘 다 red이므로, RB tree의 규칙에 어긋난다. ->두노드의 상위노드인(g노드) %d의 색을 red로 바꾼다.", index,x->key, p->key,g->key);
			print_tree(head->r);
		}
		
		//Case 3(교재에서는 Case2-1)인 경우
		if (g->key > v != p->key > v)
		{
			index++;
			printf("%d) Case3 %d를 중심으로",index, p->key);
			p = this->rotate(v, g, index);
		}//g의 key값이 삽입되는 값보다 크고, p의 key값이 삽입되는 값 v 보다 작은 경우 혹은 g의 key값이 삽입되는 값보다 작고p의 key값이 삽입되는 값 v보다 큰 경우 rotate(v, g); 실행 회전시키기.


		//Case 4(교재에서는 Case2-2)인 경우
		index++;
		printf("%d) Case4 %d를 중심으로 ", index, p->key);
		x = this->rotate(v, gg, index); 
		//위의 경우가 아닌 경우, 즉  g의 key값이 삽입되는 값보다 크고, p의 key값이 삽입되는 값 v 보다 큰 경우 혹은 g의 key값이 삽입되는 값보다 작고 p의 key값이 삽입되는 값 v보다 작은 경우 rotate(v, gg) 실행
		//Case4이므로, 회전 후 Case 4(교재에서는 Case2-2) 수행

		//교재 설명에서는 p와 g의 색상을 바꾸는 작업 (Case4 수행 후 자식노드들은 red이므로)
		index++;
		printf("%d) %d의 색을 black으로 바꿔준다.(자식노드들이 red이고, black노드 개수를 맞춰주기 위해)  \n",index, x->key);
		x->b = black; //x가 가리키는 노드의 색을 black으로 바꾼다. 
		print_tree(head->r);
	}
}

Node *IntRBTree::rotate(int v, Node *y,int index)
{
	
	Node *gc, *c; //노드를 가리키는 포인터
	c = (y->key > v) ? y->l : y->r;
	//노드 y의 key값이 삽입되는 값 v보다 크면, y의 왼쪽자식을 c가 가리킨다. 
	//노드 y의 key값이 삽입되는 값 v보다 작으면, y의 오른쪽자식을 c가 가리킨다.

	if (c->key > v) { //c가 가리키는 값 즉, y의 자식의 key값이 삽입하는 값 v보다 크면
		
		printf("오른쪽으로 회전한다.\n");
		gc = c->l; c->l = gc->r; gc->r = c; //gc는 c의 왼쪽 자식을 가리키고, c의 왼쪽자식은 gc의 오른쪽 자식을(즉 c의 왼쪽자식의 오른쪽 자식), gc의 오른쪽 자식(즉, c의 왼쪽자식의 오른쪽 자식의 오른쪽 자식)은 c를 가리킨다. 
	
		//즉, 오른쪽으로 회전
	}

	else {//c가 가리키는 값 즉, y의 자식의 key값이 삽입하는 값 v보다 작으면
		index++;
		printf("왼쪽으로 회전한다.\n");
		gc = c->r; c->r = gc->l; gc->l = c; //gc는 c의 오른쪽 자식을 가리키고, c의 오른쪽 값은 gc의 왼쪽 자식을 가리키고, gc의 왼쪽 자식은 c를 가리킨다. 
		
		//즉, 왼쪽으로 회전
	}
	if (y->key > v) y->l = gc; //y의 key값이 삽입되는 값 v 보다 크면, y의 왼쪽자식은 gc를 가리킨다. -> 회전후에 노드들이 들어갈 자리를 결정(y와 연결)
	else y->r = gc; //y의 key값이 삽입되는 값 v 보다 작으면, y의 오른쪽자식이 gc를 가리킨다.  -> 회전후에 노드들이 들어갈 자리를 결정(y와 연결)
	print_tree(head->r);
	return gc; //gc를 return
}


//RB tree를 출력하는 함수
void IntRBTree::print_tree_fun(Node *root, int space, int flag)
{
	//flag :0 == root node일때, flag : 1 ==right node일때  flag :2 == left node일때를 나타낸다.
	char color; //노드의 색을 나타내기 위해 color 변수 생성
	if (root->b == black)
		color = 'B'; //black =0
	if (root->b == red)
		color = 'R'; //red =1


	
	if (root==z)
	{
		printf("0"); //루트노드가 말단노드이면, 즉 트리가 초기화된 상태이면 0출력

	}

	
	space += BLANK;  // BLANK는 간격을 조정하는 숫자. 14부터 시작. 트리에서 한 줄씩 내려갈때마다(일반적인 트리의 모양에서. 이 프로그램에서 트리는 옆으로 출력되므로 한 칸씩 옆으로 가는 것이 됨)누적으로 증가

	//오른쪽 자식노드 부터 출력
	if (root->r != z) //오른쪽 자식노드가 존재하면
	{
		print_tree_fun(root->r, space,1); //노드를 출력. 이 때 오른쪽 자식노드이므로, flag는 1로 바꿔준다. 재귀함수를 이용해 말단까지 출력을 반복하도록 한다

	}

	// BLANK  공백 출력
	printf("\n");
	for (int i = BLANK; i < space; i++) //누적된 수만큼 공백을 출력한다. 아랫줄로 갈 수록 간격이 좁아진다.
		printf(" ");

	if (flag == 0)
		printf("*"); //루트노드일 경우 시작이므로, *표시를 해준다.
	else if (flag == 2)
		printf("L....."); // flag가 2인 경우 즉 left노드인 경우에는 L.....를 출력하는데, 이는 트리의 모양을 알기 쉽게 표현하기 위한 장치
	else if (flag == 1)
		printf("T````"); // flag가 1인 경우 즉 right노드인 경우에는 T````를 출력하는데, 이는 트리의 모양을 알기 쉽게 표현하기 위한 장치

	
	printf("%d [%c]", root->key, color); //노드에 저장된 값과 노드 색을 출력

	if (root->l != z || root->r != z) //말단 노드가 아니라면
	{
		if (flag == 0)
		{
			printf("-----"); //루트노드와 자식노드 사이는 간격이 제일 넓으므로, 조정하기 위해 더 긴 막대를 사용한다.
		}
		printf("--"); //트리의 모양을 알기 쉽게 표현하기 위한 장치. 다음 노드와의 연결을 더 보기 편하게 나타냄
	}

	if (root->l != z)//왼쪽 자식노드가 존재하면
	{
		print_tree_fun(root->l, space,2); //노드를 출력. 이 때 왼쪽 자식노드이므로, flag는 2로 바꿔준다. 재귀함수를 이용해 말단까지 출력을 반복하도록 한다.
	}

	}

//트리 출력할 때 기본적인 것들을 설정하는 함수로, space, flag를 초기화시키고, 출력된 트리들 간의 구분을 해주는 함수
	void  IntRBTree::print_tree(Node *root)
	{
		//space와 flag를 0으로 초기화 
		print_tree_fun(root, 0,0);
		printf("\n_  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  ");
		printf("\n\n\n");
		
	}
	//end












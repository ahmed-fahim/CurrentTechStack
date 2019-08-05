#include <iostream>
#include <malloc.h>
#include <sstream>
#include <cstdio>
using namespace std;
#define pii pair<int, int>
#define mp make_pair

template <typename t1> int partition(t1 *arr, int left, int right, t1 pivot) {
	cout << left << " " << right << " then -> ";
	while (left <= right) {
		while (arr[left] < pivot) {
			left++;
		}
		while (arr[right] > pivot) {
			right--;
		}
		if (left <= right) {
			t1 var = arr[left];
			arr[left] = arr[right];
			arr[right] = var;
			left++;
			right--;
		}
	}
	cout << left << " " << right << endl;
	return left;
}
template <typename t1> void sort(t1 *arr, int left, int right) {
	if (left >= right)return;
	t1 pivot = arr[(left + right) / 2];
	int index = partition(arr, left, right, pivot);
	sort(arr, left, index - 1);
	sort(arr, index, right);
}
template <typename t1> void sort(t1 *arr, t1 *arrEnd) {
	int size = (arrEnd - arr);
	int left = 0, right = size - 1;
	sort(arr, left, right);

}
#define infinity 2147483647
template <typename t1> struct node {
	t1 value;
	node<t1> *next, *prev;
	node() {
		value = 0;
		next = prev = NULL;
	}
	node(t1 v) {
		value = v;
		next = prev = NULL;
	}
};
template <typename t1> struct list {
	node<t1> *head, *tail;
	int sz;
	list() {
		head = new node<t1>; tail = new node<t1>;
		head->next = tail; tail->prev = head;
	}
	list(t1 v) {
		head = new node<t1>; tail = new node<t1>;
		node<t1>* newNode = new node<t1>;
		newNode->value = v;
		head->next = newNode; newNode->next = tail;
		tail->prev = newNode; newNode->prev = head;
	}
	inline void copyList(const list<t1> *copied){
        copied->head->next=this->head->next;
        this->head->next->prev = copied->head;
        copied->tail->prev=this->tail->prev;
        this->tail->prev->next=copied->tail;
        return;
	}
	inline void addWith(const list<t1> *leftPart){
        ///add = leftPart(from head to strictly previous of tail)
        ///     + thisList(except head,tail) + leftPart(only tail)
        node<t1> *leftPartLeft, *leftPartRight;
        leftPartLeft=leftPart->tail->prev;
        leftPartRight=leftPart->tail;
        node <t1> *afterHead=this->head->next;
        node <t1> *beforeTail=this->tail->prev;
        leftPartLeft->next=afterHead; afterHead->prev=leftPartLeft;
        beforeTail->next=leftPartRight; leftPartRight->prev=beforeTail;
	}
	inline void push_back(t1 v)
	{
		node<t1>* newNode = new node<t1>;
		newNode->value = v;
		node<t1>* prevTail = tail->prev;
		prevTail->next = newNode; newNode->next = tail;
		tail->prev = newNode; newNode->prev = prevTail;
	}
	inline void push_front(t1 v) {
		node<t1> *newNode = new node<t1>(v);
		node<t1> *leftMost = head, *rightMost = head->next;
		leftMost->next = newNode; newNode->next = rightMost;
		rightMost->prev = newNode; newNode->prev = leftMost;
	}
	inline void pop_front() {
		if (this->empty())return;
		node<t1>* middleNode = head->next;
		node<t1>* rightNode = middleNode->next;
		head->next = rightNode;
		rightNode->prev = head;
		delete(middleNode);
	}
	inline void pop_back() {
		if (this->empty())return;
		node<t1>* middleNode = tail->prev;
		node<t1>* leftNode = middleNode->prev;
		tail->prev = leftNode;
		leftNode->next = tail;
		delete(middleNode);
	}
	inline bool empty() {
		return (this->head->next == this->tail) ? true : false;
	}
	inline void print() {
		if (this->empty())return;
		node<t1>* carrier;
		carrier = head->next;
		while (carrier != tail) {
			cout << carrier->value << " ";
			carrier = carrier->next;
		}
		cout << endl;
	}
	inline void clear(){
        head->next = tail; tail->prev = head;
	}
	inline t1 front() {
		if (this->empty())return infinity;
		return head->next->value;
	}
	inline t1 back() {
		if (this->empty())return infinity;
		return tail->prev->value;
	}
	template <typename type2> friend void merge(list<type2> *keeper, list<type2>* fhalf, list<type2>* shalf);
	template <typename type2> friend void mergeSort(list<type2> *finalRes,list<type2>* x);
	template <typename type2> friend node<type2>* getMiddlePointer(list<type2>* ptr);

};
template <typename t1> void merge(list<t1> *keeper,list<t1>* fhalf, list<t1>* shalf) {
	while (fhalf->empty()==false or shalf->empty()==false) {
		if (!fhalf->empty() and !shalf->empty()) {
			if (fhalf->front() < shalf->front()) {
				keeper->push_back(fhalf->front());
				fhalf->pop_front();
			}
			else {
				keeper->push_back(shalf->front());
				shalf->pop_front();
			}
		}
		else if (fhalf->empty()) {
            shalf->addWith(keeper);
            shalf->clear();
		}
		else if (shalf->empty()) {
            fhalf->addWith(keeper);
            fhalf->clear();
		}
	}
	return;
}
template <typename t1> node<t1>* getMiddlePointer(list<t1>* ptr) {
	node<t1> *leader, *follower;
	follower = leader = ptr->head;

	while (leader->next != ptr->tail) {
		leader = leader->next;
		if (leader->next != ptr->tail) {
			follower = follower->next;
			leader = leader->next;
		}
	}
	return follower;
}
template <typename t1> void mergeSort(list<t1> *finalRes, list<t1>* x){
	if (x->empty() == true){
        return;
	}

	///if it has only one element, return it
	if (x->head->next->next == x->tail) {
		finalRes->push_back(x->head->next->value);
		return;
	}
	node<t1>* midPointer = getMiddlePointer(x);

	//connecting the second half of the list x to a new list y
	list<t1> y;
	y.head->next = midPointer->next;
	midPointer->prev = y.head;
		//Also connecting the second half of list x with the new list y
	node<t1>* last_before_tail = x->tail->prev;
	last_before_tail->next = y.tail;
	y.tail->prev = last_before_tail;


	//truncating x to first half
	x->tail->prev = midPointer;
	midPointer->next = x->tail;

	list<t1> sortedList;
	list<t1> sortedFirst, sortedSecond;
	mergeSort(&sortedFirst, x);
	mergeSort(&sortedSecond, &y);
	merge(&sortedList, &sortedFirst, &sortedSecond);
    sortedList.copyList(finalRes);
	return;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); cerr.tie(0);
	list<int> a;
	int arr[] = { 1,3,5,2,4,6,99,-1,-45,-21 };
	for (int i = 0; i <= 9; i++) {
		a.push_back(arr[i]);
	}
	list<int> p;
	mergeSort(&p,&a);
	p.print();
	system("pause");
	return 0;
}

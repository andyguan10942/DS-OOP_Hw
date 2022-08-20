//TODO
#include<iostream>
using namespace std;

template<class T> //�ŧi myList
class myList;

//ListNode 
template <class T>
class ListNode{
	private:
		T val;
		ListNode<T> *next;
	public:
		ListNode(T x):val(x),next(0){} //constructor
		friend class myList<T>;//�Nclass myList�ŧi��friend�A��myList�i�H�s��ListNode��private����
};

//myList
template <class T>
class myList{
	private:
		ListNode<T> *head;
	public:
		myList(); //Constructor
		~myList(); //Destructor 
		void push_back(T val);
		void push_front(T val);
		void insert(int index,T val);
		void pop_back();
		void pop_front();
		void pop_index(int index);
		void print();
};

//mylist define
template<class T>
myList<T>::myList():head(0){}

template<class T>
myList<T>::~myList(){
	ListNode<T> *ptr=head;
	ListNode<T> *tmp;
	while (ptr!=NULL){
		tmp=ptr->next;
		delete ptr;
		ptr=tmp;
	}
	head=NULL;
}

template<class T>
void myList<T>::push_back(T val){
	ListNode<T> *NewNode=new ListNode<T>(val);
	if (head==NULL){//�쥻�S��node
		head=NewNode;
	}else{
		ListNode<T> *cur;
		cur=head;
		while (cur->next!=NULL){
			cur=cur->next;
		}
		cur->next=NewNode;
	}
}

template<class T>
void myList<T>::push_front(T val){
	ListNode<T> *NewNode=new ListNode<T>(val);
	if (head==NULL){//�쥻�S��node
		head=NewNode;
	}else{
		NewNode->next=head;
		head=NewNode;
	}
}

template<class T>
void myList<T>::insert(int index,T val){
	if (index<0){//index����p��0 
		cout<<"index ��J���~"<<endl;
		return;
	}
	 
	ListNode<T> *NewNode=new ListNode<T>(val);
	
	if (index==0){
		NewNode->next=head;
		head=NewNode;
	}else{ // index>=1
		ListNode<T> *ptr=head;
		for (int i=1;i<=index-1 && ptr->next!=NULL;i++){
			ptr=ptr->next;
		}
		
		if (ptr->next==NULL){//ptr->next==NULL �S��kinsert index��J���~ 
			delete NewNode;
			cout<<"index ��J���~"<<endl;
			return;
		}
		
		NewNode->next=ptr->next;
		ptr->next=NewNode;
	}
}

template<class T>
void myList<T>::pop_back(){
	if (head==NULL)return;//�S��node
	
	ListNode<T> *cur=head;
	ListNode<T> *pre=NULL;
	while (cur->next!=NULL){
		pre=cur;
		cur=cur->next;
	}
	
	
	if (pre==NULL){//�u���@�� node
		head=NULL;
	}else{//��ӥH�Wnode
		pre->next=NULL;
	}
	delete cur;//�R���̫�@��node
}

template<class T>
void myList<T>::pop_front(){
	if (head==NULL)return;//�S��node
	
	ListNode<T> *ptr=head;
	head=head->next;
	delete ptr;
}

template<class T>
void myList<T>::pop_index(int index){
	if (index<0){//index����p�� 0 
		cout<<"index ��J���~"<<endl; 		
		return;
	}
	
	if (head==NULL)return;//�S��node
	
	ListNode<T> *cur=head;
	ListNode<T> *pre=NULL;
	
	for (int i=1;i<=index && cur!=NULL;i++){
		pre=cur;
		cur=cur->next;
	}
	
	if (cur==NULL){//cur==NULL �S��k�R�� index��J���~
		cout<<"index ��J���~"<<endl; 
		return;
	}
	
	if (index==0){//�R����0��node
		head=head->next;
	}else{
		pre->next=cur->next;
	}	
	delete cur;//�R����index��node
}

template <class T>
void myList<T>::print(){
	ListNode<T> *ptr=head;
	while (ptr){
		cout<<ptr->val<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}


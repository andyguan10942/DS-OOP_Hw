//TODO
#include<iostream>
using namespace std;

template<class T> //宣告 myList
class myList;

//ListNode 
template <class T>
class ListNode{
	private:
		T val;
		ListNode<T> *next;
	public:
		ListNode(T x):val(x),next(0){} //constructor
		friend class myList<T>;//將class myList宣告為friend，讓myList可以存取ListNode的private成員
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
	if (head==NULL){//原本沒有node
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
	if (head==NULL){//原本沒有node
		head=NewNode;
	}else{
		NewNode->next=head;
		head=NewNode;
	}
}

template<class T>
void myList<T>::insert(int index,T val){
	if (index<0){//index不能小於0 
		cout<<"index 輸入錯誤"<<endl;
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
		
		if (ptr->next==NULL){//ptr->next==NULL 沒辦法insert index輸入錯誤 
			delete NewNode;
			cout<<"index 輸入錯誤"<<endl;
			return;
		}
		
		NewNode->next=ptr->next;
		ptr->next=NewNode;
	}
}

template<class T>
void myList<T>::pop_back(){
	if (head==NULL)return;//沒有node
	
	ListNode<T> *cur=head;
	ListNode<T> *pre=NULL;
	while (cur->next!=NULL){
		pre=cur;
		cur=cur->next;
	}
	
	
	if (pre==NULL){//只有一個 node
		head=NULL;
	}else{//兩個以上node
		pre->next=NULL;
	}
	delete cur;//刪除最後一個node
}

template<class T>
void myList<T>::pop_front(){
	if (head==NULL)return;//沒有node
	
	ListNode<T> *ptr=head;
	head=head->next;
	delete ptr;
}

template<class T>
void myList<T>::pop_index(int index){
	if (index<0){//index不能小於 0 
		cout<<"index 輸入錯誤"<<endl; 		
		return;
	}
	
	if (head==NULL)return;//沒有node
	
	ListNode<T> *cur=head;
	ListNode<T> *pre=NULL;
	
	for (int i=1;i<=index && cur!=NULL;i++){
		pre=cur;
		cur=cur->next;
	}
	
	if (cur==NULL){//cur==NULL 沒辦法刪除 index輸入錯誤
		cout<<"index 輸入錯誤"<<endl; 
		return;
	}
	
	if (index==0){//刪除第0個node
		head=head->next;
	}else{
		pre->next=cur->next;
	}	
	delete cur;//刪除第index個node
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


#include <iostream>

using namespace std;
template <class T>

class Node{
	public:
	T * next;
	T * first;
	T * last;
	
	Init(){
		next = NULL;
		first = NULL;
		last = NULL;
	}
	
	static T * CreateNode(){
		T * newNode = new T();
		newNode -> Init();
		return newNode;
	}
	
	bool isExist(string header){
		T * temp = this -> first;
		
		while(temp != NULL){
			if(temp -> Getheader() == header){
				delete temp;
				return true;
			}
			temp = temp -> next;
		}
		return false;
	}
	
	virtual void Delete(string header) = 0;
	virtual void Print() = 0;
};

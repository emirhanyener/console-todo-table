#include <iostream>
#include <fstream>
#include "todo.cpp"

using namespace std;

class FileSystem{
	public:
	Todo * todoList;
	Todo * tempt;
	
	FileSystem(){
		tempt = Todo::CreateNode();
		todoList = Todo::CreateNode();
		string text;
		string temp;
		ifstream file("db.dat");
		while(getline(file, text)){
			Todo * node = Todo::CreateNode();
			
			int column = 0;
			for(int i = 0; text[i] != '\0'; i++){
				if(text[i] != ',' && text[i+1] != '\0'){
					temp += text[i];
					continue;
				}
				if(column == 1){
					node -> Setdescription(temp);
				}
				if(column == 0){
					node -> Setheader(temp);
				}
				
				column++;
				temp = "";
			}
			if(todoList -> last == NULL){
				todoList -> first = node;
				todoList -> last = node;
			}
			else{
				todoList -> last -> next = node;
				todoList -> last = node;
			}
		}
		file.close();
	}
	
	void ReadTodoList(){
		tempt = todoList -> first;
		while(tempt != NULL){
			cout << tempt -> Getheader() << ", " << tempt -> Getdescription() << endl;
			tempt = tempt -> next;
		}
	}
	
	void AddTodo(string header, string description){
		bool control = true;
		tempt = todoList -> first;
		while(tempt != NULL){
			if(tempt -> Getheader() == header)
				control = false;
			tempt = tempt -> next;
		}
		
		if(control){
			Todo * newNode = Todo::CreateNode(header, description);
			todoList -> last -> next = newNode;
			todoList -> last = newNode;
		}
		else{
			cout << "this header exists" << endl;
		}
		
	}
	
	void WriteTodoList(){
		ofstream file("db.dat");
		tempt = todoList -> first;
		while(tempt != NULL){
			file << tempt -> Getheader() << ", " << tempt -> Getdescription() << endl;
			tempt = tempt -> next;
		}
		file.close();
	}
	
	void DeleteTodo(string header){
		tempt = todoList -> first;
		
		while(tempt != NULL){
			if(todoList -> first -> Getheader() == header){
				todoList -> first = todoList -> first -> next;
				break;
			}
			if(tempt -> next -> Getheader() == header){
				if(tempt -> next == todoList -> last)
					todoList -> last = tempt;
				tempt -> next = tempt -> next -> next;
				cout << "deleted" << endl;
				break;
			}
			tempt = tempt -> next;
		}
	}
};

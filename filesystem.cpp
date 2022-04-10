#include <iostream>
#include <fstream>
#include "todo.cpp"

using namespace std;

class FileSystem{
	public:
	Todo * todoList;
	
	FileSystem(){
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
	}
	
	void WriteTodoList(){
		Todo * temp = Todo::CreateNode();
		temp = todoList -> first;
		while(temp != NULL){
			cout << temp -> Getheader() << ", " << temp -> Getdescription() << endl;
			temp = temp -> next;
		}
	}
};

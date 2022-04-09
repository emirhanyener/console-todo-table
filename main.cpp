#include <iostream>
#include <fstream>
#include "todo.cpp"
using namespace std;

void addTodo(int id, string header, string description);

int main() {
	Todo * todo = new Todo(1, "test", "description test");
	todo->Print();
	
	addTodo(1,"test", "desc");
	
	return 0;
}

void addTodo(int id, string header, string description){
	ofstream DB("db.dat");

  	DB << id << "," << header << "," << description << ";";

  	DB.close();
}

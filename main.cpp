#include <iostream>
#include "filesystem.cpp"
using namespace std;

void addTodo(int id, string header, string description);

int main() {
	FileSystem file;
	file.ReadTodoList();
	file.AddTodo("test11", "desc11");
	file.ReadTodoList();
	file.AddTodo("test12", "desc12");
	file.DeleteTodo("test11");
	file.AddTodo("test13", "desc13");
	file.ReadTodoList();
	file.WriteTodoList();
	
	return 0;
}


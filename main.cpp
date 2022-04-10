#include <iostream>
#include "filesystem.cpp"
using namespace std;

void addTodo(int id, string header, string description);

int main() {
	FileSystem file;
	file.ReadTodoList();
	file.AddTodo("deneme1", "aciklama1");
	file.ReadTodoList();
	file.AddTodo("deneme1", "aciklama1");
	file.DeleteTodo("deneme1");
	file.AddTodo("deneme2", "aciklama1");
	file.ReadTodoList();
	file.WriteTodoList();
	
	
	return 0;
}


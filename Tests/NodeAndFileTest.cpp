#include <iostream>
#include <windows.h>
#include "../include/Utils/NodeManager.h"

using namespace std;

int main() {
	NodeManager file;
	cout << "todo add test;" << endl;
	file.AddTodo("test1", "desc1", "clmn1");
	file.ReadTodoList();
	cout << "------------------------------" << endl;
	cout << "column add test;" << endl;
	file.AddColumn("clmn1");
	file.ReadColumnList();
	cout << "------------------------------" << endl;
	cout << "todo add test;" << endl;
	file.AddTodo("test2", "desc2", "clmn1");
	file.AddTodo("test3", "desc3", "clmn1");
	file.ReadTodoList();
	cout << "------------------------------" << endl;
	file.WriteTodoList();
	file.WriteColumnList();
	cout << "todo delete test;" << endl;
	file.DeleteTodo("test3");
	file.ReadTodoList();
	cout << "------------------------------" << endl;
	cout << "column delete test;" << endl;
	file.DeleteColumn("clmn1");
	file.DeleteTodo("test2");
	file.ReadTodoList();
	file.ReadColumnList();
	cout << "------------------------------" << endl;
	cout << "column delete test;" << endl;
	file.DeleteColumn("clmn1");
	file.ReadColumnList();
	
	return 0;
}


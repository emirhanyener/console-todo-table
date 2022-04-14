#include <iostream>
#include <windows.h>
#include "headers/FileSystem.h"

using namespace std;

int main() {
	FileSystem file;
	string command = "";
	string value = "";
	string description = "";
	string column = "";
	while(command != "exit"){
		cout << "commands;" << endl << "+column" << endl << "+todo" << endl << "+exit" << endl << "command : ";
		cin >> command;
		if(command == "column"){
			cout << "commands;" << endl << "+list" << endl << "+add" << endl << "+delete" << endl << "+save" << endl << "+exit" << endl << "command : ";
			cin >> command;
			if(command == "add"){
				cout << "column > add > header name : ";
				cin >> value;
				file.AddColumn(value);
				cout << value << "added." << endl;
			}
			if(command == "list"){
				file.ReadColumnList();
			}
			if(command == "delete"){
				cout << "column > delete > header name : ";
				cin >> value;
				file.DeleteColumn(value);
				cout << value << "deleted." << endl;
			}
			if(command == "save"){
				file.WriteColumnList();
				cout << "columns saved a file." << endl;
			}
		}
		if(command == "todo"){
			cout << "commands;" << endl << "+list" << endl << "+add" << endl << "+delete" << endl << "+save" << endl << "+exit" << endl << "command : ";
			cin >> command;
			if(command == "add"){
				cout << "todo > add > header name : ";
				cin >> value;
				cout << "todo > add > descrition : ";
				cin >> description;
				cout << "todo > add > column name : ";
				cin >> column;
				file.AddTodo(value, description, column);
				cout << value << "added." << endl;
			}
			if(command == "list"){
				file.ReadTodoList();
			}
			if(command == "delete"){
				cout << "todo > delete > header name : ";
				cin >> value;
				file.DeleteTodo(value);
				cout << value << "deleted." << endl;
			}
			if(command == "save"){
				file.WriteTodoList();
				cout << "todo saved a file." << endl;
			}
		}
	}
	
	return 0;
}


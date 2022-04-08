#include <iostream>
#include "todo.cpp"
using namespace std;

int main() {
	Todo * todo = new Todo(1, "test", "description test");
	todo->Print();
	return 0;
}

#include "8.h"

int main() {
	List list;
	list.Create(100, list);
	list.Insert(0, 1);
	list.Insert(1, 3);
	list.Insert(2, 4);

	list.Display();

	list.Delete(1);
	list.Display();

	list.Insert(5, 2);
}

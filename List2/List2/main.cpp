#include "../List2/List.h"
template<typename T>
int main()
{
	List<T> list1;
	list1.pushBack(4);
	list1.pushBack(2);
	list1.pushBack(3);
	list1.pushBack(6);
	std::cout << list1.toString() << "\n" << std::endl;
	return 0;
}
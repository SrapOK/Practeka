#include "Manager.h"

template<typename T>
void Manager<T>::add(T& item)
{
	std::unique_ptr<T> pitem;
	list.push_back(pitem);
}

template<typename T>
void Manager<T>::drow(void)
{
	for (size_t i = 0; i < list.size(); i++) {
		window.draw(list[i].sprite());
	}
}

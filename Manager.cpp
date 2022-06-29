#include "Manager.h"


void Manager::add(Creature* _item)
{
	if (_item == nullptr) throw std::domain_error("void Manager<T>::add(T* item)");
	list.push_back(_item);
}

void Manager::display(void)
{
	for (size_t i = 0; i < list.size(); i++) {
		window.draw(list[i]->sprite());
	}
}

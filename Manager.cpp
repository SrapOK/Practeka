#include "Manager.h"




void Manager::update(float _time)
{
	for (size_t i = 0; i < list.size(); i++) {
		if (!list[i]->alive()) {
			delete list[i];
			list.erase(list.begin() + i);
		}
		else {
			list[i]->get_command(_time);
			list[i]->move();
		}
	}
}

void Manager::add(Creature* _item)
{
	if (_item == nullptr) throw std::domain_error("void Manager::add(T* item)");

	list.push_back(_item);
}

void Manager::display(void)
{
	for (size_t i = 0; i < list.size(); i++) {
		window.draw(list[i]->sprite());
	}
}

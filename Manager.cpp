#include "Manager.h"

void Manager::print(void)
{
	for (auto i = list.begin(); i != list.end(); ++i) {
		window.draw((*i)->sprite());
	}
}



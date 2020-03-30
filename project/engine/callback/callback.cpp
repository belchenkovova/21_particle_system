#include "callback.h"

using namespace		engine;

void				callback::test(event::type type)
{
	if (this->type == type)
		functor::run();
}
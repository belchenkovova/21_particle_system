#include "callback.h"

using namespace		engine;

void				callback::test(event::type type)
{
	if (not block and this->type == type)
		functor::run();
}
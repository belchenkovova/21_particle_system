#include "functor.h"

using namespace			engine;

						functor::functor(std::function<void()> &function) :
						function(function)
{}

void 					functor::run() const
{
	function();
}
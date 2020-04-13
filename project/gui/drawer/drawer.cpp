#include "drawer.h"

using namespace		gui;

					drawer::drawer(shared_ptr<object> &target, float relative_position) :
					target(target), relative_position(relative_position)
{}

void				drawer::render_virtual() const
{

}
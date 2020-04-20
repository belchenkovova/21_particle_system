#include "manager.h"

using namespace 	particle_system;

void				manager::initialize(initialization method)
{
	arguments.position.acquire();

	switch (method)
	{
		case initialization::null :
			kernels.initialize_as_null.run();
			break ;
		case initialization::sphere :
			kernels.initialize_as_sphere.run();
			break ;
		case initialization::cube :
			kernels.initialize_as_cube.run();
			break ;
		case initialization::tetrahedron :
			kernels.initialize_as_tetrahedron.run();
			break ;
	}

	arguments.position.release();
}

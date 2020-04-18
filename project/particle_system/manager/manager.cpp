#include "particle_system/manager/manager.h"

using namespace			particle_system;

						manager::manager(engine::core &engine, computer::core &computer) :
						engine(engine),
						computer(computer)
{
	engine_start();
	computer_start();
}
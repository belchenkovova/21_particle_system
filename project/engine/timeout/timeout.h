#pragma once

#include "engine/namespace.h"
#include "engine/functor/functor.h"

class				engine::timeout : public engine::functor
{
public :

	template		<typename... args_type>
	explicit		timeout(float wait, args_type ...args) :
					functor(args...), wait(wait) {}

	void 			use()
	{
		finish.reset();
		is_working = true;
	}

	void 			test(float now)
	{
		if (not is_working)
			return ;
		if (not finish)
			finish.emplace(now + wait);
		if (now >= finish)
		{
			is_working = false;
			functor::run();
		}
	}

private :

	const float		wait;
	optional<float>	finish;
	bool			is_working = false;
};
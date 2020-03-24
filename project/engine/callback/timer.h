#pragma once

#include "engine/namespace.h"
#include "engine/callback/callback.h"

template				<auto t_functor, typename t_type>
class					engine::timer : public engine::callback::real<t_functor, t_type>
{
public :

						timer(t_type &data, const float &period) :
						engine::callback::real<t_functor, t_type>(data),
						period(period)
	{}
						~timer() override = default;

	void				test(const float &new_timestamp)
	{
		if (new_timestamp - last_timestamp >= period)
		{
			engine::callback::real<t_functor, t_type>::run();
			last_timestamp = new_timestamp;
		}
	}


private :

	const float			period{0.f};
	float				last_timestamp{0.f};
};
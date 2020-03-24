#pragma once

#include "engine/namespace.h"

namespace				engine::callback
{
	class				abstract
	{
	public :

						abstract() = default;
		virtual			~abstract() = default;

		virtual void	run() = 0;
	};

	template			<auto t_functor, typename t_type>
	class				real : abstract
	{
	public :

		explicit		real(t_type &data) :
						data(data)
		{}
						~real() override = default;

		void			run() override
		{
			t_functor(data);
		}

	private :

		t_type			&data;

	};
}
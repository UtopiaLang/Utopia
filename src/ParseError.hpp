#pragma once

#include "Error.hpp"

namespace Utopia
{
	class ParseError : public Error
	{
	public:
		using Error::Error;
	};
}

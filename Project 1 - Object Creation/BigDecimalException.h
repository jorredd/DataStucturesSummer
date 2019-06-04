#pragma once
#include "CharException.h"
using namespace projectOne;
namespace projectOne {
	class BigDecimalException : public CharException
	{
	public:
		BigDecimalException();
		~BigDecimalException();
	};

}
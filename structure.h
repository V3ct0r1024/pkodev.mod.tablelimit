#pragma once
#include <string>

namespace pkodev
{
	// Limit structure
	struct limit
	{
		// Table name
		std::string name;

		// Limit
		unsigned int max_size;

		// Original function pointer
		LPVOID* original_func;

		// Hook function poiunter
		LPVOID hook_func;

		// Constructor
		limit() :
			name(""),
			max_size(0),
			original_func(nullptr),
			hook_func(nullptr)
		{

		}

		// Constructor
		limit(const std::string& name_, unsigned int max_size_, LPVOID* original_func_, LPVOID hook_func_) :
			name(name_),
			max_size(max_size_),
			original_func(original_func_),
			hook_func(hook_func_)
		{

		}
	};
}
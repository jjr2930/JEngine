#pragma once
#include <stdint.h>
#include <string>

using namespace std;

namespace JSample 
{
	static uint32_t objectCount = 0;
	class JObject
	{
	protected:
		uint32_t m_id;
		wstring _name;

	public:
		JObject();

		virtual ~JObject() {}

		wstring GetName();

		void SetName(wstring value);

		uint32_t GetID() const;
	};
}


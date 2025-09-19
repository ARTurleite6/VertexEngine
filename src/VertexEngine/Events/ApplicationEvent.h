#pragma once

#include "Event.h"

namespace VertexEngine
{
	class WindowCloseEvent final : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowClose)
	};
}

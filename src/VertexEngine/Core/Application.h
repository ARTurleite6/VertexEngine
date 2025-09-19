#pragma once

#include "VertexEngine/Core/Window.h"
#include "VertexEngine/Events/ApplicationEvent.h"
#include "VertexEngine/Events/Event.h"

namespace VertexEngine
{
	class Application final
	{
	public:
		Application();
		void Init();
		void Run();
		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running{true};
	};
}

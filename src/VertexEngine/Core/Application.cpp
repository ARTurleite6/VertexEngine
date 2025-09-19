#include "Application.h"

#include "VertexEngine/Events/Event.h"

namespace VertexEngine
{
	Application::Application()
		: m_Window{Window::Create()}
	{
	}

	void Application::Init()
	{
		m_Window->Init();
		m_Window->SetEventCallback([this](Event& e) {
			OnEvent(e);
		});
	}

	void Application::Run()
	{
		while(m_Running)
		{
			m_Window->ProcessEvents();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher{e};
		dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& e) {
			return OnWindowClose(e);
		});
	}

	bool Application::OnWindowClose(WindowCloseEvent& e [[maybe_unused]])
	{
		m_Running = false;
		return true;
	}
}

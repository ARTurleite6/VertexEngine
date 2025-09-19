#include "VertexEngine/Core/Application.h"

int main()
{
	VertexEngine::Log::Init();
	VertexEngine::Application app;
	app.Init();
	app.Run();
	return 0;
}

#include "ftpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Fountain {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}
#include "ftpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h" 

namespace Fountain {
	VertexBuffer * VertexBuffer::Create(float * vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: FT_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}

		FT_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	IndexBuffer * IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: FT_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indices, size);
		}

		FT_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
#include "ftpch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Fountain {

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    FT_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(width, height);
		}

		FT_CORE_ASSERT(false, "Unknow RendererAPI!");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
			switch (Renderer::GetAPI())
			{
				case RendererAPI::API::None:    FT_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
				case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(path);
			}

			FT_CORE_ASSERT(false, "Unknow RendererAPI!");
			return nullptr;
	}
}
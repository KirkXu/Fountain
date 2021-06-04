#include "ftpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Fountain {
	OpenGLContext::OpenGLContext(GLFWwindow * windowHandle)
		: m_WindowHandle(windowHandle)
	{
		FT_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		FT_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		FT_CORE_ASSERT(status, "Failed to initialize Glad!");

		FT_CORE_INFO("OpenGL Info:");
		FT_CORE_INFO(" Vendor: {0}", glGetString(GL_VENDOR));
		FT_CORE_INFO(" Renderer: {0}", glGetString(GL_RENDERER));
		FT_CORE_INFO(" Version: {0}", glGetString(GL_VERSION));

#ifdef FT_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		FT_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Fountain requires at least OpenGL version 4.5!");
#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		FT_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}
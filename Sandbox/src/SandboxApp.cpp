#include <Fountain.h>
#include <Fountain/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"

class ExampleLayer : public Fountain::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.0f / 720.0f)
	{
		m_VertexArray = Fountain::VertexArray::Create();

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 1.0f, 1.0f,
			 0.0f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		};


		Fountain::Ref<Fountain::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Fountain::VertexBuffer::Create(vertices, sizeof(vertices)));
		Fountain::BufferLayout layout = {
			{ Fountain::ShaderDataType::Float3, "a_Position"},
			{ Fountain::ShaderDataType::Float4, "a_Color"}
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[3] = { 0, 1, 2 }; 
		Fountain::Ref<Fountain::IndexBuffer> indexBuffer;
		indexBuffer.reset(Fountain::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA = Fountain::VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Fountain::Ref<Fountain::VertexBuffer> squareVB;
		squareVB.reset(Fountain::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Fountain::ShaderDataType::Float3, "a_Position"},
			{ Fountain::ShaderDataType::Float2, "a_TexCoord"}
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		unsigned int squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		Fountain::Ref<Fountain::IndexBuffer> squareIB;
		squareIB.reset(Fountain::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader = Fountain::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader = Fountain::Shader::Create("flatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = Fountain::Texture2D::Create("assets/textures/Cloud.png");
		m_JerryLogoTexture = Fountain::Texture2D::Create("assets/textures/JerryLogo.png");

		std::dynamic_pointer_cast<Fountain::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<Fountain::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(Fountain::Timestep ts) override
	{
		// Update
		m_CameraController.OnUpdate(ts);

		// Render
		Fountain::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Fountain::RenderCommand::Clear();

		Fountain::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Fountain::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Fountain::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Fountain::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}
		
		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		Fountain::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		m_JerryLogoTexture->Bind();
		Fountain::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		// Triangle
		// Fountain::Renderer::Submit(m_Shader, m_VertexArray);

		Fountain::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(Fountain::Event& e) override
	{
		m_CameraController.OnEvent(e);

		if (e.GetEventType() == Fountain::EventType::WindowResize)
		{
			auto& re = (Fountain::WindowResizeEvent&)e;

			// float zoom = (float)re.GetWidth() / 1280.0f;
			// m_CameraController.SetZoomLevel(zoom);
		}
	}

private:
	Fountain::ShaderLibrary m_ShaderLibrary;
	Fountain::Ref<Fountain::Shader> m_Shader;
	Fountain::Ref<Fountain::VertexArray> m_VertexArray;

	Fountain::Ref<Fountain::Shader> m_FlatColorShader;
	Fountain::Ref<Fountain::VertexArray> m_SquareVA;

	Fountain::Ref<Fountain::Texture2D> m_Texture, m_JerryLogoTexture;

	Fountain::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox : public Fountain::Application
{
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}
	
	~Sandbox()
	{

	}
};

Fountain::Application* Fountain::CreateApplication()
{
	return new Sandbox();
}
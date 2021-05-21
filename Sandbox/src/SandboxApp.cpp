#include <Fountain.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public Fountain::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Fountain::VertexArray::Create());

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

		m_SquareVA.reset(Fountain::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		Fountain::Ref<Fountain::VertexBuffer> squareVB;
		squareVB.reset(Fountain::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Fountain::ShaderDataType::Float3, "a_Position"}
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

		m_Shader.reset(Fountain::Shader::Create(vertexSrc, fragmentSrc));

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

		m_FlatColorShader.reset(Fountain::Shader::Create(flatColorShaderVertexSrc, flatColorShaderFragmentSrc));

	}

	void OnUpdate(Fountain::Timestep ts) override
	{
		// FT_INFO("Delta time: {0}s ({1}ms)", ts.GetSeconds(), ts.GetMilliseconds());
		if (Fountain::Input::IsKeyPressed(FT_KEY_LEFT))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;
		else if (Fountain::Input::IsKeyPressed(FT_KEY_RIGHT))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;

		if (Fountain::Input::IsKeyPressed(FT_KEY_UP))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;
		else if (Fountain::Input::IsKeyPressed(FT_KEY_DOWN))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;

		if (Fountain::Input::IsKeyPressed(FT_KEY_A))
			m_CameraRotation -= m_CameraRotationSpeed * ts;
		if (Fountain::Input::IsKeyPressed(FT_KEY_D))
			m_CameraRotation += m_CameraRotationSpeed * ts;

		Fountain::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Fountain::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Fountain::Renderer::BeginScene(m_Camera);

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
		
		Fountain::Renderer::Submit(m_Shader, m_VertexArray);

		Fountain::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(Fountain::Event& event) override
	{

	}

private:
	Fountain::Ref<Fountain::Shader> m_Shader;
	Fountain::Ref<Fountain::VertexArray> m_VertexArray;

	Fountain::Ref<Fountain::Shader> m_FlatColorShader;
	Fountain::Ref<Fountain::VertexArray> m_SquareVA;

	Fountain::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f; 

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox : public Fountain::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	
	~Sandbox()
	{

	}
};

Fountain::Application* Fountain::CreateApplication()
{
	return new Sandbox();
}
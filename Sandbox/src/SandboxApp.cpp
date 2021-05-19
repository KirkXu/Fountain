#include <Fountain.h>

#include "imgui/imgui.h"

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


		std::shared_ptr<Fountain::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Fountain::VertexBuffer::Create(vertices, sizeof(vertices)));


		Fountain::BufferLayout layout = {
			{ Fountain::ShaderDataType::Float3, "a_Position"},
			{ Fountain::ShaderDataType::Float4, "a_Color"}
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[3] = { 0, 1, 2 };
		std::shared_ptr<Fountain::IndexBuffer> indexBuffer;
		indexBuffer.reset(Fountain::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Fountain::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};

		std::shared_ptr<Fountain::VertexBuffer> squareVB;
		squareVB.reset(Fountain::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Fountain::ShaderDataType::Float3, "a_Position"}
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		unsigned int squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Fountain::IndexBuffer> squareIB;
		squareIB.reset(Fountain::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
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

		m_Shader.reset(new Fountain::Shader(vertexSrc, fragmentSrc));

		std::string blueShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";

		std::string blueShaderFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			void main()
			{
				color = vec4(0, 0, 1.0, 1.0);
			}
		)";

		m_BlueShader.reset(new Fountain::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));

	}

	void OnUpdate(Fountain::Timestep ts) override
	{
		FT_INFO("Delta time: {0}s ({1}ms)", ts.GetSeconds(), ts.GetMilliseconds());
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

		Fountain::Renderer::Submit(m_BlueShader, m_SquareVA);
		Fountain::Renderer::Submit(m_Shader, m_VertexArray);

		Fountain::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{

	}

	void OnEvent(Fountain::Event& event) override
	{

	}

private:
	std::shared_ptr<Fountain::Shader> m_Shader;
	std::shared_ptr<Fountain::VertexArray> m_VertexArray;

	std::shared_ptr<Fountain::Shader> m_BlueShader;
	std::shared_ptr<Fountain::VertexArray> m_SquareVA;

	Fountain::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f; 

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;
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
#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
{
}

void Sandbox2D::OnAttach()
{
	FT_PROFILE_FUNCTION();

	m_CloudTexture = Fountain::Texture2D::Create("assets/textures/Cloud.png");
}

void Sandbox2D::OnDetach()
{
	FT_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Fountain::Timestep ts)
{
	FT_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Fountain::Renderer2D::ResetStats();
	{
		FT_PROFILE_SCOPE("Renderer Prep");
		Fountain::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Fountain::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		FT_PROFILE_SCOPE("Renderer Draw");
		Fountain::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Fountain::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Fountain::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Fountain::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		Fountain::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.f }, m_CloudTexture, 10.0f);
		Fountain::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CloudTexture, 20.0f);
		Fountain::Renderer2D::EndScene();

		Fountain::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 1.0f };
				Fountain::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Fountain::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	FT_PROFILE_FUNCTION();
	
	
		ImGui::Begin("Settings");

		auto stats = Fountain::Renderer2D::GetStats();
		ImGui::Text("Renderer2D Stats:");
		ImGui::Text("Draw Calls: %d", stats.DrawCalls);
		ImGui::Text("Quads: %d", stats.QuadCount);
		ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
		ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

		ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

		ImGui::End();
}

void Sandbox2D::OnEvent(Fountain::Event& e)
{
	m_CameraController.OnEvent(e);
}

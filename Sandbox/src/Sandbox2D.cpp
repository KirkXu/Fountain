#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
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
	{
		FT_PROFILE_SCOPE("Renderer Prep");
		Fountain::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Fountain::RenderCommand::Clear();
	}

	{
		FT_PROFILE_SCOPE("Renderer Draw");
		Fountain::Renderer2D::BeginScene(m_CameraController.GetCamera());
		// Fountain::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(-45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		Fountain::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Fountain::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		// Fountain::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1 }, { 10.0f, 10.0f }, m_CloudTexture, 10.0f);
		Fountain::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	FT_PROFILE_FUNCTION();
	
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

	ImGui::End();
}

void Sandbox2D::OnEvent(Fountain::Event& e)
{
	m_CameraController.OnEvent(e);
}

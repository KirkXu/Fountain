#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chrono>

template<typename Fn>
class Timer
{
public:
	Timer(const char* name, Fn&& func)
		: m_Name(name), m_Func(func), m_Stopped(false)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		if (!m_Stopped)
			Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		m_Stopped = true;

		float duration = (end - start) * 0.001f;

		std::cout << m_Name << ": " << duration << "ms" << std::endl;
		m_Func({ m_Name, duration });
	}
private:
	const char* m_Name;
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
	bool m_Stopped;
	Fn m_Func;
};

#define PROFILE_SCOPE(name) Timer timer##__LINE__(name, [&](ProfileResult profileResult) { m_ProfileResults.push_back(profileResult); })

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	m_CloudTexture = Fountain::Texture2D::Create("assets/textures/Cloud.png");

}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Fountain::Timestep ts)
{
	FT_PROFILE_FUNCTION();

	// Update
	{
		FT_PROFILE_SCOPE("CameraController::OnUpdate");
		m_CameraController.OnUpdate(ts);
	}

	// Render
	{
		FT_PROFILE_SCOPE("Renderer Prep");
		Fountain::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Fountain::RenderCommand::Clear();
	}

	{
		FT_PROFILE_SCOPE("Renderer Draw");
		Fountain::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Fountain::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Fountain::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Fountain::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1 }, { 10.0f, 10.0f }, m_CloudTexture);
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

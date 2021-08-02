#pragma once

#include "Fountain.h"

class Sandbox2D : public Fountain::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Fountain::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Fountain::Event& e) override;

private:
	Fountain::OrthographicCameraController m_CameraController;

	// Temp
	Fountain::Ref<Fountain::VertexArray> m_SquareVA;
	Fountain::Ref<Fountain::Shader> m_FlatColorShader;
	Fountain::Ref<Fountain::Framebuffer> m_Framebuffer;

	Fountain::Ref<Fountain::Texture2D> m_CloudTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

};
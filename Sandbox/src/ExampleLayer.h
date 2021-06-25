#pragma once

#include "Fountain.h"

class ExampleLayer : public Fountain::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Fountain::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Fountain::Event& e) override;
private:
	Fountain::ShaderLibrary m_ShaderLibrary;
	Fountain::Ref<Fountain::Shader> m_Shader;
	Fountain::Ref<Fountain::VertexArray> m_VertexArray;

	Fountain::Ref<Fountain::Shader> m_FlatColorShader;
	Fountain::Ref<Fountain::VertexArray> m_SquareVA;

	Fountain::Ref<Fountain::Texture2D> m_Texture, m_ChernoLogoTexture;

	Fountain::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

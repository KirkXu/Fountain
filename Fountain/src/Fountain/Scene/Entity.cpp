#include "ftpch.h"
#include "Entity.h"

namespace Fountain {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}
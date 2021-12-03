
#pragma once

#include <GLFW/glfw3.h>
#include "GameObject.h"
#include "GameObjectContainer.h"
#include "ParticleSystem.h"
#include "ParticleAffector.h"
#include "ParticleAffectorContainer.h"

class Application
{
private:
	Application();

	GameObjectContainer<GameObject> m_GOs;
	std::list<GameObject*>::iterator iteGO;

	ParticleSystem* m_particleSystem0;
	ParticleSystem* m_particleSystem1;
	ParticleSystem* m_particleSystem2;

	ParticleAffectorContainer<ParticleAffector> m_PAs;
	std::list<ParticleAffector*>::iterator itePA;

	//ParticleSystem* m_ps1;
	//ParticleAffector* m_affector1;

public:
    ~Application();

	GameObject* GO;

	Sprite* m_sprite0;
	Sprite* m_sprite1;
	Sprite* m_sprite2;
	Sprite* m_sprite3;
	Sprite* m_sprite4;
	Sprite* m_sprite5;
	Sprite* m_sprite6;

	// overload spawn gameobject function
	GameObject* Spawn();
	GameObject* Spawn(GameObject* duplicate);
	GameObject* Spawn(Transform2D transform);
	GameObject* Spawn(Vector2 position, float rotation, Vector2 scale);
	GameObject& FindGameObject(int index);
	void Destroy(GameObject* gameObject);

	// create singleton
	static Application& Instance();
	float time;

	void Start();
	void Update(float deltaTime);
	void Draw();
};


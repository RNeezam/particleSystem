
#pragma once

#include "ParticleObject.h"
#include "ParticleObjectContainer.h"
#include "ParticleAffector.h"
#include "ParticleAffectorContainer.h"
#include "Sprite.h"
#include "Transform2D.h"

class ParticleSystem
{
private:
	float emissionRate;
	float emissionCounter;
	float particleLife;
	Transform2D m_transform;

	ParticleObjectContainer<ParticleObject> m_POs;
	std::list<ParticleObject*>::iterator itePO;

	ParticleAffectorContainer<ParticleAffector> m_PAs;
	std::list<ParticleAffector*>::iterator itePA;

	Sprite* m_sprite0;
	
public:
	ParticleSystem();
	ParticleSystem(Sprite* sprite);
	~ParticleSystem();

	//ParticleObject* PO;

	// overload spawn function
	ParticleObject* Spawn();
	ParticleObject* Spawn(ParticleObject* duplicate);
	ParticleObject* Spawn(Transform2D transform);
	ParticleObject* Spawn(Vector2 position, float rotation, Vector2 scale);
	ParticleObject& FindParticleObject(int index);
	void Destroy(ParticleObject* particle);

	void SetEmissionRate(float rate);
	void SetLocation(Vector2 position);
	void SetParticleLife(float life);
	void AddAffector(ParticleAffector* affector);

	void Start();
	void Update(float deltaTime);
	void Draw();
};


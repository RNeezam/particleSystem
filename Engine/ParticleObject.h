
#pragma once

#include "GameObject.h"

class ParticleObject : public GameObject
{
private:
	Vector2 m_velocity;
	Vector2 m_acceleration;

	float m_density;
	float m_mass;
	float m_volume;

	float m_life;
	float m_defaultLife;

public:
	ParticleObject();
	ParticleObject(Sprite& sprite, Vector2 position, Vector2 velocity, Vector2 acceleration);
	~ParticleObject();

	float GetLife() { return m_life; };
	float GetDefaultLife() { return m_defaultLife; };

	Vector2 GetAcceleration() { return m_acceleration; };
	Vector2 GetVelocity() { return m_velocity; };

	void SetLife(float life);
	void SetAcceleration(Vector2 acceleration);
	void SetVelocity(Vector2 velocity);
	
	void Start();
	void Update(float deltaTime);
};


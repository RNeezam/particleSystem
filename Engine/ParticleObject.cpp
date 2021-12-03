
#include "ParticleObject.h"

ParticleObject::ParticleObject()
{
	m_defaultLife = 1.0f;
	m_life = m_defaultLife;
	m_velocity = Vector2(0.0f, 0.0f);
	m_acceleration = Vector2(0.0f, 0.0f);
}

ParticleObject::ParticleObject(Sprite& sprite, Vector2 position, Vector2 velocity, Vector2 acceleration) : GameObject(sprite)
{
	Transform2D transform = GetTransform();
	transform.position = position;
	SetTransform(transform);

	m_defaultLife = 1.0f;
	m_life = m_defaultLife;
	m_velocity = velocity;
	m_acceleration = acceleration;
}

ParticleObject::~ParticleObject()
{
}

void ParticleObject::SetLife(float life)
{
	m_life = life;
}

void ParticleObject::SetAcceleration(Vector2 acceleration)
{
	m_acceleration = acceleration;
}

void ParticleObject::SetVelocity(Vector2 velocity)
{
	m_velocity = velocity;
}

void ParticleObject::Start()
{
	m_life = m_defaultLife;
}

void ParticleObject::Update(float deltaTime)
{
	//std::cout << "Update Particle Info" << std::endl;

	// acceleration -> velocity -> position
	m_velocity += m_acceleration;
	m_transform.position += m_velocity;

	m_life -= deltaTime;
	//std::cout << "Update Particle Info b: " << m_life << std::endl;
}

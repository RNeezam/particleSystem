
#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
}

ParticleSystem::ParticleSystem(Sprite* sprite)
{
	m_sprite0 = sprite;
	emissionRate = 0.1f;
	emissionCounter = 0.0f;
}

ParticleSystem::~ParticleSystem()
{
}

ParticleObject* ParticleSystem::Spawn()
{
	return Spawn(new ParticleObject);
}

ParticleObject* ParticleSystem::Spawn(ParticleObject* duplicate)
{
	m_POs.GetList().push_back(duplicate);
	return duplicate;
}

ParticleObject* ParticleSystem::Spawn(Transform2D transform)
{
	ParticleObject* PO = new ParticleObject();
	PO->SetTransform(transform);

	return Spawn(PO);
}

ParticleObject* ParticleSystem::Spawn(Vector2 position, float rotation, Vector2 scale)
{
	Transform2D transform;
	transform.position = position;
	transform.rotation = rotation;
	transform.scale = scale;

	return Spawn(transform);
}

ParticleObject& ParticleSystem::FindParticleObject(int index)
{
	return m_POs.GetItem(index);
}

void ParticleSystem::Destroy(ParticleObject* particle)
{
	ParticleObject* storedPOs = particle;
	m_POs.GetList().remove(particle);
	delete particle;
}

void ParticleSystem::SetEmissionRate(float rate)
{
	emissionRate = rate;
}

void ParticleSystem::SetLocation(Vector2 position)
{
	m_transform.position.x = position.x;
	m_transform.position.y = position.y;	
}

void ParticleSystem::SetParticleLife(float life)
{
	particleLife = life;
}

void ParticleSystem::AddAffector(ParticleAffector* affector)
{
	m_PAs.GetList().push_back(affector);
}

void ParticleSystem::Start()
{

}

void ParticleSystem::Draw()
{
	itePO = m_POs.GetList().begin();

	while (itePO != m_POs.GetList().end())
	{
		ParticleObject PO = **itePO;
		PO.Draw();
		++itePO;
	}
}

void ParticleSystem::Update(float deltaTime)
{
	emissionCounter += emissionRate;

	while (emissionCounter >= 1.0f)
	{
		emissionCounter--;

		// emit particle
		ParticleObject* PO = Spawn
		(
			Vector2(m_transform.position.x, m_transform.position.y), 0.0f, Vector2(1.0f, 1.0f)
		);

		PO->Start();

		PO->SetLife(particleLife);

		PO->SetSprite(*m_sprite0);
	}

	// update particle movement
	itePO = m_POs.GetList().begin();

	while (itePO != m_POs.GetList().end())
	{
		ParticleObject* PO = *itePO;

		// remove particle if life <= 0
		if (PO->GetLife() <= 0.0f)
		{
			itePO = m_POs.GetList().erase(itePO);
		}
		else
		{
			itePA = m_PAs.GetList().begin();

			while (itePA != m_PAs.GetList().end())
			{
				ParticleAffector* PA = *itePA;
				PA->affectParticleUpdate(PO);

				++itePA;
			}		

			// update particle information
			PO->Update(deltaTime);
			++itePO;
		}
	}
}



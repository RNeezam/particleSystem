
#pragma once

#include "ParticleObject.h"

class ParticleAffector
{
public:
	virtual void affectParticleUpdate(ParticleObject* particle) = 0;
};

class ColorAffector : public ParticleAffector
{
protected:
	Color origin;
	Color target;

public:
	virtual void affectParticleUpdate(ParticleObject* particle)
	{
		Color particleColor = particle->GetSprite().GetColor();

		float t = particle->GetLife() / particle->GetDefaultLife();
		particleColor.R = Lerp(t, target.R, origin.R);
		particleColor.G = Lerp(t, target.G, origin.G);
		particleColor.B = Lerp(t, target.B, origin.B);
		particleColor.A = Lerp(t, target.A, origin.A);

		particle->GetSprite().SetColor(particleColor);
	}

	void SetColor(Color originColor, Color targetColor)
	{
		origin = originColor;
		target = targetColor;
	}

	float Lerp(float current, float A, float B)
	{
		float temp;
		temp = (1 - current) * A + current * B;
		return temp;
	}
};

class AccelerationAffector : public ParticleAffector
{
protected:
	Vector2 acceleration;

public:
	virtual void affectParticleUpdate(ParticleObject* particle)
	{
		Vector2 particleAcceleration = particle->GetAcceleration();
		Vector2 newAcceleration = Vector2
		(
			particleAcceleration.x + acceleration.x, particleAcceleration.y + acceleration.y
		);

		particle->SetAcceleration(newAcceleration);
	}

	void SetAcceleration(Vector2 _acceleration)
	{
		acceleration.x = _acceleration.x;
		acceleration.y = _acceleration.y;
	}
};

class RandomPositionAffector : public ParticleAffector
{
protected:
	int randX;
	int randY;

public:
	virtual void affectParticleUpdate(ParticleObject* particle)
	{
		Vector2 current;

		if (randX != 0)
		{
			current.x = rand() % randX - (randX / 2);
		}
		if (randY != 0)
		{
			current.y = rand() % randY - (randY / 2);
		}

		Transform2D t = particle->GetTransform();
		t.position.x += current.x;
		t.position.y += current.y;

		particle->SetTransform(t);
	}

	void SetRandom(int randomX, int randomY)
	{
		randX = randomX;
		randY = randomY;
	}
};

class ScaleAffector : public ParticleAffector
{
protected:
	Vector2 originScale;
	Vector2 targetScale;

public:
	virtual void affectParticleUpdate(ParticleObject* particle)
	{
		Transform2D t = particle->GetTransform();

		float point = particle->GetLife() / particle->GetDefaultLife();

		t.scale.x = Lerp(point, targetScale.x, originScale.x);
		t.scale.y = Lerp(point, targetScale.y, originScale.y);

		particle->SetTransform(t);
	}

	void SetScale(Vector2 origin, Vector2 target)
	{
		originScale = origin;
		targetScale = target;
	}

	float Lerp(float current, float A, float B)
	{
		float temp;
		temp = (1 - current) * A + current * B;
		return temp;
	}
};

class RotationAffector : public ParticleAffector
{
protected:
	float rotationSpeed;

public:
	virtual void affectParticleUpdate(ParticleObject* particle)
	{

		Transform2D t = particle->GetTransform();
		t.rotation += rotationSpeed;

		particle->SetTransform(t);
	}

	void SetRotator(float _rotationSpeed)
	{
		rotationSpeed = _rotationSpeed;
	}
};

class OrbitAffector : public ParticleAffector
{
protected:
	Vector2 position;
	Vector2 radius;
	Vector2 rate;
	float time;

public:
	virtual void affectParticleUpdate(ParticleObject* particle)
	{
		Transform2D t = particle->GetTransform();

		t.position =
			Vector2
			(
				radius.x * (sin(time * rate.x) + t.position.x),
				radius.y * (cos(time * rate.y) + t.position.y)
			);

		//100.0f * (sin(time * 5.0f) + 1.0f), 100.0f * (cos(time * 5.0f) + 1.0f)

		particle->SetTransform(t);
	}

	void SetOrbit(Vector2 _position, Vector2 _radius, Vector2 _rate, float _time)
	{
		position = _position;
		radius = _radius;
		rate = _rate;
		time = _time;
	}
};

class BurstAffector : public ParticleAffector
{
protected:
	Vector2 origin;
	
public:
	virtual void affectParticleUpdate(ParticleObject* particle)
	{
		Vector2 currentAcceleration = particle->GetAcceleration();
		Vector2 currentVelocity = particle->GetVelocity();
		Vector2 originAcceleration = origin;

		//currentAcceleration = originAcceleration;

		if (currentAcceleration.x > originAcceleration.x)
		{
			currentVelocity.x = 0.0f;
			currentAcceleration.x -= originAcceleration.x;
		}
		else if (currentAcceleration.x < originAcceleration.x)
		{
			currentVelocity.x = 0.0f;
			currentAcceleration.x += originAcceleration.x;
		}

		particle->SetAcceleration(currentAcceleration);
		particle->SetVelocity(currentVelocity);
	}

	// set the origin as the burst acceleration, then reduce rapidly after reaching target
	void SetBurst(Vector2 _origin)
	{
		origin = _origin;
	}
};

class BounceAffector : public ParticleAffector
{
protected:
	Vector2 Position;

public:
	virtual void affectParticleUpdate(ParticleObject* particle)
	{
		Transform2D t = particle->GetTransform();
		Vector2 dynamicAcceleration;

		if (t.position.x > Position.x)
		{
			dynamicAcceleration.x -= 1.0f;
		}
		else if (t.position.x < Position.x)
		{
			dynamicAcceleration.x += 1.0f;
		}

		if (t.position.y > Position.y)
		{
			dynamicAcceleration.y -= 1.0f;
		}
		else if (t.position.y < Position.y)
		{
			dynamicAcceleration.y += 1.0f;
		}

		particle->SetAcceleration(dynamicAcceleration);
	}

	void SetBounce(Vector2 posA)
	{
		Position = posA;
	}
};

class RandomAccelerationAffector : public ParticleAffector
{
protected:
	int randX;
	int randY;

public:
	virtual void affectParticleUpdate(ParticleObject* particle)
	{
		Vector2 current;

		if (randX != 0)
		{
			current.x = rand() % randX - (randX / 2);
		}
		if (randY != 0)
		{
			current.y = rand() % randY - (randY / 2);
		}

		Vector2 acceleration = particle->GetAcceleration();
		acceleration.x += current.x;
		acceleration.y += current.y;

		particle->SetAcceleration(acceleration);
	}

	void SetRandom(int randomX, int randomY)
	{
		randX = randomX;
		randY = randomY;
	}
};

class RandomRotationAffector : public ParticleAffector
{
protected:
	int random;
	float rotation;

public:
	virtual void affectParticleUpdate(ParticleObject* particle)
	{
		if (random != 0)
		{
			rotation = rand() % random - (random / 2);
		}

		Transform2D t = particle->GetTransform();
		t.rotation = rotation;

		particle->SetTransform(t);
	}

	void SetRotator(int _random)
	{
		random = _random;
	}
};
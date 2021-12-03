
#include "Application.h"
#include <iostream>

Application::Application()
{
}

Application::~Application()
{
}

GameObject* Application::Spawn()
{
	return Spawn(new GameObject());
}

GameObject* Application::Spawn(GameObject* duplicate)
{
	m_GOs.GetList().push_back(duplicate);
	return duplicate;
}

GameObject* Application::Spawn(Transform2D transform)
{
	GameObject* GO = new GameObject();
	GO->SetTransform(transform);

	return Spawn(GO);
}

GameObject* Application::Spawn(Vector2 position, float rotation, Vector2 scale)
{
	Transform2D transform;
	transform.position = position;
	transform.rotation = rotation;
	transform.scale = scale;

	return Spawn(transform);
}

GameObject & Application::FindGameObject(int index)
{
	return m_GOs.GetItem(index);
}

void Application::Destroy(GameObject* gameObject)
{
	GameObject* storedGOs = gameObject;
	m_GOs.GetList().remove(gameObject);
	delete gameObject;
}

Application & Application::Instance()
{
	// return singleton
	static Application instance;
	return instance;
}

void Application::Start()
{
	std::cout << "APPLICATION STARTED" << std::endl;
	
	/*GO = Spawn(Vector2(400.0f, 300.0f), 45.0f, Vector2(1.0f, 1.0f));
	GO->GetSprite().SetFilePath("../media/Jake.bmp");*/
		
	GO = Spawn(Vector2(100.0f, 100.0f), 0.0f, Vector2(1.0f, 1.0f));
	GO->GetSprite().SetFilePath("../media/NomadAvatar.bmp");	
	
	/*GO = Spawn(Vector2(600.0f, 400.0f), 90.0f, Vector2(1.0f, 1.0f));
	GO->GetSprite().SetFilePath("../media/Solaire.bmp");*/	

	//=====
	//m_affector1 = ColorAffector(255, 255, 255, 1, 3, 3);
	//m_ps1 = new ParticleSystem(m_sprite222);
	//m_ps1->AddAffector(&m_affector1);
	//m_ps1->AddAffector(&m_affector2);
	//=====

	m_sprite0 = new Sprite();
	m_sprite0->SetFilePath("../media/Jake.bmp");

	m_sprite1 = new Sprite();
	m_sprite1->SetFilePath("../media/hand.bmp");

	m_sprite2 = new Sprite();
	m_sprite2->SetFilePath("../media/Solaire.bmp");

	m_sprite3 = new Sprite();
	m_sprite3->SetFilePath("../media/Pokeball.bmp");
	m_sprite3->SetColor(Color(255, 0, 255, 1));

	m_sprite4 = new Sprite();
	m_sprite4->SetFilePath("../media/Smoke.bmp");
	m_sprite4->SetBlendingMode(BLEND_ADDITIVE);

	m_sprite5 = new Sprite();
	m_sprite5->SetFilePath("../media/Knife.bmp");
	m_sprite5->SetBlendingMode(BLEND_ADDITIVE);

	m_sprite6 = new Sprite();
	m_sprite6->SetFilePath("../media/Butterfly.bmp");
	m_sprite6->SetBlendingMode(BLEND_ADDITIVE);

	ColorAffector* colorAffector0 = new ColorAffector();
	colorAffector0->SetColor(Color(255, 0, 0, 255), Color(0, 100, 0, 255));

	ColorAffector* colorAffector1 = new ColorAffector();
	colorAffector1->SetColor(Color(255, 255, 255, 255), Color(200, 200, 200, 255));

	AccelerationAffector* accelerationAffector0 = new AccelerationAffector();
	accelerationAffector0->SetAcceleration(Vector2(0.0f, 0.02f));

	AccelerationAffector* accelerationAffector1 = new AccelerationAffector();
	accelerationAffector1->SetAcceleration(Vector2(0.0f, -0.05f));

	RandomPositionAffector* randomPosAffector0 = new RandomPositionAffector();
	randomPosAffector0->SetRandom(20, 0);

	RotationAffector* rotatorAffector0 = new RotationAffector();
	rotatorAffector0->SetRotator(5.0f);

	ScaleAffector* scaleAffector0 = new ScaleAffector();
	scaleAffector0->SetScale(Vector2(1.0f, 1.0f), Vector2(3.0f, 3.0f));

	ScaleAffector* scaleAffector1 = new ScaleAffector();
	scaleAffector1->SetScale(Vector2(0.5, 0.5), Vector2(0.3f, 0.3f));

	BounceAffector* bounceAffector0 = new BounceAffector();
	bounceAffector0->SetBounce(Vector2(600.0f, 300.0f));

	RandomAccelerationAffector* randomAccelerationAffector0 = new RandomAccelerationAffector();
	randomAccelerationAffector0->SetRandom(5.0f, 5.0f);

	RandomRotationAffector* randomRotatorAffector0 = new RandomRotationAffector();
	randomRotatorAffector0->SetRotator(50.0f);

	m_particleSystem0 = new ParticleSystem(m_sprite4);
	m_particleSystem0->Start();
	m_particleSystem0->SetLocation(Vector2(400.0f, 50.0f));
	m_particleSystem0->SetEmissionRate(1.0f);
	m_particleSystem0->SetParticleLife(1.0f);
	m_particleSystem0->AddAffector(colorAffector0);
	m_particleSystem0->AddAffector(accelerationAffector0);
	m_particleSystem0->AddAffector(randomPosAffector0);

	m_particleSystem1 = new ParticleSystem(m_sprite5);
	m_particleSystem1->Start();
	m_particleSystem1->SetLocation(Vector2(200.0f, 550.0f));
	m_particleSystem1->SetEmissionRate(0.05f);
	m_particleSystem1->SetParticleLife(1.0f);
	m_particleSystem1->AddAffector(accelerationAffector1);
	m_particleSystem1->AddAffector(rotatorAffector0);
	m_particleSystem1->AddAffector(scaleAffector0);

	m_particleSystem2 = new ParticleSystem(m_sprite6);
	m_particleSystem2->Start();
	m_particleSystem2->SetLocation(Vector2(700.0f, 100.0f));
	m_particleSystem2->SetEmissionRate(0.03f);
	m_particleSystem2->SetParticleLife(5.0f);
	m_particleSystem2->AddAffector(bounceAffector0);
	m_particleSystem2->AddAffector(randomAccelerationAffector0);
	m_particleSystem2->AddAffector(randomRotatorAffector0);
	m_particleSystem2->AddAffector(scaleAffector1);
	m_particleSystem2->AddAffector(colorAffector1);
}

void Application::Update(float deltaTime)
{
	//std::cout << "APPLICATION UPDATED" << endl;

	time += deltaTime;

	/*Transform2D m_transform0;
	m_transform0 = FindGameObject(0).GetTransform();
	m_transform0.rotation = 100.0f * time;
	m_transform0.scale =
		Vector2
		(
			0.5f * (tan(time + 1.0f) + 1.0f), 0.5f * (tan(time + 1.0f) + 1.0f)
		);
	FindGameObject(0).SetTransform(m_transform0);*/	
	
	Transform2D m_transform1;
	m_transform1 = FindGameObject(0).GetTransform();
	m_transform1.position =
		Vector2
		(
			100.0f * (sin(time * 3.0f) + 1.0f), 100.0f * (cos(time * 3.0f) + 1.0f)
		);
	FindGameObject(0).SetTransform(m_transform1);

	/*Transform2D m_transform2;
	m_transform2 = FindGameObject(2).GetTransform();
	m_transform2.scale =
		Vector2
		(
			1.5f * (cos(time * 2.0f) + 1.0f), 1.5f * (cos(time * 2.0f) + 1.0f)
		);
	FindGameObject(2).SetTransform(m_transform2);*/	

	//=====
	//m_ps1->update();
	//=====

	m_particleSystem0->Update(deltaTime);

	m_particleSystem1->Update(deltaTime);

	m_particleSystem2->Update(deltaTime);
}

void Application::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//=====
	//m_ps1->draw();
	//=====

	// draw function
	iteGO = m_GOs.GetList().begin();
	while (iteGO != m_GOs.GetList().end())
	{
		GameObject GO = **iteGO;
		GO.Draw();
		++iteGO;
	}

	m_particleSystem0->Draw();

	m_particleSystem1->Draw();

	m_particleSystem2->Draw();
}
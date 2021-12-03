
#pragma once

#include "TemplateList.h"

template <class T>
class ParticleObjectContainer
{
private:
	std::list<T*> m_list;

public:
	ParticleObjectContainer()
	{
	}

	~ParticleObjectContainer()
	{
		std::list<ParticleObject*>::iterator ite = m_list.begin();

		while (ite != m_list.end())
		{
			delete *ite;
			++ite;
		}
		m_list.clear();
	}

	std::list<T*>& GetList()
	{
		return m_list;
	}

	T& GetItem(unsigned int index)
	{
		return TemplateList::Get(GetList(), index);
	}
};
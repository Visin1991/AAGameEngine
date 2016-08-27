#include "Component.h"
#include "Debug.h"

namespace AAEngine
{
	/*-------------------------------------------------------------
		this is a static classInfoMap, which contain:

			string: the ComponentType

			ClassInfo*: string--->the ComponentType
						ptr---> the pointer of a function which return a new ComponentX;
	---------------------------------------------------------------*/

	std::map<std::string, ClassInfo*> Component::m_classInfoMap = std::map<std::string, ClassInfo*>();

	bool RegisterClass(ClassInfo* classinfo)
	{ 
		return Component::RegisterClass(classinfo);
	}

	Component::Component(void)
	{
	}

	bool Component::RegisterClass(ClassInfo* classinfo)
	{
		m_classInfoMap[classinfo->m_Type] = classinfo;
		return true;
	}

	Component* Component::CreateInstance(std::string type,GameObject3D* obj)
	{
		if (m_classInfoMap[type] != NULL)
		{
			return m_classInfoMap[type]->m_Func(obj);
		}
		else
		{
			Debug::LogError("Component Type does not exsit!");
		}
		return NULL;
	}

	Component::~Component(void)
	{
	}
}


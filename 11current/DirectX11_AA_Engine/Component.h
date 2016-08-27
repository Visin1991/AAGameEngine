#pragma once

#include <map>
#include <string>
#include <vector>

namespace AAEngine {

	class Component;
	struct ClassInfo;
	class GameObject3D;


	bool RegisterClass(ClassInfo* classinfo);
	typedef Component* (*funCreateInstance)(GameObject3D* obj);


	//¿‡–≈œ¢;
	struct  ClassInfo
	{
		std::string m_Type;
		funCreateInstance m_Func;


		ClassInfo(std::string type, funCreateInstance func)
		{
			m_Type = type;
			m_Func = func;
			RegisterClass(this);
		}
	};



	class Component
	{
	public:
		Component(void);
		virtual ~Component(void);

		static bool RegisterClass(ClassInfo* classinfo);

		static Component* CreateInstance(std::string type,GameObject3D* obj);

	private:
		static std::map<std::string, ClassInfo*> m_classInfoMap;
	};
}
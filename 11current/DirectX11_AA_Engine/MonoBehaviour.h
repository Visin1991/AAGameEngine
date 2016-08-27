#pragma  once

#include "Component.h"
#include"GameObject3D.h"
#include <vector>
namespace AAEngine
{
#define DECLEAR_DYNCRT_ACTION(TypeName) \
public: \
	TypeName::TypeName(GameObject3D* obj){Awake();TypeName::m_obj = obj;}\
	static TypeName* CreateInstance(GameObject3D* obj) \
	{ \
		return new TypeName(obj); \
	} \
private: \
	static ClassInfo* m_classInfo; \


#define IMPLEMENT_DYNCRT_ACTION(TypeName) \
	ClassInfo* TypeName::m_classInfo= new ClassInfo(#TypeName,(funCreateInstance)TypeName::CreateInstance); \
	
	/*
		ClassInfo(){
					RegisterClass(this){
									  Component::RegisterClass(ClassInfo){
																	   	m_classInfoMap[classinfo->m_Type] = classinfo;
																		}
									   } 
				   }
	*/
	 //Overview::  every time we create a new component, we create a " map<ComponentName,StaticFunctionPointerReturnTheComponent>"
	//            and trace back to class component, Rehister it.
	//-----------------------------------------------------------------------

	class MonoBehaviour :Component
	{
		DECLEAR_DYNCRT_ACTION(MonoBehaviour)

	public:
		GameObject3D* m_obj;
	public:
		MonoBehaviour();
		virtual ~MonoBehaviour();

		virtual void Awake();

		virtual void OnEnable();

		virtual void Start();

		virtual void Update();

		virtual void OnDisable();

		virtual void OnDestroy();
	};
}

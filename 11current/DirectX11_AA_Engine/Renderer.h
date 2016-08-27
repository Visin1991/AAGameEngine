#pragma once

#include"ComponentBaseHeader.h"
#include"Bounds.h"
#include"Material.h"



namespace AAEngine {
	
	class GameObject3D;
	class Mesh;

	class Renderer : public MonoBehaviour
	{
		DECLEAR_DYNCRT_ACTION(Renderer)
	public:
		Renderer();

		~Renderer();

		virtual void Awake();

		//Variable
		Mesh* mesh;
		
		std::string sharedMesh;

		Bounds* bounds; // should it be create in stack or heap?
		
		bool enabled;

		bool isPartOfStaticBatch; //Has this renderer been statically batched with any other renderers?

		bool isVisible; //is this renderer visible in any camera ? (Read Only)

		int lightmapIndex; //The index of the baked lightmap applied to this renderer.

		Vector4 lightmapScaleOffet;

		GameObject3D* lightProbeProxyVolumeOverride; //If set, the Renderer will use the Light Probe Proxy Volume component attached to the source game object.

		Material* material;

		int sortingLayerID; //Unique ID of the Renderer's sorting layer.

	};
}


/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#include "..\stdafx.h"

using namespace std;

#pragma once

namespace Utils
{

	class Composite : public Interface::IObject
	{
	public:
		void Initialize(IO::MeshLoader* _meshLoader) override;

		void SetSelfObject(Interface::IObject* _object);

		void Destroy() override;

		void Update() override;

		void SetColor(float _r, float _g, float _b) override;

		void Render(Interface::IShader& _shader) override;

		void Translate(float _x, float _y, float _z) override;

		void Rotate(float _angleX, float _angleY, float _angleZ) override;

		void Scale(float _scaleX, float _scaleY, float _scaleZ) override;

		void Add(Interface::IObject* _object);

	private:
		vector<Interface::IObject*> childObjects;
		Interface::IObject * planet;
	};

}
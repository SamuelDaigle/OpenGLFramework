/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "..\stdafx.h"
#include "..\Utils\VertexType.h"

namespace Rendering
{

	class Square : public Framework::BaseObject
	{
	public:
		Square(IO::MeshLoader* _meshLoader, IShader& _shader);
		~Square();

		void Destroy() override;

		void Render() override;
		void Translate(float _x, float _y, float _z) override;
		void Rotate(float _angleX, float _angleY, float _angleZ) override;
		void Scale(float _scaleX, float _scaleY, float _scaleZ) override;

	private:
		void initializeBuffers();
		void shutdownBuffers();
	};

}
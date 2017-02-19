/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma  once

#include "..\Math\Matrix4.h"

class ICamera
{
public:
	virtual const Math::Vector3& GetPosition() const = 0;
	virtual const Math::Matrix4 GetViewMatrix() const = 0;
	virtual const Math::Matrix4& GetProjectionMatrix() const = 0;
	virtual const Math::Matrix4& GetRotation() const = 0;
};

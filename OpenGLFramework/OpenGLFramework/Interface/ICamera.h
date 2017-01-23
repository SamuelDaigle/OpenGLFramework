/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma  once

#include "..\Math\Matrix4.h"

class ICamera
{
public:
	virtual Math::Vector3& GetPosition() = 0;
	virtual Math::Matrix4 GetViewMatrix() = 0;
	virtual Math::Matrix4& GetProjectionMatrix() = 0;
	virtual Math::Matrix4& GetRotation() = 0;
};

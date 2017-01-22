/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "Dependencies\glew\glew.h"
#include "Dependencies\glew\wglew.h"
#include "Dependencies\freeglut\freeglut.h"
#pragma comment(lib, "glew32.lib")

#include "Math\Vector3.h"
#include <vector>
#include "Utils\Color.h"
#include "Utils\DynamicArray.h"
#include "Framework\BaseObject.h"
#include "Framework\OpenGL.h"

using namespace glm;

#define SAFE_DESTROY(ptr) { ptr->Destroy(); delete ptr; ptr = NULL; }
/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#include "Dependencies\glew\glew.h"
#include "Dependencies\glew\wglew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies\glm\glm.hpp"
#pragma comment(lib, "glew32.lib")

#include <vector>
#include "Utils/Color.h"
#include "Utils/DynamicArray.h"
#include "Interfaces\IObject.h"
#include "Framework\OpenGL.h"

using namespace glm;

#define SAFE_DESTROY(ptr) { ptr->Destroy(); delete ptr; ptr = NULL; }
/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#define SAFE_DESTROY(ptr) { ptr->Destroy(); delete ptr; ptr = NULL; }
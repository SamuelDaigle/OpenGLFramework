/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#pragma once

#define SAFE_DESTROY(ptr) { ptr->Destroy(); delete ptr; ptr = NULL; }
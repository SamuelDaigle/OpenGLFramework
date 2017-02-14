/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#define SAFE_DESTROY(ptr) { ptr->Destroy(); delete ptr; ptr = NULL; }
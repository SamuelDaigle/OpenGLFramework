/************************************************************************/
/* Author: Samuel Daigle et S�bastien Rousseau                          */
/************************************************************************/

#define SAFE_DESTROY(ptr) { ptr->Destroy(); delete ptr; ptr = NULL; }
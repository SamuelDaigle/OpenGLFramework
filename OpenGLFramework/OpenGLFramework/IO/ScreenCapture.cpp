#include "ScreenCapture.h"
#include <vector>

namespace IO {
	void ScreenCapture::Capture()
	{
		int w = (float)glutGet(GLUT_SCREEN_WIDTH);
		int h = (float)glutGet(GLUT_SCREEN_HEIGHT); 
		std::vector<unsigned char> buf(w * h * 3);
		glPixelStorei(GL_PACK_ALIGNMENT, 1);
		glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, &buf[0]);

		int frameSave = SOIL_save_image("img3d.bmp", SOIL_SAVE_TYPE_BMP, w, h, 3, &buf[0]);
	}
}
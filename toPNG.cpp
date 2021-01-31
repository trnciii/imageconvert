#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

int main(int argc, char *argv[]){
	std::string filename(argv[1]);

	int x,y,n;
	unsigned char *data = stbi_load(filename.data(), &x, &y, &n, 3);

	filename.replace(filename.size()-3, 3, "png");
	stbi_write_png(filename.data(), x, y, 3, data, 3*x);
	
	stbi_image_free(data);
	return 0;
}
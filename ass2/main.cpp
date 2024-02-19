#include "CFunction.h"
#include "BaseObject.h"

BaseObject g_background;


// SDL_Surface *LoadImage(SDL_Window *window, std::string file_path){
//     SDL_Surface *load_Image = nullptr;
//     SDL_Surface *optimize_image = NULL;

//     load_Image = IMG_Load(file_path.c_str());
//     if (load_Image != NULL){
//         optimize_image = SDL_ConvertSurfaceFormat(load_Image, SDL_GetWindowPixelFormat(window), 0);
//         SDL_FreeSurface(load_Image);
//     }

//     return optimize_image;
// }

bool initData(){
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if(ret < 0){
		return false;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	g_window = SDL_CreateWindow("Game Cpp SDL2.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(g_window == NULL){
		success = false;
	}
	else{
		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if(g_screen == NULL){
			success = false;
		}
		else{
			SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
			int imgFlags = IMG_INIT_PNG;
			if(!(IMG_Init(imgFlags) && imgFlags)){
				success = false;
			}
		}
	}
	return success;
}


bool LoadBackground(){
	bool ret = g_background.loadImg("image/1.png", g_screen);
	if(ret ==false){
		return false;
	}
	return true;
}

void close(){
	g_background.Free();
	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;
	SDL_DestroyWindow(g_window);
	g_window = NULL;


	IMG_Quit();
	SDL_Quit();
}


int main(int argc, char* argv[]){
	if (initData() == false){
		return -1;
	}
	if(LoadBackground() == false){
		return -1;
	}

	bool isquit = false;
	while(!isquit){
		while(SDL_PollEvent(&g_event) != 0){
			if(g_event.type == SDL_QUIT){
				isquit = true;
			}
		}
		SDL_SetRenderDrawColor(g_screen,255,255,255,255);
		SDL_RenderClear(g_screen);
		g_background.Render(g_screen, NULL);
		SDL_RenderPresent(g_screen);
	}

	close();

	return 0;
}












// int main(int argc, char *argv[])
// {

	// // returns zero on success else non-zero
	// if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	// 	printf("error initializing SDL: %s\n", SDL_GetError());
	// }
	// SDL_Window* win = SDL_CreateWindow("GAME", // creates a window
	// 								SDL_WINDOWPOS_CENTERED,
	// 								SDL_WINDOWPOS_CENTERED,
	// 								1000, 1000, 0);

	// // triggers the program that controls
	// // your graphics hardware and sets flags
	// Uint32 render_flags = SDL_RENDERER_ACCELERATED;

	// // creates a renderer to render our images
	// SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

	// // creates a surface to load an image into the main memory
	// SDL_Surface* surface;

	// // please provide a path for your image
	// surface = IMG_Load("image/white.png");

	// // loads image to our graphics hardware memory.
	// SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);

	// // clears main-memory
	// // SDL_FreeSurface(surface);

    // SDL_Surface* img = NULL;

    // img = LoadImage(win, "image/white.png");
    // SDL_RenderCopy(img, NULL, win, NULL);

	// // let us control our image position
	// // so that we can move it with our keyboard.
	// SDL_Rect dest;

	// // connects our texture with dest to control position
	// SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

	// // adjust height and width of our image box.
	// dest.w /= 50;
	// dest.h /= 50;

	// // sets initial x-position of object
	// dest.x = (1000 - dest.w) / 2;

	// // sets initial y-position of object
	// dest.y = (1000 - dest.h) / 2 + 100;

	// // controls animation loop
	// int close = 0;

	// // speed of box
	// int speed = 300;

	// // animation loop
	// while (!close) {
	// 	SDL_Event event;

	// 	// Events management
	// 	while (SDL_PollEvent(&event)) {
	// 		switch (event.type) {

	// 		case SDL_QUIT:
	// 			// handling of close button
	// 			close = 1;
	// 			break;

	// 		case SDL_KEYDOWN:
	// 			// keyboard API for key pressed
	// 			switch (event.key.keysym.scancode) {
	// 			case SDL_SCANCODE_W:
	// 			case SDL_SCANCODE_UP:
	// 				dest.y -= speed/10;
	// 				break;
	// 			case SDL_SCANCODE_A:
	// 			case SDL_SCANCODE_LEFT:
	// 				dest.x -= speed/10;
	// 				break;
	// 			case SDL_SCANCODE_S:
	// 			case SDL_SCANCODE_DOWN:
	// 				dest.y += speed/10;
	// 				break;
	// 			case SDL_SCANCODE_D:
	// 			case SDL_SCANCODE_RIGHT:
	// 				dest.x += speed/10;
	// 				break;
	// 			default:
	// 				break;
	// 			}
	// 		}
	// 	}

	// 	// right boundary
	// 	if (dest.x + dest.w > 1000)
	// 		dest.x = 1000 - dest.w;

	// 	// left boundary
	// 	if (dest.x < 0)
	// 		dest.x = 0;

	// 	// bottom boundary
	// 	if (dest.y + dest.h > 1000)
	// 		dest.y = 1000 - dest.h;

	// 	// upper boundary
	// 	if (dest.y < 0)
	// 		dest.y = 0;

	// 	// clears the screen
	// 	SDL_RenderClear(rend);
	// 	SDL_RenderCopy(rend, tex, NULL, &dest);

	// 	// triggers the double buffers
	// 	// for multiple rendering
	// 	SDL_RenderPresent(rend);

	// 	// calculates to 60 fps
	// 	SDL_Delay(1000 / 60);
	// }

	// // destroy texture
	// SDL_DestroyTexture(tex);

	// // destroy renderer
	// SDL_DestroyRenderer(rend);

	// // destroy window
	// SDL_DestroyWindow(win);
	
	// // close SDL
	// SDL_Quit();

	// return 0;
// }


// void logSDLError(std::ostream &os, const std::string &msg){
// 	os << msg << " error: " << SDL_GetError() << std::endl;
// }

// SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
// 	//Initialize to nullptr to avoid dangling pointer issues
// 	SDL_Texture *texture = nullptr;
// 	//Load the image
// 	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
// 	//If the loading went ok, convert to texture and return the texture
// 	if (loadedImage != nullptr){
// 		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
// 		SDL_FreeSurface(loadedImage);
// 		//Make sure converting went ok too
// 		if (texture == nullptr){
// 			logSDLError(std::cout, "CreateTextureFromSurface");
// 		}
// 	}
// 	else {
// 		logSDLError(std::cout, "LoadBMP");
// 	}
// 	return texture;
// }



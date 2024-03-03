
// // #include "CFunction.h"
// // #include "BaseObject.h"
// #include "CFunction.h"
// #include "BaseObject.h"

// // BaseObject g_background;

// #include<stdio.h>
// #include <stdlib.h>
// #include <iostream>
// #include <windows.h>
// #include<string>
// #include<string.h>
// #include<C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2\SDL.h>
// #include<C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2\SDL_image.h>
// #include<C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2\SDL_timer.h>
// #include<C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2\SDL_mixer.h>
// #include<C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2\SDL_ttf.h>
// BaseObject g_background;


// SDL_Surface *LoadImage(SDL_Window *window, std::string file_path){

//     return optimize_image;
// }

// bool initData(){
// 	bool success = true;
// 	int ret = SDL_Init(SDL_INIT_VIDEO);
// 	if(ret < 0){
// 		return false;
// 	}
// bool initData(){
// 	bool success = true;
// 	int ret = SDL_Init(SDL_INIT_VIDEO);
// 	if(ret < 0){
// 		return false;
// 	}

// // 	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
// // 	g_window = SDL_CreateWindow("Game Cpp SDL2.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
// // 	if(g_window == NULL){
// // 		success = false;
// // 	}
// // 	else{
// // 		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
// // 		if(g_screen == NULL){
// // 			success = false;
// // 		}
// // 		else{
// // 			SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
// // 			int imgFlags = IMG_INIT_PNG;
// // 			if(!(IMG_Init(imgFlags) && imgFlags)){
// // 				success = false;
// // 			}
// // 		}
// // 	}
// // 	return success;
// // }


// bool LoadBackground(){
// 	bool ret = g_background.loadImg("image/1.png", g_screen);
// 	if(ret ==false){
// 		return false;
// 	}
// 	return true;
// }
// 	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
// 	g_window = SDL_CreateWindow("Game Cpp SDL2.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
// 	if(g_window == NULL){
// 		success = false;
// 	}
// 	else{
// 		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
// 		if(g_screen == NULL){
// 			success = false;
// 		}
// 		else{
// 			SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
// 			int imgFlags = IMG_INIT_PNG;
// 			if(!(IMG_Init(imgFlags) && imgFlags)){
// 				success = false;
// 			}
// 		}
// 	}
// 	return success;
// }

// void close(){
// 	g_background.Free();
// 	SDL_DestroyRenderer(g_screen);
// 	g_screen = NULL;
// 	SDL_DestroyWindow(g_window);
// 	g_window = NULL;

// bool LoadBackground(){
// 	bool ret = g_background.loadImg("image/1.png", g_screen);
// 	if(ret ==false){
// 		return false;
// 	}
// 	return true;
// }

// // 	IMG_Quit();
// // 	SDL_Quit();
// // }
// void close(){
// 	g_background.Free();
// 	SDL_DestroyRenderer(g_screen);
// 	g_screen = NULL;
// 	SDL_DestroyWindow(g_window);
// 	g_window = NULL;


// // int main(int argc, char* argv[]){
// // 	if (initData() == false){
// // 		return -1;
// // 	}
// // 	if(LoadBackground() == false){
// // 		return -1;
// // 	}
// 	IMG_Quit();
// 	SDL_Quit();
// }

// 	bool isquit = false;
// 	while(!isquit){
// 		while(SDL_PollEvent(&g_event) != 0){
// 			if(g_event.type == SDL_QUIT){
// 				isquit = true;
// 			}
// 		}
// 		SDL_SetRenderDrawColor(g_screen,255,255,255,255);
// 		SDL_RenderClear(g_screen);
// 		g_background.Render(g_screen, NULL);
// 		SDL_RenderPresent(g_screen);
// 	}

// 	close();
// int main(int argc, char* argv[]){
// 	if (initData() == false){
// 		return -1;
// 	}
// 	if(LoadBackground() == false){
// 		return -1;
// 	}

// // 	return 0;
// // }
// 	bool isquit = false;
// 	while(!isquit){
// 		while(SDL_PollEvent(&g_event) != 0){
// 			if(g_event.type == SDL_QUIT){
// 				isquit = true;
// 			}
// 		}
// 		SDL_SetRenderDrawColor(g_screen,255,255,255,255);
// 		SDL_RenderClear(g_screen);
// 		g_background.Render(g_screen, NULL);
// 		SDL_RenderPresent(g_screen);
// 	}

// 	close();

// 	return 0;
// }






// // void logSDLError(std::ostream &os, const std::string &msg){
// // 	os << msg << " error: " << SDL_GetError() << std::endl;
// // }
// int main(int argc, char *argv[])
// {

// // SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
// // 	//Initialize to nullptr to avoid dangling pointer issues
// // 	SDL_Texture *texture = nullptr;
// // 	//Load the image
// // 	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
// // 	//If the loading went ok, convert to texture and return the texture
// // 	if (loadedImage != nullptr){
// // 		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
// // 		SDL_FreeSurface(loadedImage);
// // 		//Make sure converting went ok too
// // 		if (texture == nullptr){
// // 			logSDLError(std::cout, "CreateTextureFromSurface");
// // 		}
// // 	}
// // 	else {
// // 		logSDLError(std::cout, "LoadBMP");
// // 	}
// // 	return texture;
// // }
	// // returns zero on success else non-zero
	// if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	// 	printf("error initializing SDL: %s\n", SDL_GetError());
	// }
	// SDL_Window* win = SDL_CreateWindow("GAME", // creates a window
	// 								SDL_WINDOWPOS_CENTERED,
	// 								SDL_WINDOWPOS_CENTERED,
	// 								1000, 1000, 0);

#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include<string>
#include<string.h>
#include <C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2\SDL.h>
#include <C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2\SDL_image.h>
#include <C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2/SDL_timer.h>
 
	// // triggers the program that controls
	// // your graphics hardware and sets flags
	// Uint32 render_flags = SDL_RENDERER_ACCELERATED;

class GameObject{
public:
	GameObject();
	~GameObject();
	void SetRect(const int& x, const int& y){
        rect_.x = x;
        rect_.y = y;
    }
    SDL_Rect GetRect() const { return rect_; }
    SDL_Texture* GetObject() const { return p_object_; }
	// // creates a renderer to render our images
	// SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

    bool loadImg(std::string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Free();
protected:;
    SDL_Texture* p_object_;
    SDL_Rect rect_;
	// // creates a surface to load an image into the main memory
	// SDL_Surface* surface;

	// // please provide a path for your image
	// surface = IMG_Load("image/white.png");

};
	// // loads image to our graphics hardware memory.
	// SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);

	// // clears main-memory
	// // SDL_FreeSurface(surface);

int main(int argc, char *argv[])
{
    // SDL_Surface* img = NULL;

	// returns zero on success else non-zero
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("error initializing SDL: %s\n", SDL_GetError());
	}
	SDL_Window* win = SDL_CreateWindow("GAME", // creates a window
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									1800, 1000, 0);
    // img = LoadImage(win, "image/white.png");
    // SDL_RenderCopy(img, NULL, win, NULL);

	// triggers the program that controls
	// your graphics hardware and sets flags
	Uint32 render_flags = SDL_RENDERER_ACCELERATED;
	// // let us control our image position
	// // so that we can move it with our keyboard.
	// SDL_Rect dest;

	// creates a renderer to render our images
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
	// // connects our texture with dest to control position
	// SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

	// creates a surface to load an image into the main memory
	SDL_Surface* player1;
	SDL_Surface* image;
	SDL_Surface* player2;
	// // adjust height and width of our image box.
	// dest.w /= 50;
	// dest.h /= 50;

	// please provide a path for your image
	player1 = IMG_Load("image/circle.png");
	player2 = IMG_Load("image/white.png");
	image = IMG_Load("image/background.jpg");
	// // sets initial x-position of object
	// dest.x = (1000 - dest.w) / 2;

	// loads image to our graphics hardware memory.
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, player1);
	SDL_Texture* text = SDL_CreateTextureFromSurface(rend, player2);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, image);
	// // sets initial y-position of object
	// dest.y = (1000 - dest.h) / 2 + 100;

	SDL_Surface* ball_img = SDL_CreateRGBSurface(0, 20, 20, 32, 0, 0, 0, 0);
    SDL_FillRect(ball_img, NULL, SDL_MapRGB(ball_img->format, 255, 255, 255));
	// // controls animation loop
	// int close = 0;

	SDL_Rect ball;
	ball.x = 0;
	ball.y = 0;
	ball.w = 100;
	ball.h = 100;
	// clears main-memory
	// SDL_FreeSurface(surface);
	// // speed of box
	// int speed = 300;

	// let us control our image position
	// so that we can move it with our keyboard.
	// // animation loop
	// while (!close) {
	// 	SDL_Event event;

	// 	// Events management
	// 	while (SDL_PollEvent(&event)) {
	// 		switch (event.type) {

    // clears main-memory
    SDL_FreeSurface(player1);
    SDL_FreeSurface(player2);
    SDL_FreeSurface(image);
    SDL_FreeSurface(ball_img);
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
	
	SDL_Rect background;
	background.x = 0; // Vị trí ban đầu theo trục x
	background.y = 0; // Vị trí ban đầu theo trục y
	background.w = 1800; // Chiều rộng
	background.h = 1000; // Chiều cao


	// SDL_RenderClear(rend);
	// SDL_RenderCopy(rend, texture, NULL, &background);
	// // close SDL
	// SDL_Quit();

	// triggers the double buffers
	// for multiple rendering
	// SDL_RenderPresent(rend);

	SDL_Rect p2;
	// connects our texture with dest to control position
	SDL_QueryTexture(text, NULL, NULL, &p2.w, &p2.h);

	// adjust height and width of our image box.
	p2.w /= 200;
	p2.h /= 200;

	// sets initial x-position of object
	p2.x = (1800 - p2.w) / 2 + 300;

	// sets initial y-position of object
	p2.y = (1000 - p2.h) / 2;


	SDL_Rect p1;
	// connects our texture with dest to control position
	SDL_QueryTexture(tex, NULL, NULL, &p1.w, &p1.h);

	// adjust height and width of our image box.
	p1.w /= 50;
	p1.h /= 50;

	// sets initial x-position of object
	p1.x = (1800 - p1.w) / 2 - 300;

	// sets initial y-position of object
	p1.y = (1000 - p1.h) / 2;

	// controls animation loop
	int close = 0;

	// speed of box
	int speed = 300;

	// animation loop
	while (!close) {
		SDL_Event event;

		// Events management
		while (SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				close = 1;
			}
			else if(event.type == SDL_KEYDOWN){
				if(event.key.keysym.sym == SDLK_ESCAPE){
					close = 1;
				}
				else if(event.key.keysym.sym == SDLK_w){
					p1.y -= speed/10;
				}
				else if(event.key.keysym.sym == SDLK_UP){
					p2.y -= speed/10;
				}
				else if(event.key.keysym.sym == SDLK_a){
					p1.x -= speed/10;
				}
				else if(event.key.keysym.sym == SDLK_LEFT){
					p2.x -= speed/10;
				}
				else if(event.key.keysym.sym == SDLK_s){
					p1.y += speed/10;
				}
				else if(event.key.keysym.sym == SDLK_DOWN){
					p2.y += speed/10;
				}
				else if(event.key.keysym.sym == SDLK_d){
					p1.x += speed/10;
				}
				else if(event.key.keysym.sym == SDLK_RIGHT){
					p2.x += speed/10;
				}
			}
			else if(event.type == SDL_KEYUP){
				if(event.key.keysym.sym == SDLK_ESCAPE){
					close = 1;
				}
				else if(event.key.keysym.sym == SDLK_w){
					p1.y -= speed/10;
				}
				else if(event.key.keysym.sym == SDLK_UP){
					p2.y -= speed/10;
				}
				else if(event.key.keysym.sym == SDLK_a){
					p1.x -= speed/10;
				}
				else if(event.key.keysym.sym == SDLK_LEFT){
					p2.x -= speed/10;
				}
				else if(event.key.keysym.sym == SDLK_s){
					p1.y += speed/10;
				}
				else if(event.key.keysym.sym == SDLK_DOWN){
					p2.y += speed/10;
				}
				else if(event.key.keysym.sym == SDLK_d){
					p1.x += speed/10;
				}
				else if(event.key.keysym.sym == SDLK_RIGHT){
					p2.x += speed/10;
				}
			}
			// switch (event.type) {

			// case SDL_QUIT:
			// 	// handling of close button
			// 	close = 1;
			// 	break;

			// case SDL_KEYDOWN:
			// 	// keyboard API for key pressed
			// 	switch (event.key.keysym.scancode) {
			// 	case SDL_SCANCODE_W:
			// 		p1.y -= speed/10;
			// 		break;
			// 	case SDL_SCANCODE_UP:
			// 		p2.y -= speed/10;
			// 		break;
			// 	case SDL_SCANCODE_A:
			// 		p1.x -= speed/10;
			// 		break;
			// 	case SDL_SCANCODE_LEFT:
			// 		p2.x -= speed/10;
			// 		break;
			// 	case SDL_SCANCODE_S:
			// 		p1.y += speed/10;
			// 		break;
			// 	case SDL_SCANCODE_DOWN:
			// 		p2.y += speed/10;
			// 		break;
			// 	case SDL_SCANCODE_D:
			// 		p1.x += speed/10;
			// 		break;
			// 	case SDL_SCANCODE_RIGHT:
			// 		p2.x += speed/10;
			// 		break;
			// 	default:
			// 		break;
			// 	}
			// }
		}
	// return 0;
// }

		// right boundary
		if (p1.x + p1.w > 1800)
			p1.x = 1800 - p1.w;

		// left boundary
		if (p1.x < 0)
			p1.x = 0;

		// bottom boundary
		if (p1.y + p1.h > 1000)
			p1.y = 1000 - p1.h;

		// upper boundary
		if (p1.y < 0)
			p1.y = 0;

		// right boundary
		if (p2.x + p2.w > 1800)
			p2.x = 1800 - p2.w;

		// left boundary
		if (p2.x < 0)
			p2.x = 0;

		// bottom boundary
		if (p2.y + p2.h > 1000)
			p2.y = 1000 - p2.h;

		// upper boundary
		if (p2.y < 0)
			p2.y = 0;
		// clears the screen
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend, texture, NULL, &background);
		SDL_RenderCopy(rend, tex, NULL, &p1);
		SDL_RenderCopy(rend, text, NULL, &p2);
        // SDL_BlitSurface(ball_img, NULL, rend, &ball);
		// triggers the double buffers
		// for multiple rendering
		SDL_RenderPresent(rend);

		// calculates to 60 fps
		SDL_Delay(1800 / 240);
	}

	// destroy texture
	SDL_DestroyTexture(tex);
	SDL_DestroyTexture(texture);
// void logSDLError(std::ostream &os, const std::string &msg){
// 	os << msg << " error: " << SDL_GetError() << std::endl;
// }

	// destroy renderer
	SDL_DestroyRenderer(rend);
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

	// destroy window
	SDL_DestroyWindow(win);
	
	// close SDL
	SDL_Quit();

	return 0;
}
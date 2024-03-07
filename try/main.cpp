#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include<string>
#include<string.h>
#include <chrono>
#include <C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2\SDL.h>
#include <C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2\SDL_image.h>
#include <C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2/SDL_timer.h>
#include <C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2/SDL_ttf.h>

using namespace std;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const float PLAYER_SPEED = 0.5f;
const int PLAYER_WIDTH = 20;
const int PLAYER_HEIGHT = 20;
const float BALL_SPEED = 0.01f;
const int BALL_WIDTH = 15;
const int BALL_HEIGHT = 15;

enum Buttons
{
	PlayerOneUp = 0,
	PlayerOneDown,
	PlayerOneLeft,
	PlayerOneRight,
	PlayerTwoUp,
	PlayerTwoDown,
	PlayerTwoLeft,
	PlayerTwoRight,

};

enum class CollisionType
{
	None,
	Top,
	Middle,
	Bottom,
	Left,
	Right
};

struct Contact
{
	CollisionType type;
	float penetration;
};

class Vec2
{
public:
	Vec2()
		: x(0.0f), y(0.0f)
	{}

	Vec2(float x, float y)
		: x(x), y(y)
	{}

	Vec2 operator+(Vec2 const& rhs)
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}

	Vec2& operator+=(Vec2 const& rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	Vec2 operator*(float rhs)
	{
		return Vec2(x * rhs, y * rhs);
	}

	float x, y;
};

class Player
{
public:
	Player(Vec2 position, Vec2 velocity)
		: position(position), velocity(velocity)
	{
		rect.x = static_cast<int>(position.x);
		rect.y = static_cast<int>(position.y);
		rect.w = PLAYER_WIDTH;
		rect.h = PLAYER_HEIGHT;
	}

	void Update(float dt)
	{
		position += velocity * dt;

		if (position.y < 0)
		{
			// Restrict to top of the screen
			position.y = 0;
		}
		else if (position.y > (WINDOW_HEIGHT - PLAYER_HEIGHT))
		{
			// Restrict to bottom of the screen
			position.y = WINDOW_HEIGHT - PLAYER_HEIGHT;
		}

		if (position.x < 0)
		{
			// Restrict to top of the screen
			position.x = 0;
		}
		else if (position.x > (WINDOW_WIDTH - PLAYER_WIDTH))
		{
			// Restrict to bottom of the screen
			position.x = WINDOW_WIDTH - PLAYER_WIDTH;
		}
	}

	void Draw(SDL_Renderer* renderer)
	{
		rect.y = static_cast<int>(position.y);
		rect.x = static_cast<int>(position.x);

		SDL_RenderFillRect(renderer, &rect);
	}

	Vec2 position;
	Vec2 velocity;
	SDL_Rect rect{};
};



class Ball
{
public:
	Ball(Vec2 position, Vec2 velocity)
		: position(position), velocity(velocity)
	{
		rect.x = static_cast<int>(position.x);
		rect.y = static_cast<int>(position.y);
		rect.w = BALL_WIDTH;
		rect.h = BALL_HEIGHT;
	}

	void Update(float dt)
	{
		position += velocity * dt;
	}

	void Draw(SDL_Renderer* renderer)
	{
		rect.x = static_cast<int>(position.x);
		rect.y = static_cast<int>(position.y);

		SDL_RenderFillRect(renderer, &rect);
	}

	void CollideWithPlayer(Contact const& contact, Player const& player)
	{
		if (contact.type == CollisionType::Top)
		{
			velocity.y = 0.0f;
			float ballCenterY = rect.y + rect.w / 2;
			float playerCenterY = player.rect.y + player.rect.h * 4;
			
			float penetrationY = ballCenterY - playerCenterY;
			
			// Thay đổi tốc độ của quả bóng dựa trên hướng va chạm
			velocity.y += penetrationY * 0.024f;
		}
		else if (contact.type == CollisionType::Bottom)
		{
			velocity.y = 0.0f;
			float ballCenterY = rect.y + rect.w / 2;
			float playerCenterY = player.rect.y + player.rect.h * 4;
			
			float penetrationY = ballCenterY + playerCenterY;
			
			// Thay đổi tốc độ của quả bóng dựa trên hướng va chạm
			velocity.y = velocity.y + penetrationY * 0.003f;
		}
		// else if (contact.type == CollisionType::Right)
		// {
			
		// 	velocity.x = -BALL_SPEED;
		// 	float ballCenterX = rect.x + rect.w / 2;
		// 	float playerCenterX = player.rect.x + player.rect.h * 4;
			
		// 	float penetrationX = ballCenterX - playerCenterX;
			
		// 	//Thay đổi tốc độ của quả bóng dựa trên hướng va chạm
		// 	velocity.x += penetrationX * 0.01f; // Tăng tốc độ theo hướng x
		// }
		// else if (contact.type == CollisionType::Left)
		// {
			
		// 	velocity.x = -BALL_SPEED;
		// 	float ballCenterX = rect.x + rect.w / 2;
		// 	float playerCenterX = player.rect.x + player.rect.h * 4;
			
		// 	float penetrationX = ballCenterX - playerCenterX;
			
		// 	//Thay đổi tốc độ của quả bóng dựa trên hướng va chạm
		// 	velocity.x += penetrationX * 0.01f; // Tăng tốc độ theo hướng x
		// }
		{
			// Xử lý va chạm giữa người chơi và quả bóng
			// Tính toán hướng và mức độ va chạm
			// float ballCenterX = rect.x + rect.w / 2;
			// float playerCenterX = player.rect.x + player.rect.h * 4;
			
			// float penetrationX = ballCenterX - playerCenterX;
			
			// // Thay đổi tốc độ của quả bóng dựa trên hướng va chạm
			// velocity.x += penetrationX * 0.01f; // Tăng tốc độ theo hướng x
			

			// float ballCenterY = rect.y + rect.w / 2;
			// float playerCenterY = player.rect.y + player.rect.h * 4;
			
			// float penetrationY = ballCenterY - playerCenterY;
			
			// // Thay đổi tốc độ của quả bóng dựa trên hướng va chạm
			// velocity.y += penetrationY * 0.01f; // Tăng tốc độ theo hướng x
			
			// Có thể thay đổi hướng di chuyển của quả bóng tùy theo hướng va chạm
			// Ví dụ: nếu va chạm từ phía trên hoặc dưới, thay đổi hướng di chuyển theo y
		}
	}

	void CollideWithWall(Contact const& contact)
	{
		if ((contact.type == CollisionType::Top)
		    || (contact.type == CollisionType::Bottom))
		{
			position.y += contact.penetration;
			velocity.y = -velocity.y;
		}
		else if (contact.type == CollisionType::Left)
		{
			position.x = WINDOW_WIDTH / 2.0f;
			position.y = WINDOW_HEIGHT / 2.0f;
			velocity.x = BALL_SPEED;
			velocity.y = 0.75f * BALL_SPEED;
		}
		else if (contact.type == CollisionType::Right)
		{
			position.x = WINDOW_WIDTH / 2.0f;
			position.y = WINDOW_HEIGHT / 2.0f;
			velocity.x = -BALL_SPEED;
			velocity.y = 0.75f * BALL_SPEED;
		}
		
		if(position.x == WINDOW_WIDTH / 2.0f && position.y == WINDOW_HEIGHT / 2.0f){
			velocity.x = 0;
			velocity.y = 0;
		}
	}

	Vec2 position;
	Vec2 velocity;
	SDL_Rect rect{};
};

class PlayerScore
{
public:
	PlayerScore(Vec2 position, SDL_Renderer* renderer, TTF_Font* font)
		: renderer(renderer), font(font)
	{
		surface = TTF_RenderText_Solid(font, "0", {0xFF, 0xFF, 0xFF, 0xFF});
		texture = SDL_CreateTextureFromSurface(renderer, surface);

		int width, height;
		SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

		rect.x = static_cast<int>(position.x);
		rect.y = static_cast<int>(position.y);
		rect.w = width;
		rect.h = height;
	}

	~PlayerScore()
	{
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}

	void SetScore(int score)
	{
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);

		surface = TTF_RenderText_Solid(font, std::to_string(score).c_str(), {0xFF, 0xFF, 0xFF, 0xFF});
		texture = SDL_CreateTextureFromSurface(renderer, surface);

		int width, height;
		SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
		rect.w = width;
		rect.h = height;
	}

	void Draw()
	{
		SDL_RenderCopy(renderer, texture, nullptr, &rect);
	}

	SDL_Renderer* renderer;
	TTF_Font* font;
	SDL_Surface* surface{};
	SDL_Texture* texture{};
	SDL_Rect rect{};
};

Contact CheckPlayerCollision(Ball const& ball, Player const& player)
{
	float ballLeft = ball.position.x;
	float ballRight = ball.position.x + BALL_WIDTH;
	float ballTop = ball.position.y;
	float ballBottom = ball.position.y + BALL_HEIGHT;

	float playerLeft = player.position.x ;
	float playerRight = player.position.x + PLAYER_WIDTH;
	float playerTop = player.position.y;
	float playerBottom = player.position.y + PLAYER_HEIGHT;

	Contact contact{};

	if (ballLeft >= playerRight)
	{
		return contact;
	}

	if (ballRight <= playerLeft)
	{
		return contact;
	}

	if (ballTop >= playerBottom)
	{
		return contact;
	}

	if (ballBottom <= playerTop)
	{
		return contact;
	}

	float playerRangeUpper = playerBottom - (2.0f * PLAYER_HEIGHT / 3.0f);
	float playerRangeMiddle = playerBottom - (PLAYER_HEIGHT / 3.0f);

	if (ball.velocity.x < 0)
	{
		// Left player
		contact.penetration = playerRight - ballLeft;
	}
	else if (ball.velocity.x > 0)
	{
		// Right player
		contact.penetration = playerLeft - ballRight;
	}

	if ((ballBottom > playerTop)
	    && (ballBottom < playerRangeUpper))
	{
		contact.type = CollisionType::Top;
	}
	else if (ball.position.x == WINDOW_WIDTH / 2.0f && ball.position.y == WINDOW_HEIGHT / 2.0f && ball.velocity.x == 0.0f && ball.velocity.y == 0.0f)
	{
		contact.type = CollisionType::Middle;
	}
	else
	{
		contact.type = CollisionType::Bottom;
	}

	return contact;
}

void HandlePlayerCollision(Player& player1, Player& player2)
{
    if (SDL_HasIntersection(&player1.rect, &player2.rect))
    {
        // Xử lý va chạm giữa hai người chơi
        // Đẩy lẫn nhau

        player1.position.x -= 5.0f;
        player1.position.y -= 5.0f;
        player2.position.x += 5.0f;
        player2.position.y += 5.0f;
    }
}


void HandlePlayerBallCollision(Player& player, Ball& ball, int a)
{
    if (SDL_HasIntersection(&player.rect, &ball.rect))
    {
        // Xử lý va chạm giữa người chơi và quả bóng
        // Tính toán hướng và mức độ va chạm
        
		// if(ball.velocity.x != 0){
		// 	ball.velocity.y = -ball.velocity.y;
	
		// }
		ball.velocity.x = BALL_SPEED;
		if(a==1){
			float ballCenterX = ball.rect.x + ball.rect.w / 2;
			float playerCenterX = player.rect.x + player.rect.h * 4;
			float penetrationX = ballCenterX + playerCenterX;
			ball.velocity.x += penetrationX * 0.001f;
			ball.velocity.x = 0.0f;
			ball.velocity.y = 0.0f;
		}
		if(a==0){
			float ballCenterX = ball.rect.x + ball.rect.w / 2;
			float playerCenterX = player.rect.x + player.rect.h * 4;
			float penetrationX = ballCenterX + playerCenterX;
			ball.velocity.x += penetrationX * 0.001f;
			ball.velocity.x = -ball.velocity.x;
			
		}

        
        // Thay đổi tốc độ của quả bóng dựa trên hướng va chạm
        // ball.velocity.x += penetrationX * 0.01f; // Tăng tốc độ theo hướng x
		// if(ball.velocity.x > 0 && player.velocity.x == 0){
		// 	ball.velocity.x = -ball.velocity.x;
		// }
		// float ballCenterY = ball.rect.y + ball.rect.w / 2;
        // float playerCenterY = player.rect.y + player.rect.h * 4;
        
        // float penetrationY = ballCenterY - playerCenterY;
        
        // // Thay đổi tốc độ của quả bóng dựa trên hướng va chạm
        // ball.velocity.y += penetrationY * 0.01f; // Tăng tốc độ theo hướng x
		// ball.velocity.y = 0.0f;
        
        // Có thể thay đổi hướng di chuyển của quả bóng tùy theo hướng va chạm
        // Ví dụ: nếu va chạm từ phía trên hoặc dưới, thay đổi hướng di chuyển theo y
    }
}


Contact CheckWallCollision(Ball const& ball)
{
	float ballLeft = ball.position.x;
	float ballRight = ball.position.x + BALL_WIDTH;
	float ballTop = ball.position.y;
	float ballBottom = ball.position.y + BALL_HEIGHT;

	Contact contact{};

	if (ballLeft < 0.0f)
	{
		contact.type = CollisionType::Left;
	}	
	else if (ballRight > WINDOW_WIDTH)
	{
		contact.type = CollisionType::Right;
	}
	else if (ballTop < 0.0f)
	{
		contact.type = CollisionType::Top;
		contact.penetration = -ballTop;
	}
	else if (ballBottom > WINDOW_HEIGHT)
	{
		contact.type = CollisionType::Bottom;
		contact.penetration = WINDOW_HEIGHT - ballBottom;
	}

	return contact;
}


int main(int argc, char *argv[]){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("error initializing SDL: %s\n", SDL_GetError());
	}
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	TTF_Init();
	SDL_Window* window = SDL_CreateWindow("GAME", // creates a window
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	TTF_Font* scoreFont = TTF_OpenFont("DejaVuSansMono.ttf", 40);

	PlayerScore playerOneScoreText(Vec2(WINDOW_WIDTH / 4, 20), renderer, scoreFont);

	PlayerScore playerTwoScoreText(Vec2(3 * WINDOW_WIDTH / 4, 20), renderer, scoreFont);

	Ball ball(
			Vec2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f),
			Vec2(0.0f, 0.0f));

	Player playerOne(
			Vec2(50.0f, WINDOW_HEIGHT / 2.0f),
			Vec2(0.0f, 0.0f));

	Player playerTwo(
		Vec2(WINDOW_WIDTH - 50.0f, WINDOW_HEIGHT / 2.0f),
		Vec2(0.0f, 0.0f));

	int playerOneScore = 0;
	int playerTwoScore = 0;

	bool running = true;
	bool buttons[8]={};

	
	float dt = 0.0f;

	while(running) {
		auto startTime = std::chrono::high_resolution_clock::now();
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				running = false;
			}
			else if(event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}
				else if (event.key.keysym.sym == SDLK_w)
				{
					buttons[Buttons::PlayerOneUp] = true;
				}
				else if (event.key.keysym.sym == SDLK_s)
				{
					buttons[Buttons::PlayerOneDown] = true;
				}
				else if (event.key.keysym.sym == SDLK_UP)
				{
					buttons[Buttons::PlayerTwoUp] = true;
				}
				else if (event.key.keysym.sym == SDLK_DOWN)
				{
					buttons[Buttons::PlayerTwoDown] = true;
				}
				else if (event.key.keysym.sym == SDLK_a)
				{
					buttons[Buttons::PlayerOneLeft] = true;
				}
				else if (event.key.keysym.sym == SDLK_d)
				{
					buttons[Buttons::PlayerOneRight] = true;
				}
				else if (event.key.keysym.sym == SDLK_RIGHT)
				{
					buttons[Buttons::PlayerTwoRight] = true;
				}
				else if (event.key.keysym.sym == SDLK_LEFT)
				{
					buttons[Buttons::PlayerTwoLeft] = true;
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_w)
				{
					buttons[Buttons::PlayerOneUp] = false;
				}
				else if (event.key.keysym.sym == SDLK_s)
				{
					buttons[Buttons::PlayerOneDown] = false;
				}
				else if (event.key.keysym.sym == SDLK_UP)
				{
					buttons[Buttons::PlayerTwoUp] = false;
				}
				else if (event.key.keysym.sym == SDLK_DOWN)
				{
					buttons[Buttons::PlayerTwoDown] = false;
				}
				else if (event.key.keysym.sym == SDLK_a)
				{
					buttons[Buttons::PlayerOneLeft] = false;
				}
				else if (event.key.keysym.sym == SDLK_d)
				{
					buttons[Buttons::PlayerOneRight] = false;
				}
				else if (event.key.keysym.sym == SDLK_RIGHT)
				{
					buttons[Buttons::PlayerTwoRight] = false;
				}
				else if (event.key.keysym.sym == SDLK_LEFT)
				{
					buttons[Buttons::PlayerTwoLeft] = false;
				}
			}
		}
		if (buttons[Buttons::PlayerOneUp])
		{
			playerOne.velocity.y = -PLAYER_SPEED;
		}
		else if (buttons[Buttons::PlayerOneDown])
		{
			playerOne.velocity.y = PLAYER_SPEED;
		}
		else if (buttons[Buttons::PlayerOneRight])
		{
			playerOne.velocity.x = PLAYER_SPEED;
		}
		else if (buttons[Buttons::PlayerOneLeft])
		{
			playerOne.velocity.x = -PLAYER_SPEED;
		}
		else
		{
			playerOne.velocity.y = 0.0f;
			playerOne.velocity.x = 0.0f;
		}

		if (buttons[Buttons::PlayerTwoUp])
		{
			playerTwo.velocity.y = -PLAYER_SPEED;
		}
		else if (buttons[Buttons::PlayerTwoDown])
		{
			playerTwo.velocity.y = PLAYER_SPEED;
		}
		else if (buttons[Buttons::PlayerTwoRight])
		{
			playerTwo.velocity.x = PLAYER_SPEED;
		}
		else if (buttons[Buttons::PlayerTwoLeft])
		{
			playerTwo.velocity.x = -PLAYER_SPEED;
		}
		else
		{
			playerTwo.velocity.y = 0.0f;
			playerTwo.velocity.x = 0.0f;
		}
		// Update the player positions

		// Xử lý va chạm giữa hai người chơi
		HandlePlayerCollision(playerOne, playerTwo);

		// Xử lý va chạm giữa người chơi và quả bóng


		playerOne.Update(dt);
		playerTwo.Update(dt);


		// Update the ball position
		ball.Update(dt);

		
		// Check collisions
		if (Contact contact = CheckPlayerCollision(ball, playerOne);
			contact.type != CollisionType::None)
		{
			float ballLeft = ball.position.x;
			float ballRight = ball.position.x + BALL_WIDTH;
			float ballTop = ball.position.y;
			float ballBottom = ball.position.y + BALL_HEIGHT;

			float playerLeft = playerOne.position.x ;
			float playerRight = playerOne.position.x + PLAYER_WIDTH;
			float playerTop = playerOne.position.y;
			float playerBottom = playerOne.position.y + PLAYER_HEIGHT;

			float playerRangeUpper = playerBottom - (2.0f * PLAYER_HEIGHT / 3.0f);
			float playerRangeMiddle = playerBottom - (PLAYER_HEIGHT / 3.0f);
			
			if((ballLeft < playerRight) && playerOne.velocity.x >= 0){
				// if(contact.type == CollisionType::Top || contact.type == CollisionType::Bottom){
				// 	ball.CollideWithPlayer(contact, playerOne);
				// }
				// else {
				// 	ball.velocity.y = 0.0f;
				// }
				HandlePlayerBallCollision(playerOne, ball,0);
				ball.CollideWithPlayer(contact, playerOne);
					ball.velocity.x = -ball.velocity.x;

				if(playerOne.velocity.x == 0.0f){
					ball.velocity.x = -ball.velocity.x;
				}
			}
			// else 
			if((ballRight > playerLeft)&& playerOne.velocity.x <= 0){
				// if(contact.type == CollisionType::Top || contact.type == CollisionType::Bottom){
				// 	ball.CollideWithPlayer(contact, playerOne);
				// }
				// else {
				// 	ball.velocity.y = 0.0f;
				// }
				HandlePlayerBallCollision(playerOne, ball,0);
				if(playerOne.velocity.x == 0.0f){
					ball.velocity.x = -ball.velocity.x;
				}ball.CollideWithPlayer(contact, playerOne);
			}
			// if(contact.type == CollisionType::Top || contact.type == CollisionType::Bottom){
			// 	ball.CollideWithPlayer(contact, playerOne);
			// }
		}
		else if (Contact contact = CheckPlayerCollision(ball, playerTwo);
			contact.type != CollisionType::None)
		{
			float ballLeft = ball.position.x;
			float ballRight = ball.position.x + BALL_WIDTH;
			float ballTop = ball.position.y;
			float ballBottom = ball.position.y + BALL_HEIGHT;

			float playerLeft = playerTwo.position.x ;
			float playerRight = playerTwo.position.x + PLAYER_WIDTH;
			float playerTop = playerTwo.position.y;
			float playerBottom = playerTwo.position.y + PLAYER_HEIGHT;

			float playerRangeUpper = playerBottom - (2.0f * PLAYER_HEIGHT / 3.0f);
			float playerRangeMiddle = playerBottom - (PLAYER_HEIGHT / 3.0f);

			if((ballLeft <= playerRight) && playerTwo.velocity.x >= 0){
				HandlePlayerBallCollision(playerTwo, ball,1);
				ball.CollideWithPlayer(contact, playerTwo);
				if(playerTwo.velocity.x == 0.0f){
					ball.velocity.x = -ball.velocity.x;
				}
			}
			// else 
			if((ballRight >= playerLeft) && playerTwo.velocity.x <= 0){
				ball.CollideWithPlayer(contact, playerTwo);
				HandlePlayerBallCollision(playerTwo, ball,0);
				if(playerTwo.velocity.x == 0.0f){
					ball.velocity.x = -ball.velocity.x;
				}
			}
			// if(contact.type == CollisionType::Top || contact.type == CollisionType::Bottom){
			// 	ball.CollideWithPlayer(contact, playerTwo);
			// }
		}
		else if (contact = CheckWallCollision(ball);
			contact.type != CollisionType::None)
		{
			ball.CollideWithWall(contact);

			if (contact.type == CollisionType::Left)
			{
				++playerTwoScore;

				playerTwoScoreText.SetScore(playerTwoScore);
			}
			else if (contact.type == CollisionType::Right)
			{
				++playerOneScore;

				playerOneScoreText.SetScore(playerOneScore);
			}
			else
			{
			}
		}
		SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
		SDL_RenderClear(renderer);

		// Set the draw color to be white
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

		// Draw the ball
		ball.Draw(renderer);

		// Draw the players
		playerOne.Draw(renderer);
		playerTwo.Draw(renderer);

		// Display the scores
		playerOneScoreText.Draw();
		playerTwoScoreText.Draw();


		// Present the backbuffer
		SDL_RenderPresent(renderer);


		// Calculate frame time
		auto stopTime = std::chrono::high_resolution_clock::now();
		dt = std::chrono::duration<float, std::chrono::milliseconds::period>(stopTime - startTime).count();
	}


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont(scoreFont);
	TTF_Quit();
	SDL_Quit();

	return 0;
}
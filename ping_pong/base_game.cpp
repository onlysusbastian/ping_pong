#include<iostream>
#include<raylib.h>

using namespace std;

//ball class to give ball some attibutes

class Ball {
public:
	float x, y;
	int radius;
	int speed_x, speed_y;

	void Draw() {
		DrawCircle(x, y, radius, RAYWHITE);
	}
	
	//update method to get the ball movin' dawg!

	void Update() {
		x += speed_x;
		y += speed_y;

		if (y + radius >= GetScreenHeight() || y - radius <= 0)
		{
			speed_y *= -1;
		}

		if (x + radius >= GetScreenWidth() || x - radius <= 0)
		{
			speed_x *= -1;
		}
	}
};


//paddle class

class Paddle
{
public :
	float x, y;
	float width, height;
	int speed;

	void Draw()
	{
		DrawRectangle(x, y, width, height, RAYWHITE);
	}

	void Update() {

		if (IsKeyDown(KEY_UP))
		{
			y = y - speed;
		}

		if (IsKeyDown(KEY_DOWN))
		{
			y = y + speed;
		}

		if (y + height >= GetScreenHeight())
		{
			y = GetScreenHeight() - height;
		}

		if (y <= 0)
		{
			y = 0;
		}
	}

};
	
Paddle player;

//ball instance
Ball ball;

int main()

{
	cout << "starting the game" << endl;

	const int screen_width = 1280;
	const int screen_height= 800;


	SetTargetFPS(60);
	//initialzing ball//

	ball.radius = 20;
	ball.x = screen_width / 2;
	ball.y = screen_height / 2;
	ball.speed_x = 7;
	ball.speed_y = 7;
	

	//initializing player
	
	player.height = 120;
	player.width = 25;
	player.x = screen_width - player.width - 10;
	player.y = screen_height/2 - player.height/2;

	player.speed = 6;


	InitWindow(screen_width,screen_height, "pong game");

	

	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		//upadate ball call

		ball.Update();
		player.Update();

		DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
		
		ball.Draw();
		


		
		DrawRectangle(10, screen_height/2 - 60, 25, 120, RAYWHITE);

		player.Draw();


		ClearBackground(BLACK);


		EndDrawing();
	}


	return 0;	

	//game loop ends:
}
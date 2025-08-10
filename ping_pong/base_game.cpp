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
	//end initialization

	InitWindow(screen_width,screen_height, "pong game");

	

	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		//upadate ball call

		ball.Update();

		DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
		
		ball.Draw();

		DrawRectangle(15, screen_height / 2 - 60, 25, 120, RAYWHITE);
		DrawRectangle(screen_width-40, screen_height / 2 - 60, 25, 120, RAYWHITE);
		ClearBackground(BLACK);


		EndDrawing();
	}


	return 0;	

	//game loop ends:
}
#include<iostream>
#include<raylib.h>

using namespace std;


//player point and cpu point count initialization
int player_point=0;
int cpu_point=0;


//ball class to give ball some attibutes

class Ball {
public:
	float x, y;
	int radius;
	int speed_x, speed_y;

	//draw method for the ball

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

		if (x + radius >= GetScreenWidth())
		{
			cpu_point++;

			ResetBall();

		}

		if ( x - radius <= 0)
		{
			player_point++;

			ResetBall();

		}
	}
	//function toi reset the ball after it touches the edge
	void ResetBall()
	{
		x = GetScreenWidth() / 2;
		y = GetScreenHeight()/ 2;
		
	int speed_choice[2] = { 1,1 };
	speed_x *= speed_choice[GetRandomValue(0, 1)];
	speed_y *= speed_choice[GetRandomValue(0, 1)];
}
};


//class to control the paddle
class Paddle
{
protected :

	//Limitmovement method can limit movement of the ball when the ball hits either side
	void Limitmovement() {
		
		if (y + height >= GetScreenHeight())
		{
			y = GetScreenHeight() - height;
		}

		if (y <= 0)
		{
			y = 0;
		}
	}
public :
	float x, y;
	float width, height;
	int speed;

	//Draw method for the rectangle
	void Draw()
	{
		DrawRectangle(x, y, width, height, RAYWHITE);
	}

	//Update method for the rectangle
	void Update() {

		if (IsKeyDown(KEY_UP))
		{
			y = y - speed;
		}

		if (IsKeyDown(KEY_DOWN))
		{
			y = y + speed;
		}
		Limitmovement();
	}


};
//cpu paddle class inherited 
class CpuPaddle : public Paddle {

public:
	void Update(int ball_y)
	{
		if (y + height / 2 > ball_y)
		{
			y = y - speed;
		}

		
		if (y + height / 2 < ball_y)
		{
			y = y+ speed;
		}
		Limitmovement();
	}
};
	
Paddle player;	
CpuPaddle cpu;

//ball instance
Ball ball;

int main()

{
	//seting up the constant screen width and height
	const int screen_width = 1920;
	const int screen_height= 1080;


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


	//inittializing the cpu 
	cpu.height = 120;
	cpu.width = 25;
	cpu.x = 10;
	cpu.y = screen_height / 2 - cpu.height / 2;
	cpu.speed = 6;


	InitWindow(screen_width,screen_height, "pong game");

	

	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		//ball, player, cpu Update
		ball.Update();
		player.Update();
		cpu.Update(ball.y);
		
		//collision checking

		if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, Rectangle{ player.x, player.y, player.width,player.height }))
		{
			ball.speed_x *= -1;
		}

		if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, Rectangle{ cpu.x, cpu.y, cpu.width,cpu.height }))
		{
			ball.speed_x *= -1;
		}

		DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
	
		//draw function to draw the player, ball and cpu
		ball.Draw();
		cpu.Draw();
		player.Draw();
		

		//drawing the text of the score 
		DrawText(TextFormat("%i", cpu_point), screen_width / 4 - 20, 20, 80, YELLOW);
		DrawText(TextFormat("%i", player_point),3 * screen_width / 4 - 20, 20, 80, YELLOW);

		ClearBackground(BLACK);


		EndDrawing();
	}


	return 0;	

	//game loop ends:
}
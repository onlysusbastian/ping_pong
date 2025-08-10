#include<iostream>
#include<raylib.h>

using namespace std;

int main()

{
	cout << "starting the game" << endl;

	const int screen_width = 1280;
	const int screen_height= 800;


	SetTargetFPS(60);


	InitWindow(screen_width,screen_height, "pong game");

	

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		
		DrawCircle(screen_width / 2, screen_height / 2, 20, RAYWHITE);

		DrawRectangle(15, screen_height / 2 - 60, 25, 120, RAYWHITE);
		DrawRectangle(screen_width-40, screen_height / 2 - 60, 25, 120, RAYWHITE);



		EndDrawing();
	}


	return 0;	

	//game loop ends:
}
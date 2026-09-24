#include "raylib.h"
#include <cmath>
#include <iostream>

void renderSprezyne() {
	/// ----------- CONFIG ---------------
	const int screenWidth = 900;
	const int screenHeight = 600;

	const int wahadloSize = 90;
	const int lineSize = 10;

	const int k = 100;
	const int m = 100;
	const int A = 200; // 1 metr to 1 pisel, tak
	// - -----------------------------------

	const int omega = sqrt(k / m);

	InitWindow(screenWidth, screenHeight, "Ruch Drgajacy - Wahadlo sprezynowe");
	SetTargetFPS(60);

	long time = 0;

	while (!WindowShouldClose())
	{
		time++;
		int displacement = A * cos(omega * (time / 10.0));

		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawRectangle(screenWidth / 3, screenHeight / 2 - lineSize / 2, screenWidth / 3, lineSize, GRAY);

		DrawRectangle(screenWidth / 2 - wahadloSize / 2, screenHeight / 2 - wahadloSize / 2 + displacement, wahadloSize, wahadloSize, BLUE);

		EndDrawing();
	}

	CloseWindow();
}

void renderMath() {
	/// ----------- CONFIG ---------------
	const int screenWidth = 900;
	const int screenHeight = 600;

	const int wahadloSize = 90;
	const int lineSize = 10;

	const int l = 400;
	const int A = 200; // 1 metr to 1 pisel, tak
	// - -----------------------------------

	const float omega = sqrt(10.0 / l);

	InitWindow(screenWidth, screenHeight, "Ruch Drgajacy - Wahadlo sprezynowe");
	SetTargetFPS(60);

	long time = 0;

	while (!WindowShouldClose())
	{
		time++;
		float displacement = A * cos(omega * (time / 10.0));
		float kat = acos(displacement / l);
		float Ydis = l * sin(kat);

		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawLine(screenWidth / 2, 0, screenWidth / 2 + displacement, Ydis, BLACK);

		DrawRectangle(screenWidth / 3, 0, screenWidth / 3, lineSize, GRAY);

		DrawRectangle(screenWidth / 2 - wahadloSize / 2 + displacement, Ydis, wahadloSize, wahadloSize, BLUE);



		EndDrawing();
	}

	CloseWindow();
}

int main()
{
	//renderSprezyne();

	renderMath();

	return 0;
}
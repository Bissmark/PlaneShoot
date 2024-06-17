#include "raylib.h"
#include <vector>

int main()
{
	// Initialization
	const int screenWidth = 550;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

	class Bullet
	{
	public:
		Vector2 position;
		float speed;
		Color color;

		Bullet()
		{
			position = { (screenWidth / 2.0f) - 25, screenHeight - 60 };
			speed = 1;
			color = RED;
		}

		Bullet(Vector2 pos, float spd, Color col)
		{
			position = pos;
			speed = spd;
			color = col;
		}

		void Move()
		{
			position.y -= speed;
		}

		void Draw()
		{
			DrawRectangle(position.x, position.y, 10, 10, color);
		};
	};

	class Player {
	public:
		Vector2 position;
		float speed;
		Color color;
		std::vector<Bullet> bullets;

		Player() 
		{
			position = { (screenWidth / 2.0f) - 25, screenHeight - 60 };
			speed = 5;
			color = RED;
		}

		Player(Vector2 pos, float spd, Color col) 
		{
			position = pos;
			speed = spd;
			color = col;
		}

		void Move() 
		{
			if (IsKeyDown(KEY_RIGHT)) 
				position.x += speed;
			if (IsKeyDown(KEY_LEFT)) 
				position.x -= speed;
			if (IsKeyDown(KEY_UP)) 
				position.y -= speed;
			if (IsKeyDown(KEY_DOWN)) 
				position.y += speed;
		}

		void Draw() 
		{
			DrawRectangle(position.x, position.y, 50, 50, color);
		};

		void FireBullet() 
		{
			if (IsKeyPressed(KEY_SPACE)) 
			{
				bullets.push_back(Bullet({ position.x + 20, position.y }, 5, BLUE));
			}

			for (int i = 0; i < bullets.size(); i++) 
			{
				bullets[i].Move();
				bullets[i].Draw();
			}
		}

		void DestroyBullet(int index) 
		{
			bullets.erase(bullets.begin() + index);
		}

		void DestroyAllBullets() 
		{
			bullets.clear();
		}
	};

	Player player;
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		player.Draw();
		player.Move();
		player.FireBullet();

		// Update

		// Draw

		BeginDrawing();

		ClearBackground(RAYWHITE);

		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();

	}

	// De-Initialization

	CloseWindow();        // Close window and OpenGL context

	return 0;

}
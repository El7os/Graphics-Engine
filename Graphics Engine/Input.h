#pragma once

class Input
{
public:

	static inline Input& GetInstance()
	{
		static Input Instance;
		return Instance;
	}

	inline bool IsXClicked() { return bXClicked; }
	inline bool IsKeyPressed() { return bKeyPressed; }

	inline char GetKeyUp() { return KeyUp; }
	inline char GetKeyDown() { return KeyDown; }

	inline bool IsLeftMouseButtonClicked() { return bLeftMouseButtonClicked; }
	inline bool IsRightMouseButtonClicked() { return bRightMouseButtonClicked; }
	inline bool IsMiddleMouseButtonClicked() { return bMiddleMouseButtonClicked; }

	inline int GetMousePositionX() { return MousePositionX; }
	inline int GetMousePositionY() { return MousePositionY; }

	inline int GetMouseMotionX() { return MouseMotionX; }
	inline int GetMouseMotionY() { return MouseMotionY; }

	void Update();

private:

	Input();
	Input(Input&&) = default;
	Input(const Input&) = delete;

	Input& operator=(Input&&) = default;
	Input& operator=(const Input&) = delete;

	char KeyUp;
	char KeyDown;
	
	bool bXClicked;
	bool bKeyPressed;

	bool bLeftMouseButtonClicked;
	bool bRightMouseButtonClicked;
	bool bMiddleMouseButtonClicked;

	int MousePositionX;
	int MousePositionY;

	int MouseMotionX;
	int MouseMotionY;

};
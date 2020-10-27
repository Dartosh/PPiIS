#include <iostream>

struct Vector2
{
	float x, y;

	Vector2(const float x, const float y) :
		x(x),
		y(y)
	{  }

	const Vector2& operator+(const Vector2& r) const
	{
		return
			Vector2(
				this->x + r.x,
				this->y + r.y
			);
	}

	const Vector2& operator+=(const Vector2& r)
	{
		this->x += r.x;
		this->y += r.y;

		return *this;
	}
};

int main()
{

	system("pause");
	return 0;
}
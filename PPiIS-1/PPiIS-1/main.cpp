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

class Figure2D
{
public:
	virtual void Move(const Vector2& offset) = 0;

	virtual const Figure2D& operator+(const Figure2D& r) const = 0;
private:

};

class Rectangle : public Figure2D
{
public:
	Rectangle(const Vector2& downLeft, const Vector2& topRight) :
		_downLeft(downLeft),
		_topRight(topRight)
	{ }

	void Move(const Vector2& offset) override
	{
		_downLeft += offset;
		_topRight += offset;
	}

	const Figure2D& operator+(const Figure2D& other) const override
	{
		Figure2D* result = new Rectangle(*this);

		// Operation...

		return *result;
	}

private:
	Vector2 _downLeft;
	Vector2 _topRight;
};

int main()
{

	system("pause");
	return 0;
}
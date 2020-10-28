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

	virtual const Figure2D& operator+(const Figure2D& r) const = 0; //#1
	virtual const Figure2D& Intersection(const Figure2D& r) const = 0; //#2

	virtual const Figure2D& operator-(const Figure2D& r) const = 0; //#1
	virtual const Figure2D& Crossing(const Figure2D& r) const = 0; //#2
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

	const Figure2D& operator+(const Figure2D& other) const override //#1
	{
		Figure2D* result = new Rectangle(*this);

		// Operation...

		return *result;
	}

	const Figure2D& Intersection(const Figure2D& r) const override // #2
	{
		Figure2D* result = new Rectangle(*this);

		// Operation...

		return *result;
	}

	const Figure2D& operator-(const Figure2D& other) const override //#1
	{
		Figure2D* result = new Rectangle(*this);

		// Operation...

		return *result;
	}

	const Figure2D& Crossing(const Figure2D& r) const override // #2
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
	Rectangle a(Vector2(0, 0), Vector2(5, 5));
	Rectangle b(Vector2(3, 3), Vector2(10, 10));

	const Figure2D& c = a.Intersection(b);

	const Figure2D& d = a + b;

	const Figure2D& e = a.Crossing(b);

	const Figure2D& f = a - b;

	system("pause");
	return 0;
}
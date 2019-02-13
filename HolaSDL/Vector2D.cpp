#include "Vector2D.h"
#include <math.h>
#include <assert.h>

// needed for visual studio
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

Vector2D::Vector2D() :
		x_(), y_() {
}

Vector2D::Vector2D(const Vector2D& v) :
		x_(v.getX()), y_(v.getY()) {
}

Vector2D::Vector2D(double x, double y) :
		x_(x), y_(y) {
}

Vector2D::~Vector2D() {
}

double Vector2D::getX() const {
	return x_;
}

double Vector2D::getY() const {
	return y_;
}

void Vector2D::setX(double x) {
	x_ = x;
}

void Vector2D::setY(double y) {
	y_ = y;
}

void Vector2D::set(const Vector2D& v) {
	x_ = v.getX();
	y_ = v.getY();
}

void Vector2D::set(double x, double y) {
	x_ = x;
	y_ = y;
}

double Vector2D::magnitude() const {
	return sqrt(pow(x_, 2) + pow(y_, 2));
}

Vector2D Vector2D::rotate(double degrees) {
	Vector2D r;

	degrees = fmod(degrees, 360.0);
	if (degrees > 180.0) {
		degrees = degrees - 360.0;
	} else if (degrees <= -180.0) {
		degrees = 360.0 + degrees;
	}

	assert(degrees >= -180.0 && degrees <= 180.0);

	double angle = degrees * M_PI / 180.0;
	double sine = sin(angle);
	double cosine = cos(angle);

	//rotation matix
	double matrix[2][2] = { { cosine, -sine }, { sine, cosine } };

	double x = x_;
	double y = y_;

	r.x_ = matrix[0][0] * x + matrix[0][1] * y;
	r.y_ = matrix[1][0] * x + matrix[1][1] * y;

	return r;

}

double Vector2D::angle(const Vector2D& v) const {

	double a2 = atan2(v.getX(), v.getY());
	double a1 = atan2(x_, y_);
	double sign = a1 > a2 ? 1 : -1;
	double angle = a1 - a2;
	double K = -sign * M_PI * 2;
	angle = (abs(K + angle) < abs(angle)) ? K + angle : angle;
	return angle * 180. / M_PI;
}

Vector2D Vector2D::normalize() {
	Vector2D r;
	r.x_ = x_;
	r.y_ = y_;
	double mag = magnitude();
	if (mag > 0.0) {
		r.x_ = r.x_ / mag;
		r.y_ = r.y_ / mag;
	}
	return r;
}

Vector2D Vector2D::operator -(const Vector2D& v) const {
	Vector2D r;
	r.x_ = x_ - v.x_;
	r.y_ = y_ - v.y_;
	return r;
}

Vector2D Vector2D::operator +(const Vector2D& v) const {
	Vector2D r;
	r.x_ = x_ + v.x_;
	r.y_ = y_ + v.y_;
	return r;
}

Vector2D Vector2D::operator *(double d) const {
	Vector2D r;
	r.x_ = x_ * d;
	r.y_ = y_ * d;
	return r;
}

double Vector2D::operator *(const Vector2D& d) const {
	return d.x_ * x_ + d.y_ * y_;
}

Vector2D Vector2D::operator /(double d) const {
	Vector2D r;
	r.x_ = x_ / d;
	r.y_ = y_ / d;
	return r;
}

ostream& operator<<(ostream& os, const Vector2D &v) {
	os << "(" << v.getX() << "," << v.getY() << ")";
	return os;
}

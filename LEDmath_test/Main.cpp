
#include <assert.h>
#include <iostream>
#include "LEDmath.h"

using namespace std;

int main() {

	//Test Point3D addition
	cout << "Test 1 Running: Point3D addition" << endl;
	Point3D p1 = Point3D(1, 2, 3);
	Point3D p2 = Point3D(-6, -2, -4);
	Point3D p3 = Point3D(-5, 0, -1);
	cout << p1 << "+" << p2 << "=" << p3 << endl;
	cout << "Result: " << (p1 + p2) << endl;
	assert((p1 + p2) == p3);
	cout << "Test 1 Success: Point3D addition" << endl;

	//Test Vector addition
	cout << "Test 2 Running: Vector addition" << endl;
	Vector v1 = Vector(p1);
	Vector v2 = Vector(p2);
	Vector v3 = Vector(p3);
	cout << v1 << "+" << v2 << "=" << v3 << endl;
	cout << "Result: " << (v1 + v2) << endl;
	assert((v1 + v2) == v3);
	cout << "Test 2 Success: Vector addition" << endl;

	//Test Point3D zero addition
	cout << "Test 3 Running: Point3D zero addition";
	Point3D p0 = Point3D(0, 0, 0);
	cout << "Result: " << (p0 + p0) << endl;
	assert((p0 + p0) == p0);
	cout << "Test 3 Success: Point3D zero addition" << endl;

	//Test Vector zero addition
	cout << "Test 4 Running: Vector zero addition";
	Vector v0 = Vector(0, 0, 0);
	cout << "Result: " << (v0 + v0) << endl;
	assert((v0 + v0) == v0);
	cout << "Test 4 Success: Vector zero addition" << endl;

	//Test Quaternion multiplication
	cout << "Test 5 Running: Quaternion multiplication" << endl;
	Quaternion q1 = Quaternion(32, 123, 2, 432);
	Quaternion q2 = Quaternion(54, 564, 56, 78);
	Quaternion q3 = Quaternion(-101452, 654, 235954, 31584);
	cout << q1 << "*" << q2 << "=" << q3 << endl;
	cout << "Result: " << (q1 * q2) << endl;
	assert((q1 * q2) == q3);
	cout << "Test 5 Success: Quaternion multiplication" << endl;

	//Test Quaternion normalization
	cout << "Test 6 Running: Quaternion normalization" << endl;
	Quaternion q4 = q1.normalize();
	Quaternion q5 = Quaternion(0.071062, 0.273144, 0.004441, 0.959335);
	cout << "|" << q1 << "|=" << q5 << endl;
	cout << "Result: " << q4 << endl;
	assert(abs(q4.getW() - q5.getW()) < 0.00001);
	assert(abs(q4.getX() - q5.getX()) < 0.00001);
	assert(abs(q4.getY() - q5.getY()) < 0.00001);
	assert(abs(q4.getZ() - q5.getZ()) < 0.00001);
	cout << "Test 6 Success: Quaternion normalization" << endl;

	//Test Quaternion application
	cout << "Test 7 Running: Quaternion application" << endl;
	Point3D rotPoint = q5.apply(p1);
	Point3D expectedRotPoint = Point3D(0.46559, -1.93185, 3.17036);
	cout << "q=" << q5 << endl << "p=" << p1 << endl;
	cout << "qpq*=" << expectedRotPoint << endl;
	cout << "Result: " << rotPoint << endl;
	assert(abs(rotPoint.getX() - expectedRotPoint.getX() < 0.0001));
	assert(abs(rotPoint.getY() - expectedRotPoint.getY() < 0.0001));
	assert(abs(rotPoint.getZ() - expectedRotPoint.getZ() < 0.0001));
	cout << "Test 7 Success: Quaternion application";

	return 0;
}
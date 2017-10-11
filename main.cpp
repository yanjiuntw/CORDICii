#include<iostream>
using namespace std;
double FriendAngle[2][2] = { 20,15,24,7 };
double USR[2] = {128,16};
double CORDIC[3]= {32,64,128};
double Nano = 1024;
double table[] = {36.87,16.26,7.125,1.79,0.895,0.448,0.056};
void main() {
	double InAngle = 0, Out, Angle;
	cout << "¿é¤Jsin¨¤«×" << endl;
	cin >> InAngle; Angle = 90 - InAngle;
	if (Angle < 0)Angle += 360;
	double x = 0, y = 1, xtemp, ytemp;
//stage1
	if (Angle >= 225) {
		xtemp = y;
		ytemp = -x;
		x = xtemp; y = ytemp; Angle -= 270;
	}
	else if (Angle >= 135) {
		xtemp = -x;
		ytemp = -y;
		x = xtemp; y = ytemp; Angle -= 180;
	}
	else if (Angle >= 45) {
		xtemp = -y;
		ytemp = x;
		x = xtemp; y = ytemp; Angle -= 90;
	}xtemp = ytemp = 0;
	cout << "Out1:" << x << "," << y << "\tangle=" << Angle << endl;
//stage2
	for (int i = 0; i < 2; i++) {
		if (Angle > 0) {
			xtemp = FriendAngle[i][0] * x + FriendAngle[i][1] * y;
			ytemp = FriendAngle[i][0] * y - FriendAngle[i][1] * x;
			Angle -= table[i];
		}
		else {
			xtemp = FriendAngle[i][0] * x - FriendAngle[i][1] * y;
			ytemp = FriendAngle[i][0] * y + FriendAngle[i][1] * x;
			Angle += table[i];
		}x = xtemp/25; y = ytemp/25;
	}cout << "Out2:" << x<<","<<y << "\tangle=" << Angle << endl;
//stage3
	if (Angle > 0) {
		xtemp =USR[0] * x + USR[1] * y;
		ytemp = USR[0] * y - USR[1] * x;
		Angle -= table[2];
	}
	else {
		xtemp = USR[0] * x - USR[1] * y;
		ytemp = USR[0] * y + USR[1] * x;
		Angle += table[2];
	}x = xtemp/129; y = ytemp/129;
	cout << "Out3:" << x << "," << y << "\tangle=" << Angle << endl;
//stage4~6
	for (int i = 0; i < 3; i++) {
		if (Angle > 0) {
			xtemp = CORDIC[i] * x + y;
			ytemp = CORDIC[i] * y -  x;
			Angle -= table[3+i];
		}
		else {
			xtemp = CORDIC[i] * x - y;
			ytemp = CORDIC[i] * y +  x;
			Angle += table[3+i];
		}x = xtemp/CORDIC[i]; y = ytemp/CORDIC[i];
	}
	cout << "Out6:" << x << "," << y << "\tangle=" << Angle << endl;
//stage7
	for (int i = 8; i >0; i--) {
		if (Angle > 0) {
			xtemp = Nano * x + i*y;
			ytemp = Nano *y - i* x;
			Angle -= table[6]*i;
		}
		else {
			xtemp = Nano * x - i*y;
			ytemp = Nano*y + i*x;
			Angle += table[6]*i;
		}x = xtemp/Nano; y = ytemp/Nano;
	}
	cout << "Out7:" << x << "," << y << "\tangle=" << Angle << endl;
	system("pause");
}
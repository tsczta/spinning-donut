#include <bits/stdc++.h>
#define oo 1000000000
using namespace std;
struct {
	int illumination_value = 0, z_depth = oo;
}z_buffer[50][50];
const float pi = 3.14;
int R1 = 1, R2 = 2, K2 = 5, K1 = 50 * K2 * 3 / (8 * (R1 + R2));
float A = 0, B = 0;
char screen[50][50];
void reset() {
	for (int i = 0; i < 50; i++) {
    	for (int j = 0; j < 50; j++) {
    		z_buffer[i][j].illumination_value = 0;
    		z_buffer[i][j].z_depth = oo;
		}
	}
	return ;
}
void rotate() {
	A = (A + 0.07 > 2 * pi) ? 0.07 : A + 0.07;
    B = (B + 0.03 > 2 * pi) ? 0.03 : B + 0.03;
    return ;
}
void projection(float x, float y, float z, float luminance) {
	int x_prime = (K1 * -x) / (K2 + z) + 25, y_prime = (K1 * -y) / (K2 + z) + 25;
	luminance = ceil(luminance * 8);
	if (z < z_buffer[y_prime][x_prime].z_depth) {
		z_buffer[y_prime][x_prime].illumination_value = max(1, (int)luminance);
		z_buffer[y_prime][x_prime].z_depth = z;
	}
	return ;
}
void calculate(float A, float B) {
	float sinA = sin(A), cosA = cos(A), sinB = sin(B), cosB = cos(B); 
	for (float phi = 0; phi <= 2 * pi; phi += 0.02) {
		float sinphi = sin(phi), cosphi = cos(phi);
		for (float theta = 0; theta <= 2 * pi; theta += 0.07) {
			float costheta = cos(theta), sintheta = sin(theta);
    		projection((R2 + R1 * costheta) * (cosB * cosphi + sinA * sinB * sinphi) - R1 * cosA * sinB * sintheta,
					   (R2 + R1 * costheta) * (cosphi * sinB - cosB * sinA * sinphi) + R1 * cosA * cosB * sintheta,
					   cosA * (R2 + R1 * costheta) * sinphi + R1 * sinA * sintheta,
					   cosphi * costheta * sinB - cosA * costheta * sinphi - sinA * sintheta + cosB * (cosA * sintheta - costheta * sinA * sinphi));
		}
	}
	return ;
}
void print() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			switch (z_buffer[i][j].illumination_value) {
				case 0 :
					screen[i][j] = ' ';
					break;
				case 1 :
					screen[i][j] = '.';
					break;
				case 2 :
					screen[i][j] = ',';
					break;
				case 3 :
					screen[i][j] = '-';
					break;
				case 4 :
					screen[i][j] = '~';
					break;
				case 5 :
					screen[i][j] = ':';
					break;
				case 6 :
					screen[i][j] = ';';
					break;
				case 7 :
					screen[i][j] = '=';
					break;
				case 8 :
					screen[i][j] = '!';
					break;
				case 9 :
					screen[i][j] = '*';
					break;
				case 10 :
					screen[i][j] = '#';
					break;
				case 11 :
					screen[i][j] = '$';
					break;
				case 12 :
					screen[i][j] = '@';
					break;
			}
			cout << screen[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
	return ;
}
int main() {
    while (true) {
    	system("cls"); 
    	reset();
    	rotate();
    	calculate(A, B);
    	print();
	}
    return 0;
}

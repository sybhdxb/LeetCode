#include <stdio.h>
#include "math.h"
#include "string.h"

#define EARTH_RADIUS  6378137.0
#define PI 3.141592653589793

double rad(double s)
{
	return (double)(s * PI / 180.0);
}
double R_rad(double s)
{
	return (double)(s * 180.0 / PI);
}

// return meter
double GetDistance(double lat1, double lng1, double lat2, double lng2)
{
	double radLat1 = rad(lat1);
	double radLat2 = rad(lat2);
	double a = radLat1 - radLat2;
	double b = rad(lng1) - rad(lng2);
	double s = 2.0 * asin(sqrt(pow(sin(a/2.0), 2.0) + cos(radLat1)*cos(radLat2)*pow(sin(b/2.0), 2.0)));
	
	s *= EARTH_RADIUS;

	return s;
}

// lat is same to the first point.
double GetDistance2ll(double lat1, double lng1, double s)
{
	double radLat1 = rad(lat1);
	double s1 = s / EARTH_RADIUS;
	double b = 0.0;
	double radlng2 = 0.0;
	int i = s/fabs(s);
	
	s1 = pow(sin(s1 / 2.0), 2.0);
	s1 = s1 / (cos(radLat1) * cos(radLat1));
	s1 = sqrt(s1);
	b = 2 * asin(s1);
	radlng2 = rad(lng1) - i * b;
	
	return R_rad(radlng2);
}

int main(void)
{
	double lat1 = 22.705190123;
	double lng1 = 114.243718456;
	double lat2 = 22.705190123;
	double lng2 = 114.243718567;
	double s = 0.0;
	s = GetDistance(lat1, lng1, lat2, lng2);
	printf("s = %lf m\r\n", s);
	
	
	printf("lng2 = %.9lf\r\n", GetDistance2ll(lat1, lng1, -s));
	
	return 0;
}

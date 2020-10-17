#include<iostream>
#include<cmath>

using namespace std;

struct point {
	int x;
	int y;
};

struct triangolo {
	point vertice1;
	point vertice2;
	point vertice3;
	double perimetro;
	double area;
};

double
ControlloRettangolo(int ver1x, int ver1y, int ver2x, int ver2y, int ver3x,
		    int ver3y, triangolo tri)
{
	double lato1, lato2, lato3;
	lato1 =
	    sqrt(((ver1x - ver2x) * (ver1x - ver2x)) +
		 ((ver1y - ver2y) * (ver1y - ver2y)));
	lato2 =
	    sqrt(((ver2x - ver3x) * (ver2x - ver3x)) +
		 ((ver2y - ver3y) * (ver2y - ver3y)));
	lato3 =
	    sqrt(((ver3x - ver1x) * (ver3x - ver1x)) +
		 ((ver3y - ver1y) * (ver3y - ver1y)));
	tri.perimetro = lato1 + lato2 + lato3;
	tri.area =
	    sqrt(((tri.perimetro) / 2) * ((tri.perimetro) / 2 - ver1x) *
		 ((tri.perimetro) / 2 - lato2) * ((tri.perimetro) / 2 - lato3));
	bool rettangolo = 0;
	if ((ver1x > lato2) && (ver1x > lato3))
		rettangolo =
		    ((lato1) * (lato1)) ==
		    (lato2) * (lato2) + (lato3) * (lato3);
	if ((lato2 > ver1x) && (lato2 > lato3))
		rettangolo =
		    ((lato2) * (lato2)) ==
		    (lato1) * (lato1) + (lato3) * (lato3);
	if ((lato3 > lato2) && (lato3 > lato1))
		rettangolo =
		    ((lato3) * (lato3)) ==
		    (lato1) * (lato1) + (lato2) * (lato2);
	if (rettangolo)
		cout << "Il triangolo è rettangolo" << endl;
	else
		cout << "Il triangolo non è rettangolo" << endl;
	return tri.area;
};

int main()
{
	triangolo tri;
	cout << "Dimmi x e y del primo vertice" << endl;
	cin >> tri.vertice1.x >> tri.vertice1.y;
	cout << "Dimmi x e y del secondo vertice" << endl;
	cin >> tri.vertice2.x >> tri.vertice2.y;
	cout << "Dimmi x e y del terzo vertice" << endl;
	cin >> tri.vertice3.x >> tri.vertice3.y;
	ControlloRettangolo(tri.vertice1.x, tri.vertice1.y, tri.vertice2.x,
			    tri.vertice2.y, tri.vertice3.x, tri.vertice3.y,
			    triangolo tri);

	return 0;
}

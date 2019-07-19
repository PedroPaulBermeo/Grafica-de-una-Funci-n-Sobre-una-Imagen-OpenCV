#include <cstdlib>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <math.h>
using namespace std;
using namespace cv;
int main(int argc, char* args[]) {
	Mat image = imread("B-Catedral-San-Basilio.jpg");
	Mat imageGris;
	Mat image2;
	int y = 0;
	int cx = round(image.cols / 2);
	int cy = round(image.rows / 2);
	cout << "cx" << cx << endl;
	cout << "cy" << cy << endl;
	//for (int x = -4; x < 4; x++){
	vector<Point2f> puntos;

	for (int x = -40; x < 40; x++) {
		y = ((-2 * ((pow(x, 3))) + (13 * x)));
		//y = (pow(x, 3));
		cout << "y" << y << endl;
		
		//118131	imagel.cols
		//y			x
		y = (y * (image.rows)) / (118131);
		//x = (x * (image.cols/2))/40;
		
		//40	image.cols
		//-40	x
		//x = ((x*image.cols)/40);
		//x = x * 80;
		//Point2f punto = Point((cx - (x*80)), (cy - (y*16)));
		circle(image, Point((cx - (x * 7.5`dd)), (cy - y)), 1, Scalar(0, 0, 0), 5);

		//Point2f punto = Point((cx-(x*8)), (cy-y));
		//puntos.push_back(punto);

	}

	//Mat curve(puntos, true);
	//curve.convertTo(curve, CV_32S);
	//polylines(image, curve, false, Scalar(0,0,0), 2, COLOR_BGR2GRAY);

	image.copyTo(image2);
	cvtColor(image, imageGris, COLOR_BGR2GRAY);
	imshow("imagen2", image2);

	int* histo = new int[256];
	int pixel = 0;
	for (int i = 0; i < 256; i++)
		histo[i] = 0;
	
	int c1 = 0;
	int c2 = 0;
	bool cumple = false;
	for (int i = 0; i < imageGris.cols; i++) {
		cumple = false;
		for (int j = 0; j < imageGris.rows; j++) {
			pixel = (int)imageGris.at<uchar>(j, i);
			histo[pixel]++;
			if (pixel == 0) {
				cumple= true;
			}
			if (cumple == true) {
				image2.at<Vec3b>(j, i) = image.at<Vec3b>(j, i);
			}
			else {
				image2.at<Vec3b>(j, i) = (0,0,0);
			}
		}
	}
	int mayor = 0;
	int indice = 0;
	for (int i = 0; i < 256; i++) {
		if (mayor < int(histo[i])) {
			indice = i;
			mayor = int(histo[i]);
		}
		cout << histo[i] << "|";
	}
	cout << endl;
	cout << "mayor" << mayor << "|";
	cout << "indice" << indice << "|";
	cout << endl;
	imshow("imagen", image);
	imshow("imagen2", image2);
	waitKey(0);
	return 0;
}
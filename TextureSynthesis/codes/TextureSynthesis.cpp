#include "stdafx.h"
#include <iostream>
#include <opencv2/opencv.hpp>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
using namespace cv;
int main(int argc, char** argv) {
	/*

	//参数变量初始化
	string type;
	string inputImageName;
	string outputImageName;
	string overlappingAreaPixelNumber; // Over lapping area pixel number
	string synthesisSize;
	int col = -1; //get查询的列索引0～n
	int ch;

	//获取参数
	if (argc > 1) {
		type = string(argv[1]);
	}

	opterr = 0; //选项错误时不让报错
	while ((ch = getopt(argc, argv, "i:o:r:s:")) != -1) {
		switch (ch) {
		case 'i': inputImageName = string(optarg); break;
		case 'o': outputImageName = string(optarg); break;
		case 'r': overlappingAreaPixelNumber = string(optarg); break;
		case 's': synthesisSize = string(optarg); break;
		}
	}
	

	cout << inputImageName << endl;
	cout << outputImageName << endl;
	cout << overlappingAreaPixelNumber << endl;
	cout << synthesisSize << endl;
	return 0;
	*/
	
	// //  Display Image using C++ & OpenCV  // #include <iostream> #include <opencv2/opencv.hpp> 

		//Mat img = imread("Image.jpg", CV_LOAD_IMAGE_GRAYSCALE);
		//Mat img = imread("Image.jpg");
		Mat kim1 = imread("Image.jpg");
		Mat kim2 = imread("Image.jpg");
		int rows = kim1.rows;
		int cols = kim1.cols;
		int i = 0; // iterator variable
		int j = 0; // iterator variable

		Mat kimCreate;
		kimCreate.create(rows, 2 * cols, CV_8UC3);
		namedWindow("Kim  copyRight: codingstory", WINDOW_AUTOSIZE);    
		for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++) {
				Vec3b RGB = kim1.at<Vec3b>(i, j);
				uchar blue = RGB.val[0];
				uchar green = RGB.val[1];
				uchar red = RGB.val[2];

				kimCreate.at<Vec3b>(i, j) = RGB;
			}	
		}
		for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++) {
				Vec3b RGB = kim2.at<Vec3b>(i, j);
				uchar blue = RGB.val[0];
				uchar green = RGB.val[1];
				uchar red = RGB.val[2];

				kimCreate.at<Vec3b>(i, j + cols) = RGB;
			}
		}
		
		cout << "ROWS: " << rows << endl;
		cout << "COLS: " << cols << endl;

		imshow("Kim  copyRight: codingstory", kimCreate);
		cout << endl;

		waitKey(0);

		return 0;
	}

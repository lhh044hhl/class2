#include <iostream> 
#include <opencv2/opencv.hpp>
using namespace cv;

using namespace std;
//练习一
/*int main()
{
	cv::Mat src_color = imread("D:\\textphoto\\2.png");
	std::vector<cv::Mat> channels;
	cv::split(src_color, channels);
	cv::Mat B = channels.at(0);
	cv::Mat G = channels.at(1);
	cv::Mat R = channels.at(2);
	cv::imshow("red", R);
	cv::imshow("blue", B);
	cv::imshow("green", G);
	cv::imshow("original Mat", src_color);
	 waitKey(0);
}
*/
//练习二
/*
int main() {
	VideoCapture cap;

	cap.open(0);

	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return-1;
	}

	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;

	while (1)
	{
		cv::Mat frame;
		bool rSucess = cap.read(frame);

		if (!rSucess)
		{
			std::cout << "不能从视频文件中读取帧" << std::endl;
			break;
		}
		else
		{
			cv::imshow("frame", frame);
		}
		waitKey(30);
	}
}
*/
//练习三
/*int main() {
	cv::Mat dispMat = imread("D:\\textphoto\\2.png");
	cv::Point pt;
	Point pt1;
	Point pt2;
	Rect rect;
	rect.x = 200;
	rect.y = 300;
	rect.width = 50;
	rect.height = 50;
	pt1.x = 200;
	pt1.y = 200;
	pt2.x = 300;
	pt2.y = 300;
	pt.x = 100;
	pt.y = 100;
	circle(dispMat, pt, 50, CV_RGB(255, 0, 0), 2, 8, 0);
	line(dispMat, pt1, pt2, CV_RGB(255, 0, 0), 2, 8, 0);
	rectangle(dispMat, rect, CV_RGB(255, 0, 0), 2, 8, 0);
	imshow("dispMat", dispMat);
	waitKey(0);
}*/
int main() {
	cv::Mat dispMat = imread("D:\\textphoto\\2.png");
	Mat background = Mat::zeros(Size(256, 256), CV_8UC3);
	float m = 0;
	float range[255] = {0};
	int height = dispMat.rows;
	int width = dispMat.cols;
	int sum = height * width;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			//uchar n = dispMat.ptr<uchar>(j)[i];
			int n = dispMat.at<Vec3b>(j, i)[0]*0.2989 + dispMat.at<Vec3b>(j, i)[1]*0.587 + dispMat.at<Vec3b>(j, i)[2]*0.114;
			range[n] = range[n] + 1;
		}
	
	}
	for (int k = 0;k < 255;k++) {
		float guiyi = range[k] / sum;
		cv::Point pt1;
		cv::Point pt2;
		pt1.x = k;
		pt1.y = 256;
		pt2.x = k;
		pt2.y = 256-guiyi*10000;
		
		line(background, pt1, pt2, CV_RGB(255, 0, 0), 2, 8, 0);

	cout << guiyi << endl;
	m = m + guiyi;
	}
	cout << "概率相加之和："<< endl;
	cout << m << endl;
	imshow("dispMat", dispMat);
	imshow("zhifangtu", background);
	waitKey(0);
}
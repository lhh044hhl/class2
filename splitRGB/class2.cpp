#include <iostream> 
#include <opencv2/opencv.hpp>
using namespace cv;

using namespace std;
//��ϰһ
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
//��ϰ��
/*
int main() {
	VideoCapture cap;

	cap.open(0);

	if (!cap.isOpened())
	{
		std::cout << "���ܴ���Ƶ�ļ�" << std::endl;
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
			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
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
//��ϰ��
int main() {
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
}
#include<iostream>
#include<opencv2/opencv.hpp>
#include<functional>

typedef std::function<double(double)> Function;

const double C = 255.0 / log(256.0);

double LogTransform(double x)
{
	return C*log(1.0+x);
}

cv::Mat ApplyTransf(Function f, const cv::Mat& src)
{
	cv::Mat result;
	src.convertTo(result, CV_64F);
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
		{
			result.at<double>(i,j) = f(result.at<double>(i, j));
		}
	result.convertTo(result, CV_8UC1);
	
	return result;
}

int main()
{
	unsigned char data[] =
	{
		10, 30,  80, 150,
		140, 210, 90, 80,
		230, 60, 40, 70
	};

	cv::Mat img(3, 4, CV_8UC1, data);
	cv::Mat imgAdd50 = img + 50;
	cv::Mat imgLog = ApplyTransf(LogTransform, img);

	std::cout << imgAdd50 << std::endl;
	std::cout << imgLog << std::endl;



	std::cin.get();

	return 0;
}
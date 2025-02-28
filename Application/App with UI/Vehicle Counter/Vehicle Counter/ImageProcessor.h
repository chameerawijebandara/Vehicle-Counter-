#pragma once

#include <opencv2\highgui\highgui.hpp>
#include <vector>

class ImageProcessor
{
public:
	ImageProcessor();
	ImageProcessor::ImageProcessor(std::string sInputFileName, std::string sOutputFileName, std::string sOutputFileNameTxt, int iStartHour, int iStartMinute, int iStartSecond, int iNoLanes);

	bool Ismoving(cv::Mat previous, cv::Mat current);
	void Show_Avg(cv::Mat image, cv::Mat B_image);	//not used
	bool Ischanged(cv::Mat previous, cv::Mat current);
	int Find_CG(cv::Mat Binary_image);	//not used
	int Start();
	bool MarkTrackers();
	void saveResults(int start_h,int start_min,int start_second);

	/*These detail will taken from rectangles drawn by*/
	static int *w;			// width of the rect
	static int	*h;			// hieght of the rect
	static int	*x_cord;     // X cord of first point
	static int *y_cord;     // Y cord of first point

	bool *Moving_flag; // Flag will be true if something is moving in respective Lane
	bool *Man_Move;		//not used

	static cv::Mat temp;
	static cv::Mat previous;

	static bool temp_flag;
	static bool proccess_start;	// Flag will be true after proccess start
	static bool Isclicked;
	static bool Isclicked2;
	static bool First_mouse_click_done;
	static bool isVideoRun;
	static bool isVideoOut;
	static bool isVideoShow;
	static std::string currentVideo;
	static int totFrams;
	static int currentFrame;

	static int Lane;			// Current Lane number wich the proccess is doing

	/* NOT USED*/
	static class RGB
	{
	public: int R, G, B;
	};

	static class CG
	{
	public: int Last_x,
			Current_x,
			Distance;
	};

private:
	cv::Point rook_points[5];	// 5 points To draw filled pollygonal to show Lane counts
	cv::Mat image, crop;
	
	int Number_Of_Vehicles;	//Vehicle count
	std::vector<std::vector<int>> Lane_count;

	/* NOT USED*/
	RGB *Colours;	
	CG *Move_Along_X;

	int Start_Hour;
	int Start_Minute;
	int Start_Second;
	int curentTimeBlock;

	int No_Lanes;
	std::string inputFileName;
	std::string outputFileName;
	std::string outputFileNameTxt;
	
};


#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
//#include <iostream>
//#include <iostream>
//#include <string>
using namespace System;
class Player
{
private:
	bool stop;
	cv::Mat frame;
	int frameRate;
	char codec_string[5] = "H264";
	int codec;
	cv::VideoCapture capture;
	cv::VideoWriter video_write;
	cv::Mat RGBframe;
	int frame_width;
	int frame_height;
	//String outputFileName;
	//String URL;
	//Signal to output frame to be displayed
protected:
	void run();
	void msleep(int ms);
public:
	//Constructor
	//Player(QObject *parent = 0);
	//Destructor
	~Player();
	//Load a video from memory
	bool loadVideo(System::String^ filename);
	//Play the video
	void Play();
	//stat recording video
	void Record();
	void setOutputFileName(System::String^ filename);
	//Stop the video
	void Stop();
	//check if the player has been stopped
	bool isStopped() const;
};
#endif // VIDEOPLAYER_H

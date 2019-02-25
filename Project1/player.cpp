#include "player.h"


bool Player::loadVideo(System::String^ filename) {
	
	//capture.open(filename->ToString);
	if (capture.isOpened())
	{
		frameRate = (int)capture.get(cv::CAP_PROP_FPS);
		frame_width = capture.get(cv::CAP_PROP_FRAME_WIDTH);
		frame_height = capture.get(cv::CAP_PROP_FRAME_HEIGHT);
		codec = cv::VideoWriter::fourcc(codec_string[0], codec_string[1], codec_string[2], codec_string[3]);
		//video_write = VideoWriter(outputFileName, codec, 25, Size(frame_width, frame_height));
		return true;
	}
	else
		return false;
}
void Player::Play()
{

}

void Player::run()
{
	int delay = (1000 / frameRate);
	while (!stop) {
		if (!capture.read(frame))
		{
			stop = true;
		}
		if (!frame.empty() && frame.channels() == 3) {
			video_write.write(frame);
			cv::cvtColor(frame, RGBframe, cv::COLOR_BGR2RGB);
			//img = QImage((const unsigned char*)(RGBframe.data), RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
		}
		else
		{
			//img = QImage((const unsigned char*)(frame.data), frame.cols,frame.rows,QImage::Format_Indexed8);
		}
		//emit processedImage(img);
		//this->msleep(delay);
	}
}

Player::~Player()
{
	//    mutex.lock();
	stop = true;
	capture.release();
	video_write.release();
	//condition.wakeOne();
	//mutex.unlock();
	//wait();
}
void Player::Stop()
{
	stop = true;
}
void Player::msleep(int ms) {
	//struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
	//nanosleep(&ts, NULL);
}
bool Player::isStopped() const {
	return this->stop;
}
void Player::setOutputFileName(System::String^ filename) {
	//filename.copy(outputFileName);
	//outputFileName = filename;
}

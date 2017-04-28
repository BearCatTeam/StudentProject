#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include <geometry_msgs/Point.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <time.h>
//////////////////////////////////
using namespace std;
using namespace cv;
//////////////////////////////////
#define MAX_FACE_SIZE 30
#define BAUDRATE B9600
CascadeClassifier face_cascade;
String faceCascadeFile = "/home/quan/hri_ws/src/face_detector/data/haarcascade_frontalface_alt.xml";
FILE *Arduino;
int fileDescriptor;
struct termios newtio;
//////////////////////////////////
void image_receiver_cb(const sensor_msgs::ImageConstPtr& msg);
/////////////////////////////////
int main(int argc, char **argv)
{
	ros::init(argc, argv, "face_detector_node");
	
	fileDescriptor = open("/dev/ttyACM0",O_RDWR|O_NOCTTY);
	bzero(&newtio, sizeof(newtio));
    newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;

    // set to 8N1
    newtio.c_cflag &= ~PARENB;
    newtio.c_cflag &= ~CSTOPB;
    newtio.c_cflag &= ~CSIZE;
    newtio.c_cflag |= CS8;

    newtio.c_iflag = IGNPAR;

    // output mode to
    //newtio.c_oflag = 0;
    newtio.c_oflag |= OPOST;

    /* set input mode (non-canonical, no echo,...) */
    newtio.c_lflag = 0;

    newtio.c_cc[VTIME] = 10; /* inter-character timer 1 sec */
    newtio.c_cc[VMIN] = 0; /* blocking read disabled  */

    tcflush(fileDescriptor, TCIFLUSH);
    if (tcsetattr(fileDescriptor, TCSANOW, &newtio)) {
        perror("could not set the serial settings!");
        return -99;
    }
	
	if (!face_cascade.load(faceCascadeFile)) { 
		printf("--(!)Error loading\n"); 
		return -1; 
	}
	ros::NodeHandle nh;
   	cv::namedWindow("image_viewer");
   	cv::startWindowThread();
   	image_transport::ImageTransport it(nh);
   	image_transport::Subscriber sub = it.subscribe("/camera/rgb/image_raw", 1, image_receiver_cb);
   	ros::spin();
   	cv::destroyWindow("image_viewer");
	ROS_INFO("cam_tested !");
}
//////////////////////////////////
void image_receiver_cb(const sensor_msgs::ImageConstPtr& msg)
{
	cv::Mat colorI, grayI;
	std::vector<Rect> faces; 
	Point faceCenter, imageCenter;
	String message;
	try
	{
   		colorI = cv_bridge::toCvShare(msg, "bgr8")->image;
   		imageCenter = Point(colorI.size().width/2, colorI.size().height/2);
    	cvtColor(colorI, grayI, CV_RGB2GRAY);
    	face_cascade.detectMultiScale(grayI, faces, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(MAX_FACE_SIZE, MAX_FACE_SIZE));
    	if (!faces.empty())
    	{
    		faceCenter = Point(faces[0].x + faces[0].width*0.5, faces[0].y + faces[0].height*0.5);
    		ellipse(colorI, faceCenter, Size(faces[0].width*0.5, faces[0].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
    		ellipse(colorI, faceCenter, Size(1, 1), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
    		if (((faceCenter.x - imageCenter.x)*(faceCenter.x - imageCenter.x)) + ((faceCenter.y - imageCenter.y)*(faceCenter.y - imageCenter.y)) > 400) {
				message = "";
				if ((faceCenter.x - imageCenter.x) > 10) {
					message += "r";
				}
				else if ((faceCenter.x - imageCenter.x) < -10) {
					message += "l";
				}
				else {
					message += "n";
				}
				if ((faceCenter.y - imageCenter.y) > 10) {
					message += "d";
				}
				else if ((faceCenter.y - imageCenter.y) < -10) {
					message += "u";
				}
				else {
					message += "n";
				}
				long wrote = write(fileDescriptor, message.c_str(), sizeof(char)*message.size());
    		}
    	}
		circle(colorI, imageCenter, 20, Scalar(0, 255, 255), 4, 8, 0);
    	cv::imshow("image_viewer", colorI);
   	}
   	catch (cv_bridge::Exception& e)
   	{	
    	cout << "ERROR: Could not convert from '%s' to 'bgr8'." << endl;
   	}
}
///////////////////////////
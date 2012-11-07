#include "opencv2\opencv.hpp"
#include <iostream>
using namespace std;
int main(void)
{
	char key;
	IplImage* image;
	cvNamedWindow( "Example", CV_WINDOW_AUTOSIZE );
	CvCapture* capture;
	if((capture = cvCreateCameraCapture ( 0 ))==0){
		cout<<"ERROR: NO CAMERAS DETECTED."<<endl;
		return 0;
	}
	while(1){
		if((image = cvQueryFrame( capture ))==0){
			cout<<"ERROR: BAD FRAME!"<<endl;
			return 0;
		}
		cvShowImage( "Example", image );
		key=cvWaitKey(10);
				if( key == 27 ) {
					cout << "Exiting on KEY: " << key << endl;
					break;
				}
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow( "Example" );
	return 0;
}

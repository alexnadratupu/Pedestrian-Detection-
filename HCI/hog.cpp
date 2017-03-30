#include <boost/lexical_cast.hpp>
#include "opencv2/objdetect/objdetect.hpp"
 #include "opencv2/highgui/highgui.hpp"
 #include "opencv2/imgproc/imgproc.hpp"

 #include <iostream>
 #include <stdio.h>
#include<string>
 using namespace std;
 using namespace cv;

 
 void detectAndDisplay( Mat frame );// function for detectscale 


 String face_cascade_name = "hogcascade_pedestrians.xml"; // loading the.xml file for pedstrain detection 
 CascadeClassifier face_cascade;
 RNG rng(12345);

 //Main function 
 int main( int argc, const char** argv )
 {

for(int num=1;num<11;num++) // loop for displaying 10 images 
{
std::string str = boost::lexical_cast<std::string>(num);
std::string first ("ped");
std::string final;
std::string third ("jpg");
final= first +str+'.'+ third; // final string to give as input string dynamically 


// loading the cascades 
   if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };  
	Mat image =imread(final, CV_LOAD_IMAGE_UNCHANGED);	   

   if(! image.data )                              // Checking for images
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }  
   
  std::vector<Rect> faces;
  Mat frame_gray;

  cvtColor( image, frame_gray, CV_BGR2GRAY );
  equalizeHist( frame_gray, frame_gray );

  //-- Detect faces
  face_cascade.detectMultiScale( frame_gray, faces, 1.5, 1, 0|CV_HAAR_SCALE_IMAGE, Size(30, 76) );
  for( size_t i = 0; i < faces.size(); i++ )
  {
		Point pt1( faces[i].x + faces[i].width*1, faces[i].y + faces[i].height);
		   Point pt2( faces[i].x, faces[i].y);
	
	    rectangle( image,  pt1, pt2, Scalar(350,2,8,2));

    }

  //displaying the images after rectangulars drawn 
cout << "showing Image "; std::cout<<final<<'\n'; 
     namedWindow("DisplayWindow", CV_WINDOW_AUTOSIZE); // naming windows 
	imshow("DisplayWindow", image); //display the image which is stored in 'img' in the "DisplayWindow" window
	waitKey(0); //waitkey for time for image to display
 	destroyWindow("DisplayWindow"); //closing the window 

}
  return 0; 



 }

	
	
	
	
	
	
 
	     

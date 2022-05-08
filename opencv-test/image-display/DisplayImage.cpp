#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat img_color = imread( argv[1], IMREAD_COLOR );
    Mat img_gray = imread( argv[1], IMREAD_GRAYSCALE );
    Mat img_org = imread( argv[1], IMREAD_UNCHANGED );
    if ( !img_color.data )
    {
        printf("No image data \n");
        return -1;
    }
    // Create a window.
    namedWindow( "color image", WINDOW_AUTOSIZE );
    namedWindow( "grayscale image", WINDOW_AUTOSIZE );
    namedWindow( "unchanged image", WINDOW_AUTOSIZE );

    // Show the image inside it.
    imshow( "color image", img_color ); 
    imshow( "grayscale image", img_gray );
    imshow( "unchanged image", img_org ); 

    // Wait for a keystroke.   
    waitKey(0);  

    // Destroys all the windows created                         
    destroyAllWindows();
    return 0;
}
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
using namespace cv;
using namespace std;
int main()
{
    // Load the video file
    VideoCapture cap("Cars.mp4");

    // Load the car classifier XML file
    CascadeClassifier car_cascade;
    car_cascade.load("cars.xml");

    // If the video is not opened
    if (!cap.isOpened())
    {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }
    //detect cars and count number of cars in the video
    
    int count = 0;
    while (1)
    {
        Mat frame;
        // Capture frame-by-frame
        cap >> frame;

        // If the frame is empty, break immediately
        if (frame.empty())
            break;

        // Detect cars in the frame
        vector<Rect> cars;
        car_cascade.detectMultiScale(frame, cars, 1.1, 1, 0, Size(70, 70), Size(200, 200));

        // Draw rectangles around the cars
        for (Rect car : cars)
        {
            rectangle(frame, car, Scalar(255, 0, 0), 2);
        }

        // Display the resulting frame
        imshow("Frame", frame);

        // Press 27 to exit the loop
        if (waitKey(1) == 27)
            break;

        // Count the number of cars
        count += cars.size();
    }

    // When everything done, release the video capture object
    cap.release();

    // Print the number of cars
    cout << "Number of cars: " << count << endl;



    return 0;
}



Task: Develop a program in C++ to detect cars in a video using OpenCV. The program should count the number of cars in the video and display the total count. The program should use the car classifier XML file provided and the video file "Cars.mp4" for testing. The program should display the video with rectangles drawn around the detected cars and exit when the user presses the "Esc" key. The program should output the total number of cars detected in the video.


Steps completed:
1. Loaded the video file "Cars.mp4" using the VideoCapture class.
2. Loaded the car classifier XML file "cars.xml" using the CascadeClassifier class.
3. Implemented a while loop to read frames from the video and detect cars in each frame.
4. Used the detectMultiScale function to detect cars in the frame.
5. Drawn rectangles around the detected cars using the rectangle function.
6. Displayed the resulting frame with rectangles drawn around the cars.
7. Implemented a condition to exit the loop when the user presses the "Esc" key.
8. Counted the number of cars detected in the video by summing the sizes of the cars vector.
9. Released the video capture object after processing all frames.
10. Printed the total number of cars detected in the video.

Code with Proper Comments:

Sample Inputs and Outputs:

Input:

A video file "Cars.mp4" containing footage of cars on the road.
The car classifier XML file "cars.xml" for detecting cars in the video.

Output:

The program displays the video with rectangles drawn around the detected cars.
The program exits when the user presses the "Esc" key.
The program outputs the total number of cars detected in the video.

Number of cars: 26





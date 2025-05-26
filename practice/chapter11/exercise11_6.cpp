# include "stones.h"

int main()
{
    Stonewt arr[6] = {
        Stonewt(10, 5.5),
        Stonewt(12, 3.2),
        Stonewt(8, 0.0)
    };
    Stonewt standar (11,0); // 11 pounds
    Stonewt max = arr[0];
    // Initialize min with the first element
    Stonewt min = arr[0];
    std::cout <<"Please enter the last three weights in pounds (e.g., 12.5):\n";
    double pounds;
    int i = 3; // start from the fourth element
    int count = 0; 
    while (i < 6 && std::cin >> pounds && pounds >= 0) {
        std::cout << "You entered: " << pounds << " pounds.\n";
        arr[i] = Stonewt(pounds);
        i++;
    }
    for (size_t i = 0; i < 6; i++)
    {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] >= standar)    
             count++;
    }
    std::cout << "The maximum weight is: " << max;
    std::cout << "The minimum weight is: " << min;
    standar.set_mode(Stonewt::STONES); // set the mode to POUNDS_FLT for output
    std::cout << "The number of weights greater than or equal to " << standar << " is: " << count;

    return 0;
}
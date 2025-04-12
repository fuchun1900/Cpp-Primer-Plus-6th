//
// Created by Shujia Huang on 2/9/22.
//
#include <iostream>

typedef struct {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
} Box;

void modify_box_ptr(Box * box);
void show_box(Box box);

int main()
{
    using namespace std;
    Box box1 = {"Box1", 10.0, 20.0, 30.0, 0.0};
    Box box2 = {"Box2", 15.0, 25.0, 35.0, 0.0};
    Box box3 = {"Box3", 20.0, 30.0, 40.0, 0.0};

    modify_box_ptr(&box1);
    modify_box_ptr(&box2);
    show_box(box1);
    show_box(box2);

    return 0;
}
void modify_box_ptr(Box * box)
{
    using namespace std;
    box->volume = box->height * box->width * box->length; 
}
void show_box(Box box)
{
    using namespace std;
    cout << "Maker: " << box.maker << endl;
    cout << "Height: " << box.height << endl;
    cout << "Width: " << box.width << endl;
    cout << "Length: " << box.length << endl;
    cout << "Volume: " << box.volume << endl;
    cout << "------------------------" << endl; 
}

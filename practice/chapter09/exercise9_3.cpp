#include <iostream>
#include <cstring>

struct chaff
{
    char dross[20];
    int slag;

};

void showChaff(const chaff &ch)
{
    std::cout << "Dross: " << ch.dross << std::endl;
    std::cout << "Slag: " << ch.slag << std::endl;
}

int setChaff(chaff &ch, const char *dross, int slag)
{
    if (strlen(dross) > 0 && strlen(dross) < 20)
    {
        strcpy(ch.dross, dross);
        ch.slag = slag;
        return 1;
    }
    else
    {
        std::cerr << "Error: dross must be between 1 and 19 characters." << std::endl;
        return 0;
    }
}

int main()
{
    using std::cout;
    using std::endl;

    char * buffer = new char[sizeof(chaff) * 10]; // buffer for two chaff objects
    chaff *pChaff = new(buffer) chaff[2]; // placement new to create two chaff objects in buffer
    // set values for the first chaff object
    for (size_t i = 0; i < 2; i++)
    {
        cout << "Enter dross for chaff object " << i + 1 << ": ";
        char dross[20];
        std::cin.getline(dross, 20);
        int slag;
        cout << "Enter slag for chaff object " << i + 1 << ": ";
        while (!(std::cin >> slag) || slag < 0)
        {
            std::cin.clear(); // clear the error flag
            while (std::cin.get() != '\n') // discard invalid input
                continue;
            cout << "Please enter a positive integer: ";
        }
        std::cin.ignore(); // discard the newline character left in the input buffer
        setChaff(pChaff[i], dross, slag);
    }
    // display the values of the chaff objects
    for (size_t i = 0; i < 2; i++)
    {
        cout << "Chaff object " << i + 1 << ":" << endl;
        showChaff(pChaff[i]);
    }
    
    delete[] buffer; // free the allocated memory


    return 0;
}

// bank.cpp -- using the Queue interface
// compile with queue.cpp
// modified by fuchun
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "/home/DEV/C++_Project/Cpp-Primer-Plus-6th/bookcodes/chapter12/queue.h"
const int MIN_PER_HR = 60;
const int MIN_SIM_HOURS = 1500;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
// setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs);         // line 1 queue holds up to qs people
    Queue line2(qs);         // line 2 queue holds up to qs people

    cout << "Enter the number of simulation hours: ";
    int hours = MIN_SIM_HOURS;             //  hours of simulation
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles
    double perhour = 10;         //  average man of arrival per hour
    double min_per_cust;    // average time between arrivals
    Item temp;
    long turnaways;     //  turned away by full queue
    long Customers, customers1 ,customers2;    //  joined the queue
    long served ;        //  served during the simulation
    long sum_line1, sum_line2;      //  cumulative line length
    int wait_time1 , wait_time2;     //  time until autoteller is free
    long line_wait;
    double average_wait = 0;

    while (average_wait < 1)
    {
        turnaways = 0;
        Customers = customers1 = customers2 = 0;
        served = 0;
        sum_line1 = sum_line2 = 0;
        wait_time1 = wait_time2 = 0;
        line_wait = 0;
        perhour ++;
        min_per_cust = MIN_PER_HR / perhour;
        while (!line1.isempty())
            line1.dequeue(temp);
        while (!line2.isempty())
            line2.dequeue(temp);
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))  // have newcomer
            {
                if (line1.isfull() && line2.isfull())
                    turnaways++;
                else
                {
                    Customers++;
                    temp.set(cycle);    // cycle = time of arrival
                    if (line1.queuecount() <= line2.queuecount())
                    {
                        customers1++;
                        line1.enqueue(temp); // add newcomer to line 1
                    }
                    else
                    {
                        customers2++;
                        line2.enqueue(temp); // add newcomer to line 2
                    }
                }
            }
            if (wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue (temp);      // attend next customer
                wait_time1 = temp.ptime(); // for wait_time minutes
                line_wait += cycle - temp.when();
                served++;
            }
            sum_line1 += line1.queuecount();
            if (wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue (temp);      // attend next customer
                wait_time2 = temp.ptime(); // for wait_time minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time2 > 0)
                wait_time2--;
            sum_line2 += line2.queuecount();
        }
        average_wait = (double) line_wait / served;

// reporting results
        if (average_wait < 1)
        {
            if (Customers > 0)
            {
                cout << "customers accepted: " << Customers << endl;
                cout << "  customers served: " << served << endl;
                cout << "         turnaways: " << turnaways << endl;
                cout << "average queue size: ";
                cout.precision(2);
                cout.setf(ios_base::fixed, ios_base::floatfield);
                cout << (double) (sum_line1 + sum_line2) / cyclelimit << endl;
                cout << " average wait time: "
                    << (double) line_wait / served << " minutes\n";
            }
            else
                cout << "No customers!\n";
        }
    }
    cout <<"----------------------------------------\n";
    cout << "\nFinal result when average wait >= 1:\n";
    cout << "customers accepted: " << Customers << endl;
    cout << " customers served: " << served << endl;
    cout << " turnaways: " << turnaways << endl;
    cout << "average queue size: ";
    cout.precision(2);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << (double) (sum_line1 + sum_line2) / cyclelimit << endl;
    cout << " average wait time: "
        << (double) line_wait / served << " minutes\n";

    cout << "Done!\n";
    // cin.get();
    // cin.get();
    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1); 
}

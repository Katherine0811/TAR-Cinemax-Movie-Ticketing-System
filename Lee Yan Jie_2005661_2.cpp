// Assignment

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int movie_name();                        // logo, movie name, date
int movie_time(string& ticket_time);     // input time preffered
void information();                      // seat displaying, price table
int movie_class();                       // input seating class
void limited();                          // quantity of tickets is not enough
void payment_method(double total_pay);   // proceed payment method
int movie_qty(int& senior, int& adult, int& child, int& student);  // input quantity of tickets
void seat_occupancy_seven(int M1T1C1, int M1T1C2, int M1T1C3, int M2T1C1, int M2T1C2, int M2T1C3, int M3T1C1, int M3T1C2, int M3T1C3);
void seat_occupancy_eight(int M1T2C1, int M1T2C2, int M1T2C3, int M2T2C1, int M2T2C2, int M2T2C3, int M3T2C1, int M3T2C2, int M3T2C3);
void category_sales(
    int senior_one, int senior_two, int senior_three, double price_senior_one, double price_senior_two, double price_senior_three,
    int adult_one, int adult_two, int adult_three, double price_adult_one, double price_adult_two, double price_adult_three,
    int child_one, int child_two, int child_three, double price_child_one, double price_child_two, double price_child_three,
    int student_one, int student_two, int student_three, double price_student_one, double price_student_two, double price_student_three);

int main()
{
    char value;
    int M1T1C1, M1T1C2, M1T1C3, M1T2C1, M1T2C2, M1T2C3, M2T1C1, M2T1C2, M2T1C3,
        M2T2C1, M2T2C2, M2T2C3, M3T1C1, M3T1C2, M3T1C3, M3T2C1, M3T2C2, M3T2C3;
    M1T1C1 = M1T1C2 = M1T1C3 = M1T2C1 = M1T2C2 = M1T2C3 = M2T1C1 = M2T1C2 = M2T1C3 = 30;
    M2T2C1 = M2T2C2 = M2T2C3 = M3T1C1 = M3T1C2 = M3T1C3 = M3T2C1 = M3T2C2 = M3T2C3 = 30;
    int input_qty, count, name, time, input_class, ticket_class, a = 0, b = 0,
        senior, senior_one = 0, senior_two = 0, senior_three = 0,
        adult, adult_one = 0, adult_two = 0, adult_three = 0,
        child, child_one = 0, child_two = 0, child_three = 0,
        student, student_one = 0, student_two = 0, student_three = 0;
    int price[3][4] = {
        {14, 18, 9, 14},
        {16, 20, 10, 16},
        {20, 26, 13, 20} };
    double price_senior, senior_unit, price_senior_one = 0, price_senior_two = 0, price_senior_three = 0,
        price_adult, adult_unit, price_adult_one = 0, price_adult_two = 0, price_adult_three = 0,
        price_child, child_unit, price_child_one = 0, price_child_two = 0, price_child_three = 0,
        price_student, student_unit, price_student_one = 0, price_student_two = 0, price_student_three = 0,
        ticket_pay, tax, total_pay, cash_payment;
    string ticket_name, ticket_time, category;
    string Seat_M1T1C1[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M1T1C2[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M1T1C3[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M1T2C1[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M1T2C2[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M1T2C3[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M2T1C1[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M2T1C2[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M2T1C3[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M2T2C1[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M2T2C2[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M2T2C3[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M3T1C1[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M3T1C2[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M3T1C3[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M3T2C1[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M3T2C2[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
    string Seat_M3T2C3[3][10] = {
        {"01","02","03","04","05","06","07","08","09","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"} };
restart:
    name = movie_name();
    cout << "\n";                              // display time, class available 
    cout << "   ----------------------------------------------------------------------------------------------\n";
    cout << "   |    Showing Time    |           (1)  7:00 pm            |            (2)  8:00 pm           |\n";
    cout << "   |--------------------|-----------------------------------|-----------------------------------|\n";
    cout << "   |    Movies Name     |  Class 1  |  Class 2  |  Class 3  |  Class 1  |  Class 2  |  Class 3  |\n";
    cout << "   |--------------------|-----------|-----------|-----------|-----------|-----------|-----------|\n";
    // showcase remaining seats available----------------------------------------------------------------------------------------------------------

    cout << "   | Marvel Avenger     |  " << setw(7) << M1T1C1 << "  |  " << setw(7) << M1T1C2 << "  |  " << setw(7) << M1T1C3
        << "  |  " << setw(7) << M1T2C1 << "  |  " << setw(7) << M1T2C2 << "  |  " << setw(7) << M1T2C3 << "  |\n";

    cout << "   | Beauty & the beast |  " << setw(7) << M2T1C1 << "  |  " << setw(7) << M2T1C2 << "  |  " << setw(7) << M2T1C3
        << "  |  " << setw(7) << M2T2C1 << "  |  " << setw(7) << M2T2C2 << "  |  " << setw(7) << M2T2C3 << "  |\n";

    cout << "   | Zootopia 2         |  " << setw(7) << M3T1C1 << "  |  " << setw(7) << M3T1C2 << "  |  " << setw(7) << M3T1C3
        << "  |  " << setw(7) << M3T2C1 << "  |  " << setw(7) << M3T2C2 << "  |  " << setw(7) << M3T2C3 << "  |\n";

    cout << "   ----------------------------------------------------------------------------------------------\n";
    time = movie_time(ticket_time);
    information();
    input_class = movie_class();
    input_qty = movie_qty(senior, adult, child, student);
    // prompt user choose seating for all tickets -------------------------------------------------------------------------------------------------- 
    count = 0;    // To count seats to be choosen
    int seat_no[31] = { 0 };
    a = 0;
    cout << "\n";
    if (name == 1)
    {
        if (time == 1)
        {
            if (input_class == 1)  // Movie_1 Time_1 Class_1
            {
                if (input_qty <= M1T1C1)
                {
                    int row, col, seat, x, y;
                    M1T1C1 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M1T1C1[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M1T1C1[x][y] != "__")
                        {
                            Seat_M1T1C1[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_1;
                }
            }
            else if (input_class == 2)  // Movie_1 Time_1 Class_2
            {
                if (input_qty <= M1T1C2)
                {
                    int row, col, seat, x, y;
                    M1T1C2 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M1T1C2[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M1T1C2[x][y] != "__")
                        {
                            Seat_M1T1C2[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_2;
                }
            }
            else if (input_class == 3) // Movie_1 Time_1 Class_3
            {
                if (input_qty <= M1T1C3)
                {
                    int row, col, seat, x, y;
                    M1T1C3 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M1T1C3[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M1T1C3[x][y] != "__")
                        {
                            Seat_M1T1C3[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_3;
                }
            }
        }
        else if (time == 2)
        {
            if (input_class == 1)  // Movie_1 Time_2 Class_1
            {
                if (input_qty <= M1T2C1)
                {
                    int row, col, seat, x, y;
                    M1T2C1 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M1T2C1[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M1T2C1[x][y] != "__")
                        {
                            Seat_M1T2C1[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_1;
                }
            }
            else if (input_class == 2)  // Movie_1 Time_2 Class_2
            {
                if (input_qty <= M1T2C2)
                {
                    int row, col, seat, x, y;
                    M1T2C2 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M1T2C2[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M1T2C2[x][y] != "__")
                        {
                            Seat_M1T2C2[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_2;
                }
            }
            else if (input_class == 3)  // Movie_1 Time_2 Class_3
            {
                if (input_qty <= M1T2C3)
                {
                    int row, col, seat, x, y;
                    M1T2C3 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M1T2C3[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M1T2C3[x][y] != "__")
                        {
                            Seat_M1T2C3[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_3;
                }
            }
        }
    }
    else if (name == 2)
    {
        if (time == 1)
        {
            if (input_class == 1)  // Movie_2 Time_1 Class_1
            {
                if (input_qty <= M2T1C1)
                {
                    int row, col, seat, x, y;
                    M2T1C1 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M2T1C1[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M2T1C1[x][y] != "__")
                        {
                            Seat_M2T1C1[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_1;
                }
            }
            else if (input_class == 2)  // Movie_2 Time_1 Class_2
            {
                if (input_qty <= M2T1C2)
                {
                    int row, col, seat, x, y;
                    M2T1C2 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M2T1C2[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M2T1C2[x][y] != "__")
                        {
                            Seat_M2T1C2[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_2;
                }
            }
            else if (input_class == 3)  // Movie_2 Time_1 Class_3
            {
                if (input_qty <= M2T1C3)
                {
                    int row, col, seat, x, y;
                    M2T1C3 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M2T1C3[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M2T1C3[x][y] != "__")
                        {
                            Seat_M2T1C3[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_3;
                }
            }
        }
        else if (time == 2)
        {
            if (input_class == 1)  // Movie_2 Time_2 Class_1
            {
                if (input_qty <= M2T2C1)
                {
                    int row, col, seat, x, y;
                    M2T2C1 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M2T2C1[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M2T2C1[x][y] != "__")
                        {
                            Seat_M2T2C1[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_1;
                }
            }
            else if (input_class == 2)  // Movie_2 Time_2 Class_2
            {
                if (input_qty <= M2T2C2)
                {
                    int row, col, seat, x, y;
                    M2T2C2 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M2T2C2[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M2T2C2[x][y] != "__")
                        {
                            Seat_M2T2C2[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_2;
                }
            }
            else if (input_class == 3)  // Movie_2 Time_2 Class_3
            {
                if (input_qty <= M2T2C3)
                {
                    int row, col, seat, x, y;
                    M2T2C3 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M2T2C3[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M2T2C3[x][y] != "__")
                        {
                            Seat_M2T2C3[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_3;
                }
            }
        }
    }
    else if (name == 3)
    {
        if (time == 1)
        {
            if (input_class == 1)  // Movie_3 Time_1 Class_1
            {
                if (input_qty <= M3T1C1)
                {
                    int row, col, seat, x, y;
                    M3T1C1 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M3T1C1[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M3T1C1[x][y] != "__")
                        {
                            Seat_M3T1C1[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_1;
                }
            }
            else if (input_class == 2)  // Movie_3 Time_1 Class_2
            {
                if (input_qty <= M3T1C2)
                {
                    int row, col, seat, x, y;
                    M3T1C2 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M3T1C2[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M3T1C2[x][y] != "__")
                        {
                            Seat_M3T1C2[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_2;
                }
            }
            else if (input_class == 3)  // Movie_3 Time_1 Class_3
            {
                if (input_qty <= M3T1C3)
                {
                    int row, col, seat, x, y;
                    M3T1C3 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M3T1C3[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M3T1C3[x][y] != "__")
                        {
                            Seat_M3T1C3[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_3;
                }
            }
        }
        else if (time == 2)
        {
            if (input_class == 1)  // Movie_3 Time_2 Class_1
            {
                if (input_qty <= M3T2C1)
                {
                    int row, col, seat, x, y;
                    M3T2C1 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M3T2C1[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M3T2C1[x][y] != "__")
                        {
                            Seat_M3T2C1[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_1;
                }
            }
            else if (input_class == 2)  // Movie_3 Time_2 Class_2
            {
                if (input_qty <= M3T2C2)
                {
                    int row, col, seat, x, y;
                    M3T2C2 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M3T2C2[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M3T2C2[x][y] != "__")
                        {
                            Seat_M3T2C2[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_2;
                }
            }
            else if (input_class == 3)  // Movie_3 Time_2 Class_3
            {
                if (input_qty <= M3T2C3)
                {
                    int row, col, seat, x, y;
                    M3T2C3 -= input_qty;
                    while (count < input_qty)
                    {
                        cout << "**************************************************************\n";
                        for (row = 0; row < 3; row++)
                        {
                            cout << "  __    __    __    __    __    __    __    __    __    __ \n";
                            for (col = 0; col < 10; col++)
                                cout << " |" << Seat_M3T2C3[row][col] << "| ";
                            cout << "\n";
                        }
                        cout << "\n";
                        cout << "   Enter the seat number u would like to book : ";
                        cin >> seat;
                        while (!cin || (seat < 1) || (seat > 30))
                        {
                            cout << "   Invalid Input, Please re-enter : ";
                            cin.clear();
                            cin.ignore();
                            cin >> seat;
                        }
                        x = (seat - 1) / 10;
                        y = (seat - 1) % 10;
                        if (Seat_M3T2C3[x][y] != "__")
                        {
                            Seat_M3T2C3[x][y] = { "__" };
                            cout << "   booking success ! \n";
                            seat_no[a] = seat;
                            a++;
                            count++;
                        }
                        else
                            cout << "   Sorry, This seat is booked. \n";
                        cout << "   Remainding seats booking : " << (input_qty - count) << endl;
                        cout << "\n";
                    }
                    goto payment_3;
                }
            }
        }
    }
unavailable:
    limited();   // There is not enough seat for the patrons
    cin >> value;
    system("cls");
    goto restart;
payment_1:       // Calculating Bill for Class 1
    ticket_class = 1;
    senior_unit = 14;
    adult_unit = 18;
    child_unit = 9;
    student_unit = 14;
    goto bill;
payment_2:       // Calculating Bill for Class 2
    ticket_class = 2;
    senior_unit = 16;
    adult_unit = 20;
    child_unit = 10;
    student_unit = 16;
    goto bill;
payment_3:       // Calculating Bill for Class 3
    ticket_class = 3;
    senior_unit = 20;
    adult_unit = 26;
    child_unit = 13;
    student_unit = 20;
    goto bill;
bill:       // Bill Calculator
    price_senior = senior * senior_unit;
    price_adult = adult * adult_unit;
    price_child = child * child_unit;
    price_student = student * student_unit;
    ticket_pay = price_senior + price_adult + price_child + price_student;
    tax = ticket_pay * 0.06;
    total_pay = ticket_pay + tax;

    // Display Order Summary ---------------------------------------------------------------------------------------------------------------------
    cout << fixed << setprecision(2) << endl;
    cout << "          ***************************************************************\n";
    cout << "          **                                                           **\n";
    cout << "          **-----------------------ORDER SUMMARY-----------------------**\n";
    cout << "          **   _____________________________________________________   **\n";
    cout << "          **   |------------|-------|--------------|---------------|   **\n";
    cout << "          **   |  CATEGORY  |  QTY  |  UNIT PRICE  |  TOTAL PRICE  |   **\n";
    cout << "          **   |------------|-------|--------------|---------------|   **\n";

    // Showcase customer's ordered ticket price --------------------------------------------------------------------------------------------------

    cout << "          **   |  Adults    |  " << setw(2) << adult << "   |   " << "RM " << setw(5) << adult_unit
        << "   |   " << "RM " << setw(6) << price_adult << "   |   **\n";
    cout << "          **   |  Senior C. |  " << setw(2) << senior << "   |   " << "RM " << setw(5) << senior_unit
        << "   |   " << "RM " << setw(6) << price_senior << "   |   **\n";
    cout << "          **   |  Child     |  " << setw(2) << child << "   |   " << "RM " << setw(5) << child_unit
        << "   |   " << "RM " << setw(6) << price_child << "   |   **\n";
    cout << "          **   |  Students  |  " << setw(2) << student << "   |   " << "RM " << setw(5) << student_unit
        << "   |   " << "RM " << setw(6) << price_student << "   |   **\n";

    cout << "          **   |____________|_______|______________|_______________|   **\n";
    cout << "          **   _____________________________________________________   **\n";
    cout << "          **   |-------------------------|-------------------------|   **\n";
    cout << "          **   |   Total Ticket Price    |   RM  " << setw(6) << ticket_pay << "            |   **\n";
    cout << "          **   |   Service Tax Charged   |   RM  " << setw(6) << tax << "            |   **\n";
    cout << "          **   |   Total Payment         |   RM  " << setw(6) << total_pay << "            |   **\n";
    cout << "          **   |_________________________|_________________________|   **\n";
    cout << "          **                                                           **\n";
    cout << "          ***************************************************************\n";

    // Report Data Collecting ----------------------------------------------------------------------------------------------------------------------------------------
    if (name == 1)
    {
        ticket_name = "Marvel Avenger";
        senior_one += senior;
        adult_one += adult;
        child_one += child;
        student_one += student;

        price_senior_one += price_senior;
        price_adult_one += price_adult;
        price_child_one += price_child;
        price_student_one += price_student;
    }
    else if (name == 2)
    {
        ticket_name = "Beauty & the beast";
        senior_two += senior;
        adult_two += adult;
        child_two += child;
        student_two += student;

        price_senior_two += price_senior;
        price_adult_two += price_adult;
        price_child_two += price_child;
        price_student_two += price_student;
    }
    else if (name == 3)
    {
        ticket_name = "Zootopia 2";
        senior_three += senior;
        adult_three += adult;
        child_three += child;
        student_three += student;

        price_senior_three += price_senior;
        price_adult_three += price_adult;
        price_child_three += price_child;
        price_student_three += price_student;
    }
    // Payment And Print Ticket -----------------------------------------------------------------------------------------------------------------------------------
    payment_method(total_pay);
    a = 0;
    while (seat_no[a] != 0)
    {
        if (senior != 0)
        {
            category = "Category -- Senior";
            senior--;
            b = 1;
        }
        else if (senior == 0 && adult != 0)
        {
            category = "Category -- Adult";
            adult--;
            b = 2;
        }
        else if (senior == 0 && adult == 0 && child != 0)
        {
            category = "Category -- Child";
            child--;
            b = 3;
        }
        else if (senior == 0 && adult == 0 && child == 0 && student != 0)
        {
            category = "Category -- Student";
            student--;
            b = 4;
        }
    printing:
        cout << left << setfill(' ') << endl;
        cout << "          *********************************************************\n";
        cout << "          **                     TAR CINEMAX                     **\n";
        cout << "          **  -------------------------------------------------  **\n";
        cout << "          **  " << setw(30) << ticket_name << "                     **\n";
        // for different seat number
        // for different category

        cout << "          **  " << setw(30) << "11 August 2020 (Wednesday)" << " Class    : " << ticket_class << "        **\n";
        cout << "          **  " << setw(30) << ticket_time << " Seat No. : " << ticket_class << right
            << setw(2) << setfill('0') << seat_no[a] << "      **" << left << setfill(' ') << endl;
        cout << "          **  " << setw(30) << category << " Price    : RM " << setw(6) << price[ticket_class - 1][b - 1] << "**\n";
        cout << "          **                                                     **\n";
        cout << "          *********************************************************\n";
        a++;
    }

    // Continue Selling Ticket or Display Report -------------------------------------------------------------------------------------------------------------------
next:
    cout << "                Next Customer ? (Y) Yes (N) No :";
    cin >> value;
    if (islower(value) != 0)
        value = static_cast<char>(toupper(value));
    if (value == 'Y')
    {
        system("cls");
        goto restart;
    }
    else if (value == 'N')
        goto report;
    else
        goto next;
report:
    cout << "\n";
    cout << "========================================================================================================================\n";
    cout << "\n";
    cout << "                                      *************************************** \n";
    cout << "                                      **        TICKET SALES REPORT        ** \n";
    cout << "                                      *************************************** \n";
    seat_occupancy_seven(M1T1C1, M1T1C2, M1T1C3, M2T1C1, M2T1C2, M2T1C3, M3T1C1, M3T1C2, M3T1C3);
    seat_occupancy_eight(M1T2C1, M1T2C2, M1T2C3, M2T2C1, M2T2C2, M2T2C3, M3T2C1, M3T2C2, M3T2C3);
    category_sales(
        senior_one, senior_two, senior_three, price_senior_one, price_senior_two, price_senior_three,
        adult_one, adult_two, adult_three, price_adult_one, price_adult_two, price_adult_three,
        child_one, child_two, child_three, price_child_one, price_child_two, price_child_three,
        student_one, student_two, student_three, price_student_one, price_student_two, price_student_three);
    cout << "\n";
    cout << "========================================================================================================================\n";
    cout << "\n";
    cout << "     ************************************************************************************************************ \n";
    cout << "     ************************************************************************************************************ \n";
    cout << "     **          _       _          **                                                                         ** \n";
    cout << "     **         (c).---.(c)         **         T  H  A  N  K  .  Y  O  U  .  V  E  R  Y  .  M  U  C  H         ** \n";
    cout << "     **          / . _ . \\          **                                                                         ** \n";
    cout << "     **        __\\(  Y  )/__        **            F  O  R  .  W  A  T  C  H  I  N  G  .  W  I  T  H            ** \n";
    cout << "     **       (_.-/ '-' \\-._)       **                                                                         ** \n";
    cout << "     **          ||  X  ||          **                     T  A  R  .  C  I  N  E  M  A  X                     ** \n";
    cout << "     **        _.'  '-'  '._        **                                                                         ** \n";
    cout << "     **       ( .-./'-'\\.-. )       **  ------------------------------- BROUGHT TO YOU BY : KATHERINE LEE ---  ** \n";
    cout << "     **                             **                                                                         ** \n";
    cout << "     ************************************************************************************************************ \n";
    cout << "     ************************************************************************************************************ \n";
    cout << "\n";
    cout << "========================================================================================================================\n";
    cout << "\n";
    return 0;
}
// Start Screen ---------------------------------------------------------------------------------------------------------------------------------------------------
int movie_name()
{
    int name;
    cout << "*********************************************************************************************************************** \n";
    cout << "*********************************************************************************************************************** \n";
    cout << "**   ______            ___                                  **  1. Patrons with temperature above than 37.5 are      ** \n";
    cout << "**     ||  __.  .__   /   ' ' .__   __  ._ _   __.          **     not allowed to enter even with tickets.           ** \n";
    cout << "**     || /  .\\ |  ' |      | |  \\ /__\\ | | | /  .\\ \\_/     **                                                       ** \n";
    cout << "**     || \\__/| |     \\___/ | |  | |__. | | | \\__/| / \\     **  2. Patrons must wear a face mask and practice        ** \n";
    cout << "**                                                          **     social distancing at all time.                    ** \n";
    cout << "**************************************************************                                                       ** \n";
    cout << "**************************************************************  3. Provide personal contact details upon entering    ** \n";
    cout << "**                                                          **     hall. You are encourage to use MySejahteraApp.    ** \n";
    cout << "**    Now Showing --- 11 August 2020 (Wednesday)            **                                                       ** \n";
    cout << "**                                                          **       . .  _  | |  _     __  _   _   _   _  ___       ** \n";
    cout << "**    1. Marvel Avengers : End Game                         ** _____ |_| |_| | | | |   |   |_| | | | | | |  | ______ ** \n";
    cout << "**    2. Beauty and the Beast                               **       | | |_, | | |_| o |__ | | | | | | |_|  |        ** \n";
    cout << "**    3. Zootopia 2                                         **                                                       ** \n";
    cout << "**                                                          **                               copyright by GSC Admin. ** \n";
    cout << "*********************************************************************************************************************** \n";
    cout << "*********************************************************************************************************************** \n";
movieName:
    cout << "\n";
    cout << "   Select (1 - 3) for the movie you would like to watch : ";
    cin >> name;
    while (!cin)
    {
        cout << "   Invalid input, try again. \n";
        cout << "\n";
        cout << "   Select (1 - 3) for the movie you would like to watch : ";
        cin.clear();
        cin.ignore();
        cin >> name;
    }
    if (name > 3 || name == 0)
    {
        cout << "   Invalid input, try again. \n";
        goto movieName;
    }
    return name;
}
int movie_time(string& ticket_time)
{
    int time;
movieTime:
    cout << "\n";
    cout << "   Select (1 - 2) to choose the time preferred : ";
    cin >> time;
    while (!cin)
    {
        cout << "   Invalid input, try again. \n";
        cout << "\n";
        cout << "   Select (1 - 2) to choose the time preferred : ";
        cin.clear();
        cin.ignore();
        cin >> time;
    }
    if (time == 1)
        ticket_time = "7:00 pm";
    else if (time == 2)
        ticket_time = "8:00 pm";
    else
    {
        cout << "   Invalid input, try again. \n";
        goto movieTime;
    }
    return time;
}
void information()
{
    cout << "\n";
    cout << "   *******************************************************************************************************\n";
    cout << "   **            _______________             | Class          |      1      |      2      |      3      **\n";
    cout << "   **   __ __ __ __ __     __ __ __ __ __    |----------------|-------------|-------------|-------------**\n";
    cout << "   **  |__|__|__|__|__|   |__|__|__|__|__|   | Category       |  Front Seat | Middle Seat |  Sofa bed   **\n";
    cout << "   **   __ __ __ __ __     __ __ __ __ __    |----------------|-------------|-------------|-------------**\n";
    cout << "   **  |__|__|__|__|__|   |__|__|__|__|__|   | Senior Citizen |  RM 14.00   |  RM 16.00   |  RM 20.00   **\n";
    cout << "   **   __ __ __ __ __     __ __ __ __ __    | Adult          |  RM 18.00   |  RM 20.00   |  RM 26.00   **\n";
    cout << "   **  |__|__|__|__|__|   |__|__|__|__|__|   | Child          |  RM  9.00   |  RM 10.00   |  RM 13.00   **\n";
    cout << "   **                                        | Student        |  RM 14.00   |  RM 16.00   |  RM 20.00   **\n";
    cout << "   **   __ __ __ __ __     __ __ __ __ __    |----------------------------------------------------------**\n";
    cout << "   **  |__|__|__|__|__|   |__|__|__|__|__|   |                    Terms & Condition                     **\n";
    cout << "   **   __ __ __ __ __     __ __ __ __ __    |----------------------------------------------------------**\n";
    cout << "   **  |__|__|__|__|__|   |__|__|__|__|__|   |         Senior Citizen  -->  above 60 years old          **\n";
    cout << "   **   __ __ __ __ __     __ __ __ __ __    |         Child           -->  below 12 years old          **\n";
    cout << "   **  |__|__|__|__|__|   |__|__|__|__|__|   |         Student         -->  must show student card      **\n";
    cout << "   **                                        |                                                          **\n";
    cout << "   **   __ __ __ __ __     __ __ __ __ __    |----------------------------------------------------------**\n";
    cout << "   **  |__|__|__|__|__|   |__|__|__|__|__|   |                                 _  _                     **\n";
    cout << "   **   __ __ __ __ __     __ __ __ __ __    |              TAR CINEMAX       / \\/ \\                    **\n";
    cout << "   **  |__|__|__|__|__|   |__|__|__|__|__|   |           -----------------    \\    / /\\/\\               **\n";
    cout << "   **   __ __ __ __ __     __ __ __ __ __    |            TABLE PRICE FOR      \\  /  \\  /               **\n";
    cout << "   **  |__|__|__|__|__|   |__|__|__|__|__|   |             MOVIE TICKETS        \\/    \\/                **\n";
    cout << "   **                                        |                                                          **\n";
    cout << "   *******************************************************************************************************\n";
}
// User input ticket details --------------------------------------------------------------------------------------------------------------------------------------
int movie_class()
{
    int input_class;
inputClass:
    cout << "\n";
    cout << "   Please input Class Required (1 - 3) : ";
    cin >> input_class;
    while (!cin)
    {
        cout << "   Invalid input, try again. \n";
        cout << "\n";
        cout << "   Please input Class Required (1 - 3) : ";
        cin.clear();
        cin.ignore();
        cin >> input_class;
    }
    if (input_class > 3 || input_class == 0)
    {
        cout << "   Invalid input, try again. \n";
        goto inputClass;
    }
    return input_class;
}
int movie_qty(int& senior, int& adult, int& child, int& student)
{
    int input_qty;
    char confirm;
notConfirm:
    cout << "\n";
    cout << "   Quantity of Senior Ticket   : ";
    cin >> senior;
    while (!cin)
    {
        cout << "   Quantity of Senior Ticket   : ";
        cin.clear();
        cin.ignore();
        cin >> senior;
    }
    cout << "   Quantity of Adult Ticket    : ";
    cin >> adult;
    while (!cin)
    {
        cout << "   Quantity of Adult Ticket    : ";
        cin.clear();
        cin.ignore();
        cin >> adult;
    }
    cout << "   Quantity of Child Ticket    : ";
    cin >> child;
    while (!cin)
    {
        cout << "   Quantity of Child Ticket    : ";
        cin.clear();
        cin.ignore();
        cin >> child;
    }
    cout << "   Quantity of Student Ticket  : ";
    cin >> student;
    while (!cin)
    {
        cout << "   Quantity of Student Ticket  : ";
        cin.clear();
        cin.ignore();
        cin >> student;
    }
    cout << "\n";
    cout << "   Enter (Y) to confirm your ticket quantity : ";
    cin >> confirm;
    if (islower(confirm) != 0)
        confirm = static_cast<char>(toupper(confirm));
    if (confirm != 'Y')
        goto notConfirm;
    else
        input_qty = senior + adult + child + student;
    return input_qty;
}
void limited()
{
    cout << "\n";
    cout << "          _______________________________________________________________\n";
    cout << "          |                                                             |\n";
    cout << "          |     The class you entered does not provide enough seats.    |\n";
    cout << "          |     Please refer to the showtime for more information.      |\n";
    cout << "          |                                                             |\n";
    cout << "          |     Press Any Key to Return to the Main Menu ...            |\n";
    cout << "          |_____________________________________________________________|\n";
    cout << "\n";
}
// Payment --------------------------------------------------------------------------------------------------------------------------------------------------------
void payment_method(double total_pay)
{
    char confirm;
    int pay_by;
    string username, password;
    double cash_payment, changes;
method:
    cout << "          _______________________________________________________________\n";
    cout << "          |                                                             |\n";
    cout << "          |     How Would You Like to Proceed Payment ?                 |\n";
    cout << "          |                                                             |\n";
    cout << "          |     1. Pay by Cash                                          |\n";
    cout << "          |     2. Pay by Debit or Credit Card                          |\n";
    cout << "          |     3. Pay by Touch N' Go or e-Wallet                       |\n";
    cout << "          |_____________________________________________________________|\n";
    cout << "\n";
    cout << "                Payment Method (1 - 3) : ";
    cin >> pay_by;
    switch (pay_by)
    {
    case 1:  // Pay by Cash
    {
        cout << "                Enter Cash Payment : RM  ";
        cin >> cash_payment;
        if (cash_payment < total_pay)
        {
            cout << "Payment is not enough. Payment Failed";
            cout << "\n";
            goto method;
        }
        else
            cout << "                Change due : RM " << cash_payment - total_pay << endl;
        break;
    }
    case 2:  // Pay by Debit or Credit Card
    {
        cout << "                Please enter your card username : ";
        cin.get();
        getline(cin, username);
        if (username.empty() == 1)
            goto error;
        cout << "                Please enter your card password : ";
        cin.get();
        getline(cin, password);
        if (password.empty() == 1)
            goto error;
        else
            break;
    error:
        cout << "                Invalid input. Payment Failed ! \n";
        cout << "\n";
        goto method;
    }
    case 3:  // Pay by Touch N' Go or e-Wallet
    {
        cout << "                Please scan the QR-Code provided \n";
    notConfirm:
        cout << "                Enter (Y) to proceed : ";
        cin >> confirm;
        if (islower(confirm) != 0)
            confirm = static_cast<char>(toupper(confirm));
        if (confirm != 'Y')
            goto notConfirm;
        break;
    }
    default: // Invalid Input
    {
        cout << "                Invalid input. Payment Failed ! \n";
        cout << "\n";
        goto method;
    }
    }
    cout << "                Payment Success ! \n";
}
// Report ---------------------------------------------------------------------------------------------------------------------------------------------------------
void seat_occupancy_seven(int M1T1C1, int M1T1C2, int M1T1C3, int M2T1C1, int M2T1C2, int M2T1C3, int M3T1C1, int M3T1C2, int M3T1C3)
{
    int M1T1C1_sold = 30 - M1T1C1, M1T1C2_sold = 30 - M1T1C2, M1T1C3_sold = 30 - M1T1C3,
        M2T1C1_sold = 30 - M2T1C1, M2T1C2_sold = 30 - M2T1C2, M2T1C3_sold = 30 - M2T1C3,
        M3T1C1_sold = 30 - M3T1C1, M3T1C2_sold = 30 - M3T1C2, M3T1C3_sold = 30 - M3T1C3;

    double M1T1C1_percent = (double)(M1T1C1_sold) / 3 * 10, M1T1C2_percent = (double)(M1T1C2_sold) / 3 * 10, M1T1C3_percent = (double)(M1T1C3_sold) / 3 * 10,
        M2T1C1_percent = (double)(M2T1C1_sold) / 3 * 10, M2T1C2_percent = (double)(M2T1C2_sold) / 3 * 10, M2T1C3_percent = (double)(M2T1C3_sold) / 3 * 10,
        M3T1C1_percent = (double)(M3T1C1_sold) / 3 * 10, M3T1C2_percent = (double)(M3T1C2_sold) / 3 * 10, M3T1C3_percent = (double)(M3T1C3_sold) / 3 * 10;

    cout << right << endl;
    cout << "  ___________________________________________________________________________________________________________________\n";
    cout << "  |-----------------------------------------------------------------------------------------------------------------|\n";
    cout << "  |                    SEAT OCCUPANCY FOR EACH CLASS [ 7.00 PM ] --> 11 August 2020 ( Wednesday )                   |\n";
    cout << "  |-----------------------------------------------------------------------------------------------------------------|\n";
    cout << "  |  Movies Name    |   Marvel Avengers : End Game  |      Beauty and the Beast     |           Zootopia 2          |\n";
    cout << "  |-----------------|-------------------------------|-------------------------------|-------------------------------|\n";
    cout << "  |  Seating Class  |   1   |   2   |   3   | total |   1   |   2   |   3   | total |   1   |   2   |   3   | total |\n";
    cout << "  |-----------------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|\n";
    cout << "  |  Total Seats    |    30 |    30 |    30 |    90 |    30 |    30 |    30 |    90 |    30 |    30 |    30 |    90 |\n";
    cout << "  |  Remained Seats | "

        << setw(5) << M1T1C1 << " | " << setw(5) << M1T1C2 << " | " << setw(5) << M1T1C3 << " | " << setw(5) << M1T1C1 + M1T1C2 + M1T1C3 << " | "
        << setw(5) << M2T1C1 << " | " << setw(5) << M2T1C2 << " | " << setw(5) << M2T1C3 << " | " << setw(5) << M2T1C1 + M2T1C2 + M2T1C3 << " | "
        << setw(5) << M3T1C1 << " | " << setw(5) << M3T1C2 << " | " << setw(5) << M3T1C3 << " | " << setw(5) << M3T1C1 + M3T1C2 + M3T1C3 << " |\n";

    cout << "  |  Quantity Sold  | "

        << setw(5) << M1T1C1_sold << " | " << setw(5) << M1T1C2_sold << " | " << setw(5) << M1T1C3_sold << " | "
        << setw(5) << M1T1C1_sold + M1T1C2_sold + M1T1C3_sold << " | "
        << setw(5) << M2T1C1_sold << " | " << setw(5) << M2T1C2_sold << " | " << setw(5) << M2T1C3_sold << " | "
        << setw(5) << M2T1C1_sold + M2T1C2_sold + M2T1C3_sold << " | "
        << setw(5) << M3T1C1_sold << " | " << setw(5) << M3T1C2_sold << " | " << setw(5) << M3T1C3_sold << " | "
        << setw(5) << M3T1C1_sold + M3T1C2_sold + M3T1C3_sold << " |\n";

    cout << "  |  Sold %         |" << fixed << setprecision(2)

        << setw(6) << M1T1C1_percent << " |" << setw(6) << M1T1C2_percent << " |" << setw(6) << M1T1C3_percent << " |"
        << setw(6) << (M1T1C1_percent + M1T1C2_percent + M1T1C3_percent) / 3 << " |"
        << setw(6) << M2T1C1_percent << " |" << setw(6) << M2T1C2_percent << " |" << setw(6) << M2T1C3_percent << " |"
        << setw(6) << (M2T1C1_percent + M2T1C2_percent + M2T1C3_percent) / 3 << " |"
        << setw(6) << M3T1C1_percent << " |" << setw(6) << M3T1C2_percent << " |" << setw(6) << M3T1C3_percent << " |"
        << setw(6) << (M3T1C1_percent + M3T1C2_percent + M3T1C3_percent) / 3 << " |\n";

    cout << "  |_________________|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n";

}
void seat_occupancy_eight(int M1T2C1, int M1T2C2, int M1T2C3, int M2T2C1, int M2T2C2, int M2T2C3, int M3T2C1, int M3T2C2, int M3T2C3)
{
    int M1T2C1_sold = 30 - M1T2C1, M1T2C2_sold = 30 - M1T2C2, M1T2C3_sold = 30 - M1T2C3,
        M2T2C1_sold = 30 - M2T2C1, M2T2C2_sold = 30 - M2T2C2, M2T2C3_sold = 30 - M2T2C3,
        M3T2C1_sold = 30 - M3T2C1, M3T2C2_sold = 30 - M3T2C2, M3T2C3_sold = 30 - M3T2C3;

    double M1T2C1_percent = (double)(M1T2C1_sold) / 3 * 10, M1T2C2_percent = (double)(M1T2C2_sold) / 3 * 10, M1T2C3_percent = (double)(M1T2C3_sold) / 3 * 10,
        M2T2C1_percent = (double)(M2T2C1_sold) / 3 * 10, M2T2C2_percent = (double)(M2T2C2_sold) / 3 * 10, M2T2C3_percent = (double)(M2T2C3_sold) / 3 * 10,
        M3T2C1_percent = (double)(M3T2C1_sold) / 3 * 10, M3T2C2_percent = (double)(M3T2C2_sold) / 3 * 10, M3T2C3_percent = (double)(M3T2C3_sold) / 3 * 10;

    cout << "\n";
    cout << "  ___________________________________________________________________________________________________________________\n";
    cout << "  |-----------------------------------------------------------------------------------------------------------------|\n";
    cout << "  |                    SEAT OCCUPANCY FOR EACH CLASS [ 8.00 PM ] --> 11 August 2020 ( Wednesday )                   |\n";
    cout << "  |-----------------------------------------------------------------------------------------------------------------|\n";
    cout << "  |  Movies Name    |   Marvel Avengers : End Game  |      Beauty and the Beast     |           Zootopia 2          |\n";
    cout << "  |-----------------|-------------------------------|-------------------------------|-------------------------------|\n";
    cout << "  |  Seating Class  |   1   |   2   |   3   | total |   1   |   2   |   3   | total |   1   |   2   |   3   | total |\n";
    cout << "  |-----------------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|\n";
    cout << "  |  Total Seats    |    30 |    30 |    30 |    90 |    30 |    30 |    30 |    90 |    30 |    30 |    30 |    90 |\n";
    cout << "  |  Remained Seats | "

        << setw(5) << M1T2C1 << " | " << setw(5) << M1T2C2 << " | " << setw(5) << M1T2C3 << " | " << setw(5) << M1T2C1 + M1T2C2 + M1T2C3 << " | "
        << setw(5) << M2T2C1 << " | " << setw(5) << M2T2C2 << " | " << setw(5) << M2T2C3 << " | " << setw(5) << M2T2C1 + M2T2C2 + M2T2C3 << " | "
        << setw(5) << M3T2C1 << " | " << setw(5) << M3T2C2 << " | " << setw(5) << M3T2C3 << " | " << setw(5) << M3T2C1 + M3T2C2 + M3T2C3 << " |\n";

    cout << "  |  Quantity Sold  | "

        << setw(5) << M1T2C1_sold << " | " << setw(5) << M1T2C2_sold << " | " << setw(5) << M1T2C3_sold << " | "
        << setw(5) << M1T2C1_sold + M1T2C2_sold + M1T2C3_sold << " | "
        << setw(5) << M2T2C1_sold << " | " << setw(5) << M2T2C2_sold << " | " << setw(5) << M2T2C3_sold << " | "
        << setw(5) << M2T2C1_sold + M2T2C2_sold + M2T2C3_sold << " | "
        << setw(5) << M3T2C1_sold << " | " << setw(5) << M3T2C2_sold << " | " << setw(5) << M3T2C3_sold << " | "
        << setw(5) << M3T2C1_sold + M3T2C2_sold + M3T2C3_sold << " |\n";

    cout << "  |  Sold %         | " << fixed << setprecision(2)

        << setw(5) << M1T2C1_percent << " | " << setw(5) << M1T2C2_percent << " | " << setw(5) << M1T2C3_percent << " | "
        << setw(5) << (M1T2C1_percent + M1T2C2_percent + M1T2C3_percent) / 3 << " | "
        << setw(5) << M2T2C1_percent << " | " << setw(5) << M2T2C2_percent << " | " << setw(5) << M2T2C3_percent << " | "
        << setw(5) << (M2T2C1_percent + M2T2C2_percent + M2T2C3_percent) / 3 << " | "
        << setw(5) << M3T2C1_percent << " | " << setw(5) << M3T2C2_percent << " | " << setw(5) << M3T2C3_percent << " | "
        << setw(5) << (M3T2C1_percent + M3T2C2_percent + M3T2C3_percent) / 3 << " |\n";

    cout << "  |_________________|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n";
}
void category_sales(
    int senior_one, int senior_two, int senior_three, double price_senior_one, double price_senior_two, double price_senior_three,
    int adult_one, int adult_two, int adult_three, double price_adult_one, double price_adult_two, double price_adult_three,
    int child_one, int child_two, int child_three, double price_child_one, double price_child_two, double price_child_three,
    int student_one, int student_two, int student_three, double price_student_one, double price_student_two, double price_student_three)
{
    cout << "\n";
    cout << "  _______________________________________________________________________________________________________\n";
    cout << "  |-----------------------------------------------------------------------------------------------------|\n";
    cout << "  |                 TOTAL SALES FOR EACH CATEGORY TYPE --> 11 August 2020 ( Wednesday )                 |\n";
    cout << "  |-----------------------------------------------------------------------------------------------------|\n";
    cout << "  |  Movies Name | Marvel Avengers : End Game |    Beauty and the Beast    |         Zootopia 2         |\n";
    cout << "  |--------------|----------------------------|----------------------------|----------------------------|\n";
    cout << "  |  Category    |   Seats   |   Sales (RM)   |   Seats   |   Sales (RM)   |   Seats   |   Sales (RM)   |\n";
    cout << "  |--------------|-----------|----------------|-----------|----------------|-----------|----------------|\n";
    cout << "  |  Senior C.   |   "

        << setw(5) << senior_one << "   |   " << setw(10) << price_senior_one << "   |   "
        << setw(5) << senior_two << "   |   " << setw(10) << price_senior_two << "   |   "
        << setw(5) << senior_three << "   |   " << setw(10) << price_senior_three << "   |\n";

    cout << "  |  Adult       |   "

        << setw(5) << adult_one << "   |   " << setw(10) << price_adult_one << "   |   "
        << setw(5) << adult_two << "   |   " << setw(10) << price_adult_two << "   |   "
        << setw(5) << adult_three << "   |   " << setw(10) << price_adult_three << "   |\n";

    cout << "  |  Child       |   "

        << setw(5) << child_one << "   |   " << setw(10) << price_child_one << "   |   "
        << setw(5) << child_two << "   |   " << setw(10) << price_child_two << "   |   "
        << setw(5) << child_three << "   |   " << setw(10) << price_child_three << "   |\n";

    cout << "  |  Student     |   "

        << setw(5) << student_one << "   |   " << setw(10) << price_student_one << "   |   "
        << setw(5) << student_two << "   |   " << setw(10) << price_student_two << "   |   "
        << setw(5) << student_three << "   |   " << setw(10) << price_student_three << "   |\n";

    cout << "  |--------------|-----------|----------------|-----------|----------------|-----------|----------------|\n";
    cout << "  |  Total       |   "

        << setw(5) << senior_one + adult_one + child_one + student_one << "   |   "
        << setw(10) << price_senior_one + price_adult_one + price_child_one + price_student_one << "   |   "

        << setw(5) << senior_two + adult_two + child_two + student_two << "   |   "
        << setw(10) << price_senior_two + price_adult_two + price_child_two + price_student_two << "   |   "

        << setw(5) << senior_three + adult_three + child_three + student_three << "   |   "
        << setw(10) << price_senior_three + price_adult_three + price_child_three + price_student_three << "   |\n";

    cout << "  |______________|___________|________________|___________|________________|___________|________________|\n";
}
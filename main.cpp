/********************************************
Course : TCP1101 Programming Fundamentals
Session: Trimester 2, 2020/21
Name: Ahmad Hariz Imran Bin Ahmad Azrir
ID : 1191102257
Lecture Section : TC1V
Tutorial Section: TT1V
Assignment: 1
Email: 1191102257@student.mmu.edu.my
Phone: 01139408962
********************************************/

#include <iostream>
#include <iomanip>
using namespace std;


long double fact(int n)
{
    long double f = 1;
    int c = 1;
    
    while (c <= n) {
        f = f * c;
        c = c + 1;
    }

return f;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

long double power(long double x, int n)
{
    int counter = 1;
    long double sum = x;

    while(counter < n)
    {   sum = sum * x;
        counter++;
    }

return sum;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

long double absolute(long double p_diff)
{
    if (p_diff < 0)
    {
        p_diff = p_diff * -1;
    }

return p_diff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

long double rad(long double degree, string mode)
{
    const long double pi = 3.14159265358979323846264338327950288419716;
    long double radian_before = degree * (pi/180);
    long double radian;

    if (mode == "degree")
    {   
        cout << endl;
        cout << setprecision(3) << fixed << degree << " Degrees = " << setprecision(10) << fixed << radian_before << " Radians" << endl;
        
        while (degree > 360)                    /// when angle is too big it will find the complimentary angle
        {
            degree = degree - 360;
        }
        radian = degree * (pi/180);
    }
    else
    {   while (degree > 2*pi)
        {
            degree = degree - (2*pi);
        }
        radian = degree;
    }
    

    return radian;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void results(long double f1, long double f2, long double angle_q, float dp, string mode)
{
    const long double pi = 3.14159265358979323846264338327950288419716;
    long double tangent,cosec,secant,cotangent;

    cout << "+----------------------------------+" << endl;
    cout << "|              RESULTS             |" << endl;
    if (mode == "degree")
    {
        long double qfinal;
        qfinal = angle_q * (pi/180);
        tangent = f1/f2; cosec = 1/f1; secant = 1/f2; cotangent = 1/tangent;
        
        cout << setw(12) << "x  = " << setprecision(dp) << fixed <<  setw(18) << qfinal << " Radians" << endl;
        cout << setw(12) << "sin(x) = " << setprecision(dp) << fixed << setw(18) << f1 << endl;
        cout << setw(12) << "cos(x) = " << setprecision(dp) << fixed <<  setw(18) << f2 << endl;
        cout << setw(12) << "tan(x) = " << setprecision(dp) << fixed <<  setw(18) << tangent << endl;
        cout << setw(12) << "cosec(x) = " << setprecision(dp) << fixed <<  setw(18) << cosec << endl;
        cout << setw(12) << "sec(x) = " << setprecision(dp) << fixed <<  setw(18) << secant << endl;
        cout << setw(12) << "cot(x) = " << setprecision(dp) << fixed <<  setw(18) << cotangent << endl;
        cout << endl;
        }

    else
    {
        tangent = f1/f2; cosec = 1/f1; secant = 1/f2; cotangent = 1/tangent;

        cout << setw(12) << "x  = " << setprecision(dp) << fixed <<  setw(18) << angle_q << " Radians" << endl;
        cout << setw(12) << "sin(x) = " << setprecision(dp) << fixed << setw(18) << f1 << endl;
        cout << setw(12) << "cos(x) = " << setprecision(dp) << fixed <<  setw(18) << f2 << endl;
        cout << setw(12) << "tan(x) = " << setprecision(dp) << fixed <<  setw(18) << tangent << endl;
        cout << setw(12) << "cosec(x) = " << setprecision(dp) << fixed <<  setw(18) << cosec << endl;
        cout << setw(12) << "sec(x) = " << setprecision(dp) << fixed <<  setw(18) << secant << endl;
        cout << setw(12) << "cot(x) = " << setprecision(dp) << fixed <<  setw(18) << cotangent << endl;
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

long double sinfunction(long double q, int dp)
{
    long double x = q;
    long double p1,p2,sum,p_diff;   // a is counter from 1 to N
    int i = 3, a = 2, sgn = -1;     // i is counter for factorial and power
    sum = x;
    p1 = sum;
    p2 = p1;

    cout << "\nComputing sine ..." << endl;
    cout << setprecision(dp) << fixed << setw(4) << 1 << " ===> " << setw(18) << sum << endl;

    do{
        sum = sum + sgn*power(x,i)/fact(i);
        sgn = sgn * -1;
        cout << setprecision(dp) << fixed << setw(4) << a << " ===> " << setw(18) << sum << endl;
        p2 = p1;
        p1 = sum;
        i = i + 2;
        a = a + 1;

        p_diff = p2 - p1;               // p difference to calculate when to stop
    } 
    while (absolute(p_diff) > 1.00/(power(10.00,dp)));

    return sum;
} 

////////////////////////////////////////////////////////////////////////////////////////////////////////

long double cosfunction(long double q, int dp)
{

    long double x = q;
    long double p1,p2,sum,p_diff;
    int i = 2, sgn = -1, a = 2;
    sum = 1;
    p1 = x;
    p2 = p1;

    cout << "\nComputing cosine ..." << endl;
    cout << setprecision(dp) << fixed << setw(4) << 1 << " ===> " << setw(18) << sum << endl;

    
    do{
        
        sum = sum + sgn*power(x,i)/fact(i);
        sgn = sgn * -1;
        cout << setprecision(dp) << fixed << setw(4) << a << " ===> " << setw(18) << sum  << endl;
        p2 = p1;
        p1 = sum;
        i = i + 2;
        a = a + 1;

        p_diff = p2 - p1;
    } 
    while (absolute(p_diff) > 1.00/(power(10.00,dp)));
    
    return sum;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    string mode = "radian";
    string choice;            // user inputs choice of 1,2,3 or Q
    int dp = 10;

    while (choice != "Q")
    {
    cout << "+----------------------------------+" << endl;
    cout << "|      T R I G O N O M E T R Y     |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "| Mode = " << mode << "                    |" << endl;
    cout << "| Decimal Precision = " << setw(4) << dp << "         |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "|Select:                           |" << endl;
    cout << "| 1 => Switch Degree/Radian Mode   |" << endl;
    cout << "| 2 => Set Decimal Precision       |" << endl;
    cout << "| 3 => Display Results             |" << endl;
    cout << "| Q => Quit                        |" << endl;
    cout << "+----------------------------------+" << endl;

    cout << "\nChoice => ";
    cin >> choice;


    if (choice == "1")
    {
        if (mode == "radian")
        {
            cout << "changing to degree" << endl;
            mode = "degree";
        }
        else
        {
            cout << "changing to radian" << endl;
            mode = "radian";
        }
        system("pause");
        system("CLS");
    }


    else if (choice == "2")
    {
        cout << "Decimal Precision => ";
        cin >> dp;                  // decimal point to calculate precision
        system("pause");
        system("CLS");
    }


    else if (choice == "3")
    {
        cout << "Angle value in " << mode << " => ";
        long double sin_final, cos_final, radq, ang_q, angle_q;         // sin_final and cos_final are the output of the sin and cos function
        
        cin >> angle_q;
        
        if (mode == "degree")
        {
            radq = rad(angle_q,mode);
            sin_final = sinfunction(radq,dp);
            cos_final = cosfunction(radq,dp);
        }
        else
        {
            ang_q = rad(angle_q,mode);
            sin_final = sinfunction(ang_q,dp);
            cos_final = cosfunction(ang_q,dp);
        }

        results(sin_final,cos_final,angle_q,dp,mode);
        system("pause");
        system("CLS");
    }
    
    else if (choice == "Q")
        {system("CLS");}

    else
    {
        cout << "Invalid.. Please Try again!!" << endl;
        system("pause");
        system("CLS");
    }
    }

    return 0;
}
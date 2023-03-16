#include <bits/stdc++.h>

using namespace std;
int level, student_level = 0, ques_num = 0;
int takenumber(int p)
{
    if (p == 0)
    {
        exit(1);
    }
    int a = rand();
    int x = pow(10, p);
    a = a % x;
    if ((a >= pow(10, p - 1)) && a <= pow(10, p))
        return a;
    else
    {
        return a + pow(10, p - 1);
    }
}
float round1(float var)
{

    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}
class calculator
{
    int a, b, lev, ans;
    float ans1;
    string str[8] = {"Very good!", "Excellent!", "Nice work!", "Keep up the good work!", "No, please try again", "Wrong,try once more.", "Don't give up!", "No, keep trying!"};

public:
    calculator()
    {
        lev = level;
        a = takenumber(level);
        b = takenumber(level);
    }
    void ask()
    {
        int x;
        cout << "If enter 1 then system give   operator\nIf enter  2 then you  choose operator:\n";
        cin >> x;
        if (x == 1)
        {

            int p = rand() % 4, d = rand() % 4;
            char ch;
            if (p == 0)
            {
                ch = '+';
                ans = a + b;
            }
            if (p == 1)
            {
                ch = '-';
                ans = a - b;
            }
            if (p == 2)
            {
                ch = '*';
                ans = a * b;
            }
            if (p == 3)
            {
                ch = '/';
                ans1 = (a * 1.00) / b;
                ans1 = round1(ans1);
            }
            ques_num++;
            cout << ques_num << ". How much is " << a << ch << b << "?" << endl;
            if (p == 3)
            {
                float q;
                cin >> q;
                if (q != ans1)
                {
                    student_level++;
                    d += 4;
                }
            }
            else
            {

                int q;
                cin >> q;
                if (q != ans)
                {
                    student_level++;
                    d += 4;
                }
            }

            cout << "           *********  Your's status  *********" << endl;
            cout << "            ***   " << str[d] << "   *** " << endl;
        }

        else if (x == 2)
        {
            int d = rand() % 4;
            char c;
            cout << "           ***  Enter Operator  ***\n";
            cin >> c;
            if (c == '+')
            {
                ans = a + b;
            }
            if (c == '-')
            {
                ans = a - b;
            }
            if (c == '*')
            {
                ans = a * b;
            }
            if (c == '/')
            {
                ans1 = (a * 1.00) / b;

                ans1 = round1(ans1);
            }
            ques_num++;
            cout << ques_num << ". How much is " << a << c << b << "?" << endl;
            if (c == '/')
            {
                float p;
                cin >> p;
                if (p != ans1)
                {
                    student_level++;
                    d += 4;
                }
            }
            else
            {

                int p;
                cin >> p;
                if (p != ans)
                {
                    student_level++;
                    d += 4;
                }
            }

            cout << "           *********Your's status*******" << endl;
            cout << "            ***   " << str[d] << "   *** " << endl;
        }
        return;
    }
};

int main()
{

    cout << "          ***Most Welcome For Join Us***\n";
    cout << "          ***      level of student       ****\n1.if you enter the 1 then ask question level is very simple \n2.this way if you enter the number is high then ask question level increase\n";
    cin >> level;
    int p = 10;
    while (p--)
    {
        calculator student;
        student.ask();
    }
    int ans = ((student_level)*100) / 10;
    if (ans < 25)
    {
        cout << "   ***   You are the star of us   ***\n";
        cout << "congratulations you are ready to go to the next level.\n";
    }
    else
    {
        cout << "      ***   Don't worry again try with full concentrate   ***\n";
        cout << "please ask your teacher for the extra help.\n";
    }

    return 0;
}
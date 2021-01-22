#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include  <stdio.h>
#include <string>
#include <iomanip>

using namespace std;

int days_year(int year)
{
    if ((year%4==0) && ((year%100!=0) || (year%400==0)))
    {
        return 366;
    }
    else
    {
        return 365;
    }
}
string month_print(int month)
{
    string month_entered;
    if (month==01)
        {
            month_entered="January";

        }
        else if (month==02)
        {
            month_entered="Febuary";

        }
        else if (month==03)
        {
            month_entered="March";

        }
        else if (month==04)
        {
            month_entered="April";

        }
        else if (month==05)
        {
            month_entered="May";

        }
        else if (month==06)
        {
            month_entered="June";

        }
        else if (month==07)
        {
            month_entered="July";

        }
        else if (month==8)
        {
            month_entered="August";

        }
        else if (month==9)
        {
            month_entered="September";

        }
        else if (month==10)
        {
            month_entered="October";

        }
        else if (month==11)
        {
            month_entered="November";

        }
        else if (month==12)
        {
            month_entered="December";

        }
        return month_entered;
}

int day_count(int month,int year)
{
    if (month==01)
    {
        return 31;
    }
    if (month==02)
    {
        if (year%4==0||year%400==0)
        {
            if (year%100==0 && year%400!=0)
                {
                    return 28;
                }
            else
            {
                return 29;
            }
        }
        else
        {
            return 28;
        }
    }
    if (month==03)
    {
        return 31;
    }
    if (month==04)
    {
        return 30;
    }
    if (month==05)
    {
        return 31;
    }
    if (month==06)
    {
        return 30;
    }
    if (month==07)
    {
        return 31;
    }
    if (month==8)
    {
        return 31;
    }
    if (month==9)
    {
        return 30;
    }
    if (month==10)
    {
        return 31;
    }
    if (month==11)
    {
        return 30;
    }
    if (month==12)
    {
        return 31;
    }

}

int months_difference(int month,int year)
{
    int count=0;
    month=month-1;
    while (month!=0)
        {
            count = count + day_count(month,year);
            month = month-1;

        }
        int d=year-1;
        for (int i=d;i>=1703;i--)
        {
            count=count+days_year(year-1);
            year--;
        }



    return count;
}

struct final_data
{
    string array[2][8];
    int dates[8][8];
};

int main()
{
    int month,year,days_count,month_difference,remainder,date=1,x=1;
    string month_Entered;
    cout<<"This program shows calendar of a given month.Enter month and year(1703 onwards) in the format: mm-yyyy: ";
    cin>>month>>year;
    cout<<"Data entered: "<<month<<"--"<<year;
    if (month<01||month>12||year<1703||year>9999)
    {
        cout<<"\nData Entered is not valid.";
    }
    else

    {
        struct final_data month_data;

        month_Entered = month_print(month);
        cout<<"\n\n-----------------------------------------------"<<month_Entered<<" "<<year<<"-----------------------------------------------"<<endl;
        days_count = day_count(month,year);
        //cout<<"\n"<<days_count<<endl;


        month_data.array[1][1]="Mon";
        month_data.array[1][2]="Tue";
        month_data.array[1][3]="Wed";
        month_data.array[1][4]="Thu";
        month_data.array[1][5]="Fri";
        month_data.array[1][6]="Sat";
        month_data.array[1][7]="Sun";

        if (year>=1703)
        {
                month_difference = months_difference(month,year);
                //cout<<month_difference<<endl<<endl<<endl;
                //cout<<month_difference<<endl;
                remainder = month_difference%7;
                for (int j=1;j<=remainder;j++)
                {
                    month_data.dates[2][j]=0;
                }
                remainder=remainder+1;


                while (remainder!=8)
                {

                    month_data.dates[2][remainder]=date;
                    remainder++;
                    date++;
                    //cout<<date<<endl;

                }
                for (int k=3;k<8;k++)
                {

                    for (int x=1;x<8;x++)
                    {
                        month_data.dates[k][x]=date;
                        date++;
                        //x++;
                        //cout<<date<<endl;

                        if (date>day_count(month,year))
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    continue;

                }



        }
        int random=0;
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
        for(int h=0;h<8;h++)
        {
            cout<<month_data.array[1][h]<< std::setw(15);
            //cout<<"     ";

        }
        int s = day_count(month,year);


        cout<<endl;
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl<<"              ";
        //cout<<month_data.dates[1][1]<<endl;
        for(int i=2;i<=7;i++)
        {

            for (int j=1;j<=7;j++)
            {


                if (month_data.dates[i][j]>=1)
                {
                    cout<<month_data.dates[i][j]<< std::setw(15);
                    random++;
                }
                else
                {
                    cout<<" "<< std::setw(15);
                }
                if (random!=s)
                {
                    continue;
                }
                else
                {
                    exit(0);
                }

            }



            cout<<endl;


        }


    }
    }

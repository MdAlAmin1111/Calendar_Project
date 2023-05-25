#include<iostream>
#include<list>
#include<string>
using namespace std;

int day_function(string starting_day)
{
    if(starting_day=="Sunday")
        return 0;
    else if(starting_day=="Monday")
        return 1;
    else if(starting_day=="Tuesday")
        return 2;
    else if(starting_day=="Wednesday")
        return 3;
    else if(starting_day=="Thursday")
        return 4;
    else if(starting_day=="Friday")
        return 5;
    else
        return 6;
}
void calander_function(int** A, int year, int days_in_month[])
{

    for(int i=0;i<12; i++)
    {
        for(int j=0; j<days_in_month[i]; j++)
        {
            A[i][j]=j+1;
        }
    }
}

void print_calendar(int Day, int days_in_month[], int** A)
{
    int week;
    string month_name[12]={"January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};
    for(int i=0; i<12; i++)
    {
        cout<<"\n\n   ---------------"<<month_name[i]<<"---------------";
        cout<<"\n\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n";
        for(int j=0; j<Day;j++)
        {
            cout<<"      ";
        }
        cout<<"\b\b";

        week=Day;
        for(int m=0; m<days_in_month[i]; m++)
        {
            if(m<10)
                cout<<"     ";
            else
                cout<<"    ";
            if(week > 6)
            {
                cout<<"\n   "<<A[i][m];
                week=0;
            }
            else
                cout<<A[i][m];
            week++;
        }
        Day=week;
    }
}

struct reminder
{
    string Reminder_title;
	string Reminder_description;
	int Date;
	int Month;

};
void add_reminder(list<reminder>&reminder_list)
{
    reminder new_reminder;
    cout<<"\nReminder Title: ";
    cin>>new_reminder.Reminder_title;
    cout<<"Reminder Description: ";
    cin>>new_reminder.Reminder_description;
    cout<<"Date: ";
    cin>>new_reminder.Date;
    cout<<"Month: ";
    cin>>new_reminder.Month;

   reminder_list.push_back(new_reminder);

}
void Update_reminder(list<reminder>&reminder_list)
{
    string title;
    int day, month;

    cout<<endl<<"Enter Title You Looking for: ";
    cin>>title;
    cout<<"Enter Day You Looking for: ";
    cin>>day;
    cout<<"Enter Month You Looking for: ";
    cin>>month;
    list<reminder> :: iterator it;
    for(it=reminder_list.begin();it!=reminder_list.end(); it++)
    {
        if(title==it->Reminder_title && day==it->Date && month == it->Month )
        {
            string a,b;
            int c,d;
            cout<<"\nEnter New Title: ";
            cin>>a;
            cout<<"Enter New Description:";
            cin>>b;
            cout<<"Enter New Date: ";
            cin>>c;
            cout<<"Enter New Month: ";
            cin>>d;
            it->Reminder_title=a;
            it->Reminder_description=b;
            it->Date=c;
            it->Month=d;
        }
    }
}
void View_all_the_reminders_of_a_specific_month(list<reminder>reminder_list)
{
    int month;
    cout<<"\nEnter of Which Month's Reminder You Want to View: ";
    cin>>month;
    list<reminder> :: iterator it;
    for(it=reminder_list.begin();it!=reminder_list.end(); it++)
    {
        if(month==it->Month)
        {
            cout<<"\nTitle: "<<it->Reminder_title<<endl;
            cout<<"Description: "<<it->Reminder_description<<endl;
            cout<<"Date: "<<it->Date<<endl;
            cout<<"Month: "<<it->Month<<endl;
        }
        cout<<endl<<endl;
    }
}
void Delete_a_specific_reminder(list<reminder>&reminder_list)
{
    string r_title;
    int r_day, r_month;
    cout<<"\nEnter Title: ";
    cin>>r_title;
    cout<<"Enter day: ";
    cin>>r_day;
    cout<<"Enter Month: ";
    cin>>r_month;

    list<reminder> :: iterator it;
    for(it=reminder_list.begin();it!=reminder_list.end(); it++)
    {
        if(it->Reminder_title == r_title && it->Date == r_day && it->Month == r_month )
        {
            //reminder_list.remove(it);
        }
    }


}

int main()
{
    int year;
    string starting_day;
    cout<<"Enter the Year: ";
    cin>>year;
    cout<<"Enter Starting Day of the Year: ";
    cin>>starting_day;

    int days_in_month[12]={31,28,31,29,31,29,31,31,29,31,29,31};
    if(year%4==0 && year%100!=0)
    {
        days_in_month[1]=29;
    }

    int** calendar_array= new int*[12];
    for(int i=0; i<12;i++)
    {
        calendar_array[i]=new int[days_in_month[i]];
    }

    int day=day_function(starting_day);
    calander_function(calendar_array,year,days_in_month);
    print_calendar(day, days_in_month, calendar_array);
    cout<<endl<<endl;

    for(int i=0; i<12;i++)
    {
        delete[]calendar_array[i];
    }
    delete[]calendar_array;


    list<reminder>reminder_list;
    int n;
    cout<<"Enter 1 for Add Reminder\nEnter 2 for Update Reminder\nEnter 3 for Delete a Reminder\nEnter 4 for View All the Reminders of a Specific Month\nEnter 0 for Exit from the Calendar: ";
    cin>>n;
    while(n!=0)
    {
        if(n==1)
        {
            add_reminder(reminder_list);cout<<endl;
        }
        if(n==2)
        {
            Update_reminder(reminder_list);
        }
        if(n==3)
        {
            Delete_a_specific_reminder(reminder_list);
        }
        if(n==4)
        {
            View_all_the_reminders_of_a_specific_month(reminder_list);
        }
        cout<<endl<<"What to do? Enter Again: ";
        cin>>n;
    }
    return 0;
}

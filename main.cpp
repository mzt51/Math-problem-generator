#include <iostream>
#include<random>
#include<conio.h>
#include<chrono>
#include<ctime>
#include<string>
#include<algorithm>
using namespace std;
void times_tables(int a)
{
    vector<int>vec;
    cout<<"Coming right up!\n";
    int sum=0,y;
    int x;
    for(int i=1;i<=10;i++)
    {
      sum = i*a;
      vec.push_back(sum);
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);
    shuffle(vec.begin(), vec.end(),e);
    for(int i=0;i<10;i++)
    {
        sum=vec[i];
        y = sum/a;
        cout<<a<<" x "<<y<<" = ?\n";
        cin>>x;
        while(x!=sum)
        {
            cout<<"\nWrong answer, try again\n";
            cin>>x;
        }
        cout<<"\nGood job!\n";
    }
}
int comparestr(string s)
{
    string add = "addition";
    string sub = "subtraction";
    string mul = "multiplication";
    string tim = "times tables";
    if((s.compare(add))==0)
    {
        return 1;
    }
    else if((s.compare(sub))==0)
    {
        return 2;
    }
    else if((s.compare(mul))==0)
    {
        return 3;
    }
    else if((s.compare(tim))==0)
    {
        return 4;
    }
    else
    {
        return -1;
    }
}
void change(long &a,long &b)
{
    int t = b;
      b = a;
      a = t;
      return;
}
void randn(long &x,long &y,long num1,long num2)
{
    chrono::system_clock::time_point t = chrono::system_clock::now();
  time_t tp = chrono::system_clock::to_time_t(t);
  mt19937 ab(tp);
  uniform_int_distribution<> range(num1,num2);
  x = range(ab);
  y = range(ab);
  return;

}
void subtraction(long n,long r1,long r2)
{
    cout<<"\ngot it! "<<n<<" subtraction problems coming right up!\n";
    long a=0,b=0,c,d;
  if(r1 > r2)
  {
      change(r1,r2);
  }
  for(int i = 1; i <= n; i++)
  {

        randn(a,b,r1,r2);
        c = a - b;
        cout<<"\nProblem number: "<<i<<endl;
        cout<<a<<" - "<<b<<" = ?"<<endl;
        cout<<"What's the answer?\n";
        cin>>d;
        while(d!=c)
        {
            cout<<"\nWrong answer, try again\n";
            cin>>d;
        }
        cout<<"Good job!\n";
  }
}
void addition(long n,long r1, long r2)
{
    cout<<"\ngot it! "<<n<<" addition problems coming right up!\n";
    long a=0,b=0,c,d;
  if(r1 > r2)
  {
      change(r1,r2);
  }
  for(int i = 1; i <= n; i++)
  {

        randn(a,b,r1,r2);
        c = a + b;
        cout<<"\nProblem number: "<<i<<endl;
        cout<<a<<" + "<<b<<" = ?"<<endl;
        cout<<"What's the answer?\n";
        cin>>d;
        while(d!=c)
        {
            cout<<"\nWrong answer, try again\n";
            cin>>d;
        }
        cout<<"Good job!\n";
  }
}
void multiplication(long n,long r1, long r2)
{
    cout<<"\ngot it! "<<n<<" multiplication problems coming right up!\n";
    long a=0,b=0,c,d;
  if(r1 > r2)
  {
      change(r1,r2);
  }
  for(int i = 1; i <= n; i++)
  {

        randn(a,b,r1,r2);
        c = a * b;
        cout<<"\nProblem number: "<<i<<endl;
        cout<<a<<" x "<<b<<" = ?"<<endl;
        cout<<"What's the answer?\n";
        cin>>d;
        while(d!=c)
        {
            cout<<"\nWrong answer, try again\n";
            cin>>d;
        }
        cout<<"Good job!\n";
  }
}
void maths()
{
    int x,sel;
    long y,z;
    string ch;
    cout<<"Addition, Subtraction, Multiplication or Times Tables?\n";
    cout<<"Choice: ";
    cin.clear();
    cin.sync();
    getline(cin,ch);
    transform(ch.begin(), ch.end(), ch.begin(), ::tolower);
    sel = comparestr(ch);
    while(sel==-1)
    {
        cout<<"\nDid not understand that command, try again.\n";
        cout<<"Addition, Subtraction, Multiplication or Times Tables?\n";
        cout<<"Choice: ";
        cin.clear();
        cin.sync();
        getline(cin,ch);
        sel=comparestr(ch);
    }
    if(sel==4)
    {
      cout<<"\nWhich times table do you want?\n";
      cin>>x;
      times_tables(x);
    }
    else
    {
    cout<<"\nHow many sums?\n";
    cin>>x;
    cout<<"\nWhat range should they be in?\n";
    cout<<"First number: ";
    cin>>y;
    cout<<"\nSecond number: ";
    cin>>z;
    if(sel ==1)
    {
    addition(x,y,z);
    }
    else if(sel ==2)
    {
        subtraction(x,y,z);
    }
    else if(sel ==3)
    {
        multiplication(x,y,z);
    }
    }
}
int main()
{
    string y ="yes";
    string n ="no";
    string p;
    maths();
    while(true)
    {
    cout<<"\nWanna try more problems? Type yes or no.\n";
    cin>>p;
    if((p.compare(y))==0)
    {
        maths();
    }
    else if((p.compare(n))==0)
    {
        break;
    }

}
cout<<"\nCya next time";
getch();
}

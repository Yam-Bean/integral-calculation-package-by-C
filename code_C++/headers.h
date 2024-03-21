#include <iostream>
#include<math.h>
#include<string>
#include<ctime>
#include<conio.h>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<cctype>
#include<limits>
#include<cfloat>
#include<cstring>
#include<string.h>
#include<limits.h>
#include <cstdlib>
#include<float.h>
#include<stdio.h>
#include<random>
#include<iostream>
#include<ctime>
#include<time.h>
#include<fstream>
#include<windows.h>
#include<iomanip>
#include<conio.h>

using namespace std;


class Point{
public:
    int point( string orifunc , double down , double up);
    double impro_Definition( string orifunc , double down , double up );
    double impro_Simpson( string orifunc , double down , double up );
    double impro_Trapezoid( string orifunc , double down , double up );
    double impro_Montecarlo( string orifunc , double down , double up );
    vector<double> storepoint;
};





double solve ( string orifunc, double x );  //解决加减乘除次方和e的运算
double mainsolve ( string orifunc, double x ); //用于计算括号的函数
double lastsolve( string orifunc, double x ); //用于最后计算的函数（包含绝对值运算）
double binarysolve ( string orifunc, double x, double y );
bool judge ( char c );
string tritransfer ( double mid, string orifunc, int lefthalf, int righthalf );
string logtransfer ( double lmid, double rmid, string orifunc, int lefthalf, int righthalf );
string transfer(int j,double x,int lefthalf,int righthalf,string orifunc);
string abstransfer( double absmid, string orifunc, int leftabs, int rightabs );
double Montecarlo(string orifunc,double down,double up);
double Montecarlo_Infinite(string orifunc,double down,double up);
double Montecarlo_binary(string orifunc,double downx,double upx,double downy,double upy);
double Montecarlo_binary_Infinite(string orifunc,double downx,double upx,double downy,double upy);
double montecarlo( string orifunc , double down , double up );
double montecarlo_binary(string orifunc,double downx,double upx,double downy,double upy);
double Definition( string orifunc , double down , double up );
double Definition_binary(string orifunc,double downx,double upx,double downy,double upy);
double Simpson( string orifunc , double down , double up );
double fixySimpson_binary( string orifunc , double a , double b , double y );
double exact_fy_binary( string orifunc , double a , double b , double y , double esp );
double Simpson_binary( string orifunc , double downx , double upx , double downy , double upy , double esp );
double exact_Simpson_binary( string orifunc , double downx , double upx , double downy , double upy , double esp );
double Trapezoid( string orifunc , double down , double up );
double Trapezoid_binary(string orifunc,double downx,double upx,double downy,double upy);




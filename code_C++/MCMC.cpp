#include"headers.h"

using namespace std;

double Montecarlo( string orifunc , double down , double up )
{
    double m = down ;
    double n = up ;
    double Max_point = m ;
    double Min_point = m ;
    double Max0 = lastsolve( orifunc, Max_point ) ;
    double Min0 = lastsolve( orifunc, Min_point ) ;
    double delta = 0.001;
    double x ;
    double y ;
    double r1 , r2 ;
    double enter_up = 0 , include_up = 0 , enter_down = 0 , include_down = 0 ;
    double Area1,Area2;
    int i ;
    //找最大值，最小值及最大值点，最小值点
    for ( i = 0 ; i < ( up - down ) / delta ; i = i + 1 ) {
        if ( lastsolve ( orifunc , Min_point + delta ) < Min0 ) {
            Min0 = lastsolve ( orifunc , Min_point + delta ) ;
              Min_point = Min_point + delta ;
        }
    }
    for( i = 0 ; i < ( up - down ) / delta ; i = i + 1 ) {
        if ( lastsolve ( orifunc , Max_point + delta ) > Max0) {
            Max0 = lastsolve ( orifunc  , Max_point + delta ) ;
              Max_point = Max_point + delta ;
        }
    }
    if ( Max0 >= Min0 && Min0 > 0 ) {
        Min0 = 0 ;
    }
    if ( Max0 >= Min0 && Max0 < 0 ) {
        Max0 = 0 ;
    }
    //产生在规定范围内的随机数
    default_random_engine e ( time(0) ) ;
	uniform_real_distribution<double> u ( m , n ) ;
	 srand( (double)time(NULL) ) ;
    for ( i = 0 ; i < ( up - down ) / delta ; i++ ) {
	x = u(e);
    y = ( rand() / (double)RAND_MAX ) * ( Max0 - Min0 ) + Min0 ;
    //求投点在函数于x轴之间的点数比例r
        if ( y >= 0 ) {
            enter_up = enter_up + 1 ;
            if ( y <= lastsolve( orifunc , x ) ) {
                include_up = include_up + 1 ;
            }
        }
        if ( y < 0 ) {
            enter_down = enter_down + 1 ;
            if( lastsolve ( orifunc , x ) >= y ) {
                include_down = include_down + 1 ;
            }
        }
    }
        r1 = include_up / enter_up ;
        r2 = include_down / enter_down ;
    //求函数于x轴所围成面积Area = s * r
    if ( include_up == 0 ) {
        Area1 = 0 ;
    }
    else {
        Area1 = (n - m) * Max0 *  r1 ;
    }
    if( include_down == 0 ) {
        Area2 = 0 ;
    }
    else {
        Area2 = (n - m) * (-Min0) * r2 ;
    }


    return Area1 + Area2 ;
}

//二元有限定积分
double Montecarlo_binary(string orifunc,double downx,double upx,double downy,double upy)
{
    double m = downx ;
    double n = upx ;
    double m1 = downy ;
    double n1 = upy ;
    double Max_pointx = m ;
    double Min_pointx = m ;
    double Max_pointy = m1 ;
    double Min_pointy = m1 ;
    double Max0 = binarysolve ( orifunc , Min_pointx , Min_pointy ) ;
    double Min0 = binarysolve ( orifunc , Min_pointx , Min_pointy ) ;
    double delta =  0.001 ;
    double x ;
    double y ;
    double z ;
    double r1 , r2 ;
    double enter_up = 0,include_up = 0,enter_down = 0,include_down = 0 ;
    double Area1 , Area2 ;
    int i ;
    double f ;
    //找最大值，最小值及最大值点，最小值点
	if ( ( upx - downx ) / delta  > ( upy - downy ) / delta ) {
    f = ( upx - downx ) / delta ;
	}
	else {
        f = ( upy - downy ) / delta ;
	}
    for ( i = 0 ; i < f; i = i + 1 ) {
        for ( i = 0 ; i < ( upx - downx ) / delta ; i = i + 1 ) {
            if (  binarysolve( orifunc , Min_pointx + delta , Min_pointy + delta ) < Min0 ) {
                Min0 = binarysolve( orifunc , Min_pointx + delta , Min_pointy + delta ) ;
                Min_pointx = Min_pointx + delta ;
                Min_pointy = Min_pointy + delta ;
            }
        }
        for( i = 0 ; i < ( upy - downy ) / delta ; i = i + 1 ) {
            if( binarysolve ( orifunc , Max_pointx + delta , Max_pointy + delta ) > Max0 ) {
                Max0 = binarysolve ( orifunc , Max_pointx + delta , Max_pointy + delta ) ;
                Max_pointx = Max_pointx + delta ;
                Max_pointy = Max_pointy + delta ;
            }
        }
    }

    if ( Max0 >= Min0 && Min0 < 0 ) {
        Min0 = 0 ;
    }
    if ( Max0 >= Min0 && Max0 < 0 ) {
        Max0 = 0 ;
    }
    //产生在规定范围内的随机数
    default_random_engine e ( time(0) ) ;
	uniform_real_distribution<double> u ( m , n ) ;
	srand ( (double)time(NULL) ) ;
    default_random_engine o ( time(0) ) ;
	uniform_real_distribution<double> g ( Min0 , Max0 ) ;
    for ( i = 0 ; i < f ; i++ ) {
	x = u(e);
    y = ( rand() / (double)RAND_MAX ) * ( upy - downy ) + downy ;
    z =g(o);
    //求投点在函数于x轴之间的点数比例r
        if ( z >= 0 ) {
            enter_up = enter_up + 1 ;
            if ( z <= binarysolve( orifunc , x , y ) ) {
                include_up = include_up + 1 ;
          }
        }
        if ( z < 0 ) {
            enter_down = enter_down + 1 ;
            if ( z >= binarysolve( orifunc , x , y ) ) {
                include_down = include_down + 1 ;
            }
        }
    }
        r1 = include_up / enter_up ;
        r2 = include_down / enter_down ;
    //求函数于x轴所围成面积Area = s * r
    if ( include_up == 0 ){
        Area1 = 0;
    }
    else {
        Area1 = (n1 - m1) * (n - m) * Max0 *  r1 ;
    }
    if ( include_down == 0 ){
        Area2 = 0 ;
    }
    else {
        Area2 = (n1 - m1) * (n - m) * (-Min0) * r2 ;
    }
    return  Area1 + Area2;
}
double Point::impro_Montecarlo( string orifunc , double down , double up ){
    double answer = 0 ;
    double ase = 0.001 ;
    double anothermid ;
    int i ,time = 1 ;
    vector<double> test ;
    if( storepoint.size() != 0 ){
         double sizeori =  storepoint.size() ;
    if( storepoint[0] == down){
        if( storepoint [sizeori - 1] == up){
            for( i = 0 ; i < sizeori - 1 ; i++ ){
                while( time < 9 ){
                    anothermid = Montecarlo( orifunc , storepoint[i] + ase , storepoint[i+1] - ase ) ;
                    if(fabs( anothermid ) >= 1e-6 )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                answer = answer + test[test.size()-1];
                test.clear();
            }
        }
        else{
            for( i = 0 ; i < sizeori - 2 ; i ++ ){
                while( time < 9 ){
                    anothermid = Montecarlo( orifunc , storepoint[i] + ase , storepoint[i+1] - ase ) ;
                    if(fabs( anothermid ) >= 1e-6 )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;

                }
                ase = 0.001 ;
                time = 1 ;
                answer = answer + test[test.size()-1];
                test.clear();
            }
            while( time < 9 ){
                    anothermid = Montecarlo( orifunc , storepoint[sizeori - 1] + ase , up ) ;
                    if(fabs( anothermid ) >= 1e-6 )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                answer = answer + test[test.size()-1];
                test.clear();
        }
    }
    else if( storepoint[sizeori - 1] == up ){
            for( i = 1 ; i < sizeori - 1 ; i ++ ){
                while( time < 9 ){
                    anothermid = Montecarlo( orifunc , storepoint[i] + ase , storepoint[i+1] - ase ) ;
                    if(fabs( anothermid ) >= 1e-6 )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                answer = answer + test[test.size()-1];
                test.clear();
            }
            while( time < 9 ){
                    anothermid = Montecarlo( orifunc , down , storepoint[0] - ase ) ;
                    if(fabs( anothermid ) >= 1e-6 )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                answer = answer + test[test.size()-1];
                test.clear();
        }
    else{
            for(i = 1 ; i < sizeori - 2 ; i ++ ){
                while( time < 9 ){
                    anothermid = Montecarlo( orifunc , storepoint[i] + ase , storepoint[i+1] - ase ) ;
                    if(fabs( anothermid ) >= 1e-6 )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                answer = answer + test[test.size()-1];
                test.clear();
            }
                while( time < 9 ){
                    anothermid = Montecarlo( orifunc , storepoint[sizeori - 1] + ase , up ) ;
                    if(fabs( anothermid ) >= 1e-6 )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                answer = answer + test[test.size()-1];
                test.clear();
                while( time < 9 ){
                    anothermid = Montecarlo( orifunc , down , storepoint[0] - ase ) ;
                    if(fabs( anothermid ) >= 1e-6 )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                answer = answer + test[test.size() - 1];
                test.clear();
    }
    }
    return answer;

}

//一元无穷定积分
double Montecarlo_Infinite(string orifunc,double down,double up)
{
    double m = down ;
    double n = up ;
    double Max_point = m ;
    double Min_point = m ;
    double Max0 = lastsolve( orifunc, Max_point ) ;
    double Min0 = lastsolve( orifunc, Min_point ) ;
    double delta =  0.001 ;
    double x ;
    double y ;
    double r1 , r2 ;
    double enter_up = 0 , include_up = 0 , enter_down = 0 , include_down = 0 ;
    double Area1,Area2;
    int i ;
    if ( down <- 1000 ) {
        down =- 1000 ;
    }
    if ( up > 1000 ) {
        up = 1000 ;
    }
    //找最大值，最小值及最大值点，最小值点
    for ( i = 0 ; i < ( up - down ) / delta ; i = i + 1 ) {
        if ( lastsolve ( orifunc , Min_point + delta ) < Min0 ) {
            Min0 = lastsolve ( orifunc , Min_point + delta ) ;
              Min_point = Min_point + delta ;
        }
    }
    for( i = 0 ; i < ( up - down ) / delta ; i = i + 1 ) {
        if ( lastsolve ( orifunc , Max_point + delta ) > Max0) {
            Max0 = lastsolve ( orifunc  , Max_point + delta ) ;
              Max_point = Max_point + delta ;
        }
    }
    if ( Max0 >= Min0 && Min0 > 0 ) {
        Min0 = 0 ;
    }
    if ( Max0 >= Min0 && Max0 < 0 ) {
        Max0 = 0 ;
    }
    //产生在规定范围内的随机数
    default_random_engine e ( time(0) ) ;
	uniform_real_distribution<double> u ( m , n ) ;
	 srand( (double)time(NULL) ) ;
    for ( i = 0 ; i < ( up - down ) / delta ; i++ ) {
	x = u(e);
    y = ( rand() / (double)RAND_MAX ) * ( Max0 - Min0 ) + Min0 ;
    //求投点在函数于x轴之间的点数比例r
        if ( y >= 0 ) {
            enter_up = enter_up + 1 ;
            if ( y <= lastsolve( orifunc , x ) ) {
                include_up = include_up + 1 ;
            }
        }
        if ( y < 0 ) {
            enter_down = enter_down + 1 ;
            if( lastsolve ( orifunc , x ) >= y ) {
                include_down = include_down + 1 ;
            }
        }
    }
        r1 = include_up / enter_up ;
        r2 = include_down / enter_down ;
    //求函数于x轴所围成面积Area = s * r
    if ( include_up == 0 ) {
        Area1 = 0 ;
    }
    else {
        Area1 = (n - m) * Max0 *  r1 ;
    }
    if( include_down == 0 ) {
        Area2 = 0 ;
    }
    else {
        Area2 = (n - m) * (-Min0) * r2 ;
    }
    return  Area1 + Area2;
}
//二元无穷定积分
double Montecarlo_binary_Infinite( string orifunc , double downx , double upx , double downy , double upy )
{
    double m = downx ;
    double n = upx ;
    double m1 = downy ;
    double n1 = upy ;
    double Max_pointx = m ;
    double Min_pointx = m ;
    double Max_pointy = m1 ;
    double Min_pointy = m1 ;
    double Max0 = binarysolve ( orifunc , Min_pointx , Min_pointy ) ;
    double Min0 = binarysolve ( orifunc , Min_pointx , Min_pointy ) ;
    double delta =  0.001 ;
    double x ;
    double y ;
    double z ;
    double r1 , r2 ;
    double enter_up = 0,include_up = 0,enter_down = 0,include_down = 0 ;
    double Area1 , Area2 ;
    int i ;
    double f ;
     if ( downx < -1000 ) {
        downx = -1000 ;
    }
    if ( upx > 1000 ) {
        upx = 1000 ;
    }
    if ( downy < -1000 ) {
        downy = -1000 ;
    }
    if ( upy > 1000 ) {
        upy = 1000 ;
    }
    //找最大值，最小值及最大值点，最小值点
	if ( ( upx - downx ) / delta  > ( upy - downy ) / delta ) {
    f = ( upx - downx ) / delta ;
	}
	else {
        f = ( upy - downy ) / delta ;
	}
    for ( i = 0 ; i < f; i = i + 1 ) {
        for ( i = 0 ; i < ( upx - downx ) / delta ; i = i + 1 ) {
            if (  binarysolve( orifunc , Min_pointx + delta , Min_pointy + delta ) < Min0 ) {
                Min0 = binarysolve( orifunc , Min_pointx + delta , Min_pointy + delta ) ;
                Min_pointx = Min_pointx + delta ;
                Min_pointy = Min_pointy + delta ;
            }
        }
        for( i = 0 ; i < ( upy - downy ) / delta ; i = i + 1 ) {
            if( binarysolve ( orifunc , Max_pointx + delta , Max_pointy + delta ) > Max0 ) {
                Max0 = binarysolve ( orifunc , Max_pointx + delta , Max_pointy + delta ) ;
                Max_pointx = Max_pointx + delta ;
                Max_pointy = Max_pointy + delta ;
            }
        }
    }

    if ( Max0 >= Min0 && Min0 < 0 ) {
        Min0 = 0 ;
    }
    if ( Max0 >= Min0 && Max0 < 0 ) {
        Max0 = 0 ;
    }
    //产生在规定范围内的随机数
    default_random_engine e ( time(0) ) ;
	uniform_real_distribution<double> u ( m , n ) ;
	srand ( (double)time(NULL) ) ;
    default_random_engine o ( time(0) ) ;
	uniform_real_distribution<double> g ( Min0 , Max0 ) ;
    for ( i = 0 ; i < f ; i++ ) {
	x = u(e);
    y = ( rand() / (double)RAND_MAX ) * ( upy - downy ) + downy ;
    z =g(o);
    //求投点在函数于x轴之间的点数比例r
        if ( z >= 0 ) {
            enter_up = enter_up + 1 ;
            if ( z <= binarysolve( orifunc , x , y ) ) {
                include_up = include_up + 1 ;
          }
        }
        if ( z < 0 ) {
            enter_down = enter_down + 1 ;
            if ( z >= binarysolve( orifunc , x , y ) ) {
                include_down = include_down + 1 ;
            }
        }
    }
        r1 = include_up / enter_up ;
        r2 = include_down / enter_down ;
    //求函数于x轴所围成面积Area = s * r
    if ( include_up == 0 ){
        Area1 = 0;
    }
    else {
        Area1 = (n1 - m1) * (n - m) * Max0 *  r1 ;
    }
    if ( include_down == 0 ){
        Area2 = 0 ;
    }
    else {
        Area2 = (n1 - m1) * (n - m) * (-Min0) * r2 ;
    }
    return Area1 + Area2;
}
//平均值法
//一元有限定积分
double montecarlo( string orifunc , double down , double up )
{
    double m = down ;
    double n = up ;
    double x ;
    double y ;
    double delta = 0.001;
    int i ;
    double value1 = 0 ;
    double value2 = 0 ;
    default_random_engine e ( time(0) ) ;
	uniform_real_distribution<double> u ( m , n ) ;
	for ( i = 0 ; i < (n - m)/delta ; i++ ) {
	x = u(e);
	y = lastsolve( orifunc , u(e) ) ;
	if ( y >= 0 ) {
	value1= value1 + y * ( n - m ) ;
	}
	if ( y < 0 ) {
	value2 = value2 + ( - y ) * ( n - m ) ;
	}
	}
    return value1 + value2  / (n - m)/delta ;
}
//二元有限定积分
double montecarlo_binary(string orifunc,double downx,double upx,double downy,double upy)
{
    double m = downx ;
    double n = upx ;
    double m1 = downy ;
    double n1 = upy ;
    double x ;
    double y ;
    double z ;
   double delta = 0.001;
    int i ;
    double value1 = 0 ;
    double value2 = 0 ;
     double f ;
	if ( ( upx - downx ) / delta  > ( upy - downy ) / delta ) {
    f = ( upx - downx ) / delta ;
	}
	else {
        f = ( upy - downy ) / delta ;
	}
    default_random_engine e ( time(0) ) ;
	uniform_real_distribution<double> u ( m , n ) ;
    srand ( (double)time(NULL) ) ;
	for ( i = 0 ; i < f ; i++ ) {
	x = u(e);
	y = ( rand() / (double)RAND_MAX ) * ( upy - downy ) + downy ;
	z =  binarysolve ( orifunc , x , y ) ;
	if ( z >= 0 ) {
	value1 = value1 + z * ( n - m ) * ( n1 - m1 ) ;
	}
	if ( z < 0 ) {
	value2 = value2 + ( - z ) * ( n - m ) * ( n1 - m1 ) ;
	}
	}
	return value1 + value2 /f;
}

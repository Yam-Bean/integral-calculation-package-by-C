#include"headers.h"

using namespace std;

double Simpson( string orifunc , double down , double up ){
    double minizone = 0.001 , delta = 0 , sum = 0 ;
    double left = down ;
    double right = left + minizone ;
    int i;
    for( i = 1 ; i <= ( up - down ) / minizone ; i ++ ){
        delta =  ((right - left ) / 6.0)*( lastsolve( orifunc , left ) + 4.0 * lastsolve( orifunc , ( left+right) / 2.0 ) + lastsolve( orifunc , right ) );
        sum = sum + delta ;
        left = right ;
        right = left + minizone ;
    }
    return sum ;
}
//固定y的值,计算下限为a，上限为b的x的积分
double fixySimpson_binary( string orifunc , double a , double b , double y ){
    double c,answer;
    c = (a+b)/2.0;
    answer=(binarysolve(orifunc,a,y)+4*binarysolve(orifunc,c,y)+binarysolve(orifunc,b,y))*(b-a)/6.0;
    return answer;
}
//固定y的值,计算下限为a，上限为b的x的更为精确的积分，即自适应辛普森积分
double exact_fy_binary( string orifunc , double a , double b , double y , double esp ){
    double S,L,R,c,answer;
    c=(a+b)/2.0;
    S=fixySimpson_binary( orifunc , a , b , y );
    L=fixySimpson_binary( orifunc , a , c , y );
    R=fixySimpson_binary( orifunc , c , b , y );
    if(abs(L+R-S)<=15.0*esp)//判断是否满足精度
        answer=L+R+(L+R-S)/15.0;
        else answer=exact_fy_binary(orifunc,a,c,y,esp/2.0)+exact_fy_binary(orifunc,c,b,y,esp/2.0);
    return answer;
}
//辛普森公式计算二重积分
double Simpson_binary( string orifunc , double downx , double upx , double downy , double upy , double esp ){
    double midy,answer;
    midy=(upy+downy)/2;
    answer=(exact_fy_binary( orifunc , downx , upx , downy , esp )+4*exact_fy_binary( orifunc , downx , upx , midy , esp )+exact_fy_binary( orifunc , downx , upx , upy , esp ))*(upy-downy)/6;
    return answer;
}
//计算更为精确的二重积分
double exact_Simpson_binary( string orifunc , double downx , double upx , double downy , double upy , double esp ){
    double S,L,R,midy,answer;
    midy=(upy+downy)/2.0;
    S=Simpson_binary( orifunc , downx , upx , downy , upy , esp );
    L=Simpson_binary( orifunc , downx , upx , downy , midy , esp );
    R=Simpson_binary( orifunc , downx , upx , midy , upy , esp );
    if(abs(L+R-S)<=15.0*esp)//判断是否满足精度
        answer=L+R+(L+R-S)/15.0;
        else answer=exact_Simpson_binary( orifunc , downx , upx , downy , midy , esp/2.0 )+exact_Simpson_binary( orifunc , downx , upx , midy , upy , esp/2.0 );
    return answer;
}
//用辛普森法计算一元瑕积分
double Point::impro_Simpson( string orifunc , double down , double up ){
    double answer = 0 ;
    double ase = 0.001 ;
    double anothermid ;
    int i ,time = 1;
    vector<double> test ;
    if( storepoint.size() != 0 ){
         double sizeori =  storepoint.size() ;
    if( storepoint[0] == down){
        if( storepoint [sizeori - 1] == up){
            for( i = 0 ; i < sizeori - 1 ; i++ ){
                while( time < 9 ){
                    anothermid = Simpson( orifunc , storepoint[i] + ase , storepoint[i+1] - ase ) ;
                    if( !isinf( anothermid ) )
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
                    anothermid = Simpson( orifunc , storepoint[i] + ase , storepoint[i+1] - ase ) ;
                    if( !isinf( anothermid ) )
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
                    anothermid = Simpson( orifunc , storepoint[sizeori - 1] + ase , up ) ;
                    if( !isinf( anothermid ) )
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
                    anothermid = Simpson( orifunc , storepoint[i] + ase , storepoint[i+1] - ase ) ;
                    if( !isinf( anothermid ) )
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
                    anothermid = Simpson( orifunc , down , storepoint[0] - ase ) ;
                    if( !isinf( anothermid ) )
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
                    anothermid = Simpson( orifunc , storepoint[i] + ase , storepoint[i+1] - ase ) ;
                    if( !isinf( anothermid ) )
                    test.push_back(anothermid) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                answer = answer + test[test.size()-1];
                test.clear();
            }
                while( time < 9 ){
                    anothermid = Simpson( orifunc , storepoint[sizeori - 1] + ase , up ) ;
                    if( !isinf( anothermid ) )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                answer = answer + test[test.size()-1];
                test.clear();
                while( time < 9 ){
                    anothermid = Simpson( orifunc , down , storepoint[0] - ase ) ;
                    if( !isinf( anothermid ) )
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
    return answer;
}

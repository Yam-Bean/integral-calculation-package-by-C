#include"headers.h"
using namespace std;

int Point::point( string orifunc , double down , double up ){
    int i , sizeori , time = 1 , j ;
    int flag = 1 ;
    int pin ;
    double minizone = 0.001 , copies , answer ,mid ,anothermid ;
    double number = down ;
    double ase = 0.001 ;
    vector<double> test ;
    string::size_type idx ;
    answer = 0 ;
    copies = (up - down ) / minizone ;

    for( i = 0 ; i <= copies ; i ++ ){
        idx=orifunc.find("tan");//在orifunc中查找tan函数
        if(idx == string::npos )//不存在。
           pin = 3000000 ;
         else//存在。
           pin = 1000 ;
        if ( lastsolve( orifunc , number ) > pin || lastsolve( orifunc , number ) < -pin ){
            storepoint.push_back( number ) ;
            number = number + 0.1 ;
        }
        else
            number = number + minizone ;
    }
    number = down;
    if( storepoint.size() != 0 ){
         sizeori =  storepoint.size() ;
    if( storepoint[0] == down){
        if( storepoint [sizeori - 1] == up){
            for( i = 0 ; i < sizeori - 1 ; i++ ){
                while( time < 9 ){
                    anothermid = Definition( orifunc , storepoint[i] + ase , storepoint[i+1] - ase ) ;
                    if( !isinf( anothermid ) )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                for( j = 0 ; j < test.size() - 1 ; j ++ ){
                    if( abs( test[j + 1] - test[j] ) > abs( test[j] ) )
                        flag = 0 ;
                }
                mid = Definition( orifunc , storepoint[i] + 0.001 , storepoint[i+1] - 0.001 ) ;
                answer = answer + mid ;

                test.clear();
            }
        }
        else{
            for( i = 0 ; i < sizeori - 2 ; i ++ ){
                while( time < 9 ){
                    anothermid = Definition( orifunc , storepoint[i] + ase , storepoint[i+1] - ase ) ;
                    if( !isinf( anothermid ) )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;

                }
                ase = 0.001 ;
                time = 1 ;
                for( j = 0 ; j < test.size() - 1 ; j ++ ){
                    if( abs( test[j + 1] - test[j]) > abs( test[j] ) )
                        flag = 0 ;
                }
                mid = Definition( orifunc , storepoint[i] + 0.001 , storepoint[i+1] - 0.001 ) ;
                answer = answer + mid ;
                test.clear();
            }
            answer = answer + Definition( orifunc , storepoint[sizeori - 1] +0.0000001 , up ) ;
            while( time < 9 ){
                    anothermid = Definition( orifunc , storepoint[sizeori - 1] + ase , up ) ;
                    if( !isinf( anothermid ) )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
            ase = 0.001 ;
            time = 1 ;
            for( j = 0 ; j < test.size() - 1 ; j ++ ){
                    if( fabs( test[j+1] - test[j] ) > fabs( test[j] ) )
                        flag = 0 ;
            }
            test.clear();
        }
    }
    else if( storepoint[sizeori - 1] == up ){
            for( i = 1 ; i < sizeori - 1 ; i ++ ){
                while( time < 9 ){
                    anothermid = Definition( orifunc , storepoint[i] + ase , storepoint[i+1] - ase ) ;
                    if( !isinf( anothermid ) )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                for( j = 0 ; j < test.size() - 1 ; j ++ ){
                    if( abs(test[j + 1] - test[j] ) > abs(test[j]) )
                        flag = 0 ;
                }
                mid = Definition( orifunc , storepoint[i] + 0.001 , storepoint[i+1] - 0.001 ) ;
                answer = answer + mid ;
                test.clear();
            }
            answer = answer + Definition( orifunc , down , storepoint[0] -0.001 ) ;
            while( time < 9 ){
                    anothermid = Definition( orifunc , down , storepoint[0] - ase ) ;
                    if( !isinf( anothermid ) )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
            ase = 0.001 ;
            time = 1 ;
            for( j = 0 ; j < test.size() - 1 ; j ++){
                    if( abs( test[j + 1] - test[j] ) > abs( test[j] ) )
                        flag = 0 ;
                }
            test.clear();
        }
    else{
            for(i = 1 ; i < sizeori - 2 ; i ++ ){
                while( time < 9 ){
                    anothermid = Definition( orifunc , storepoint[i] + ase , storepoint[i+1] - ase ) ;
                    if( !isinf( anothermid ) )
                    test.push_back(anothermid) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                for( j = 0 ; j < test.size() - 1 ; j ++ ){
                    if( abs( test[j + 1] - test[ j ] ) > abs( test[ j ] ) )
                        flag = 0 ;
                }
                mid = Definition( orifunc , storepoint[i] +0.001 , storepoint[i+1] - 0.001 ) ;
                answer = answer + mid ;
                test.clear();
            }
            answer = answer + Definition( orifunc , storepoint[sizeori - 1] + 0.001 , up ) + Definition( orifunc , down , storepoint[0] - 0.001 ) ;
                while( time < 9 ){
                    anothermid = Definition( orifunc , storepoint[sizeori - 1] + ase , up ) ;
                    if( !isinf( anothermid ) )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                for( j = 0 ; j < test.size() - 1 ; j ++ ){
                    if( abs( test[j + 1] - test[j] ) > abs( test[j] ) )
                        flag = 0 ;
                }
                test.clear();
                while( time < 9 ){
                    anothermid = Definition( orifunc , down , storepoint[0] - ase ) ;
                    if( !isinf( anothermid ) )
                    test.push_back( anothermid ) ;
                    ase = ase * 0.1 ;
                    time ++ ;
                }
                ase = 0.001 ;
                time = 1 ;
                for( j = 0 ; j < test.size() - 1 ; j ++ ){
                    if( abs( test[j + 1] - test[j] ) > abs( test[j] ) )
                        flag = 0 ;
                }
                test.clear();
    }
    }

        if( storepoint.size() == 0 )
        return 0;
        if( flag == 0  ) {//瑕积分发散
                return 1;
            }
            else {//瑕积分收敛
                return 2;
            }
    }


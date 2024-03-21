#include"headers.h"
using namespace std;

bool judge(char c) //判断字符c是否为数值或小数点
{
    if( c >= '0' && c <= '9' || c == '.')
        return true ;
    else
        return false ;
}
double solve( string orifunc , double x ) //解决加减乘除次方和e的运算和负数的运算
{
    int i , j , k , flag , a ;
    double decimal , temp ;
    char transferx[6] , transfere[12] , transferp[1222] , F ;
    string operat ;//储存运算符
    vector<double> number;//储存double型数字

    sprintf( transferx , "%f" , x );//将double型数字转换为char型数字，储存在transferx中
    sprintf( transfere , "%f" , 2.71828 );//将e型数字转换为char型数字，储存在transfere中
    sprintf( transferp , "%f" , 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280);
    for( i = 0 ; orifunc[i] != '\0' ; i++){
        if( orifunc[i] == 'x' ){
            orifunc.insert( i + 1 , transferx );
            orifunc.erase( i , 1 );
        }//将orifunc中的x替换为储存在transferx中的char型数字
        if( orifunc[i] == 'e' ){
            orifunc.insert( i+1 , transfere );
            orifunc.erase( i , 1 );
        }//将orifunc中的e替换为储存在transfere中的char型数字
        if( orifunc[i] == 'p' ){
            orifunc.insert( i+1 , transferp );
            orifunc.erase( i , 1 );
      }
    }
        if( orifunc[0] == '-' )
            orifunc.insert(orifunc.begin(),'0');
        i = 0 ;
    while( orifunc[i] != '\0' ){
        double sum = 0 ;
        flag = 0 ;
        if( !judge(orifunc[i]) ){
            if( judge( orifunc[i-1] ) ){
            operat.push_back( orifunc[i] ) ;
            i ++ ;
            }
            else{
            flag = 1 ;
            i ++ ;
            }
        }
        a = i ;
        while( judge (orifunc[i]) ) { //如果是数值，将char转化为double并储存在number中
            if( orifunc[i] >= '0' && orifunc[i] <= '9' ) { //计算整数部分，将整数部分的char转换为double，并暂存在sum中
                sum = sum * 10 + ( orifunc[i] - 48 ) ;
                i++ ;
            }
            else if( orifunc[i] == '.' ) //计算小数部分，将小数部分的char转换为double，并暂存在decimal/j中
            {
                int j = 1 ;
                decimal = 0 ;
                i++ ;
                while( judge ( orifunc[i] ) )
                {
                    decimal = decimal * 10 + ( orifunc[i] - 48 ) ;
                    j = j * 10.0 ;
                    i++ ;
                }
                sum = sum + decimal / j ;//整数部分和小数部分求和，得到数字
            }
        }
        if( judge( orifunc[a] ) ){
        if( flag ) sum = - sum ;
        number.push_back( sum ) ;}//将得到的数字储存在number数组中
    }
    for( k = 0 ; k < operat.size() ; k++ ) {
        for( i = 0 ; i < operat.size() ; i++ ) {
            if( operat[i] == '^' ) {
                temp = pow ( number[i] , number[i+1] ) ;
                number[i] = temp ;
                for( j = i+1 ; j < number.size() ; j++ )
                    number[j] = number[j+1] ;
                for( j = i ; j < operat.size() ; j++ )
                    operat[j] = operat[j+1] ;
            }
        }
    }
    for( k = 0 ; k < operat.size() ; k++ ) {
        for( i = 0 ; i < operat.size() ; i++ ) {
            if( operat[i] == '*' ) {
                temp = number[i] * number[i+1] ;
                number[i] = temp ;
                for( j = i+1 ; j < number.size() ; j++ )
                    number[j] = number[j+1] ;
                for( j = i ; j < operat.size() ; j++ )
                    operat[j] = operat[j+1] ;
            }
            if( operat[i] == '/' ) {
                temp = number[i] / number[i+1] ;
                number[i] = temp ;
                for( j = i+1 ; j < number.size() ; j++ )
                    number[j] = number[j+1] ;
                for( j = i ; j < operat.size() ; j++)
                    operat[j] = operat[j+1] ;
            }
        }
    }
    for( k = 0 ; k < operat.size() ; k++ ) {
        for( i = 0 ; i < operat.size() ; i++ ) {
            if( operat[i] == '+' ) {
                temp = number[i] + number[i+1] ;
                number[i] = temp ;
                for( j = i + 1 ; j < number.size(); j++ )
                    number[j] = number[j+1];
                for( j = i ; j < operat.size() ; j++ )
                    operat[j] = operat[j+1] ;
            }
            if(operat[i] == '-')
            {
                temp = number[i] - number[i+1] ;
                number[i] = temp ;
                for( j = i + 1 ; j < number.size() ; j++ )
                    number[j] = number[j+1] ;
                for( j = i ; j < operat.size() ; j++ )
                    operat[j] = operat[j+1] ;
            }
        }
    }
    operat.clear() ;
    return number[0] ;
}
string tritransfer( double mid , string orifunc , int lefthalf , int righthalf )//计算三角函数和反三角函数并将结果替换为string
{
    int h ;
    char transfermid[6] , value[6] ;
    string check , doublecheck ;
    double trivalue ;
    sprintf( transfermid , "%f" , mid );
    for( h = lefthalf - 4 ; h < lefthalf ; h++ )
        check.push_back( orifunc[h] ) ;//前四个字符存入check中以判断是否为asin/acos/atan
    for( h = lefthalf - 3 ; h < lefthalf ; h++ )
        doublecheck.push_back( orifunc[h] ) ;
    if( check == "asin" ){
        trivalue = asin( mid ) ;//计算括号内mid数值的反三角函数值，并保存在double型trivalue中
        sprintf( value , "%f" , trivalue ) ;//将double型trivalue转换为char型value。但此时"asin("")"均未从orifunc中清除
        orifunc = orifunc.insert( righthalf + 1 , value ) ;
        orifunc = orifunc.erase( lefthalf-4 , righthalf - lefthalf + 5 ) ;//用value替换orifunc中“asin(mid)"
        check.clear() ;//清空check函数，防止重复计算sin值
        doublecheck.clear() ;
    }
    else if( check == "acos" ){
        trivalue = acos( mid ) ;
        sprintf( value , "%f" , trivalue ) ;
        orifunc = orifunc.insert( righthalf + 1 , value ) ;
        orifunc = orifunc.erase( lefthalf-4 , righthalf - lefthalf + 5 ) ;
        check.clear() ;
        doublecheck.clear() ;
    }
    else if( check == "atan" ){
        trivalue = atan( mid ) ;
        sprintf( value , "%f" , trivalue ) ;
        orifunc = orifunc.insert( righthalf + 1 , value ) ;
        orifunc = orifunc.erase( lefthalf-4 , righthalf - lefthalf + 5 ) ;
        check.clear() ;
        doublecheck.clear() ;
    }
    else if( doublecheck == "sin" ) {
        trivalue = sin( mid ) ;
        sprintf( value , "%f" , trivalue ) ;
        orifunc = orifunc.insert( righthalf + 1 , value ) ;
        orifunc = orifunc.erase( lefthalf-3 , righthalf - lefthalf + 4 ) ;
        check.clear() ;
        doublecheck.clear() ;
    }
    else if( doublecheck == "cos" ) {
        trivalue = cos( mid ) ;
        sprintf( value , "%f" , trivalue ) ;
        orifunc = orifunc.insert( righthalf + 1 , value ) ;
        orifunc = orifunc.erase( lefthalf-3 , righthalf - lefthalf + 4 ) ;
        check.clear() ;
        doublecheck.clear() ;
    }
    else if( doublecheck == "tan" ) {
        trivalue = tan( mid ) ;
        sprintf( value , "%f" , trivalue ) ;
        orifunc = orifunc.insert( righthalf + 1 , value ) ;
        orifunc = orifunc.erase( lefthalf-3 , righthalf - lefthalf + 4 ) ;
        check.clear() ;
        doublecheck.clear() ;
    }
    else{
        orifunc = orifunc.insert( righthalf + 1 , transfermid ) ;
        orifunc = orifunc.erase( lefthalf , righthalf - lefthalf + 1 ) ;
        check.clear() ;
        doublecheck.clear() ;
    }
    return orifunc ;
}
string logtransfer( double lmid , double rmid , string orifunc , int lefthalf , int righthalf )//计算三角函数和反三角函数并将结果替换为string
{
    int h ;
    char transferlmid[6] , transferrmid[6] , value[12] ;
    string check , infvalue;
    double logvalue ;
    sprintf( transferlmid , "%f" , lmid ) ;
    sprintf( transferrmid , "%f" , rmid ) ;
    for( h = lefthalf - 3 ; h < lefthalf ; h++ )
        check.push_back( orifunc[h] ) ;
    if( check != "log" )
        cout << "输入有误！" ;
    if( lmid == 2.71828 )
        logvalue = log( rmid );
    else if( lmid == 10 )
        logvalue = log10( rmid ) ;
    else
        logvalue = log(rmid)/log(lmid) ;
    if (isinf(logvalue)){
        orifunc = orifunc.insert( righthalf + 1 , "1000000000000" ) ;
        orifunc = orifunc.erase( lefthalf - 3 , righthalf - lefthalf + 4 ) ;
    }
    else if (isinf(-logvalue)){
        orifunc = orifunc.insert( righthalf + 1 , "-1000000000000" ) ;
        orifunc = orifunc.erase( lefthalf - 3 , righthalf - lefthalf + 4 ) ;
    }
    else{
        sprintf( value , "%f" , logvalue ) ;
        orifunc = orifunc.insert( righthalf + 1 , value ) ;
        orifunc = orifunc.erase( lefthalf - 3 , righthalf - lefthalf + 4 ) ;
    }
    check.clear() ;
    return orifunc ;
}
string transfer( int j, double x, int lefthalf, int righthalf, string orifunc )//用于判断是用log函数还是其他函数并计算，经计算结果替换为strign
{
    double lmid , rmid ;
    string lhfunction , rhfunction ;//用于保存括号内的字符函数
    while( orifunc[j] != ',' && j < righthalf ){
        lhfunction.push_back( orifunc[j] ) ;
        j++;
    }//碰不到，和）时
    lmid = solve( lhfunction , x ) ;

    if( orifunc[j] == ',' ){
        j++;
        while( j < righthalf ){
            rhfunction.push_back( orifunc[j] ) ;
            j++ ;
        }//如果碰到",",在碰到）之前都存入rhfunction中
        rmid = solve( rhfunction , x ) ;
        orifunc = logtransfer( lmid , rmid , orifunc , lefthalf , righthalf ) ;
    }//碰到","时
    else
        orifunc = tritransfer( lmid , orifunc , lefthalf , righthalf ) ;
    lhfunction.clear() ;
    rhfunction.clear() ;
    return orifunc ;
}
double mainsolve( string orifunc , double x )//在solve的基础上计算括号、三角函数、对数函数
{
    int i , j , g , lefthalf , righthalf ;
    double lmid , rmid ;
    for(g = 0 ; g < orifunc.size() ; g++ ){
    for(i = 0 ; i < orifunc.size() ; i++){
        if( orifunc[i] == '(' ){
           lefthalf = i ;
           j = i + 1 ;
           while( orifunc[j] != ')' ){
            j++ ;
            righthalf = j ;
           }
    orifunc = transfer( i + 1 , x , lefthalf , righthalf , orifunc ) ;
    break ;
        }//if find"("
    }
    }
    for( g = 0 ; g < orifunc.size() ; g++ ){
    for( i = 0 ; i < orifunc.size() ; i++){
        if( orifunc[i] == '[' ){
           lefthalf = i ;
           j = i + 1 ;
           while( orifunc[j] != ']' ){
            j++ ;
            righthalf = j ;
           }
    orifunc = transfer( i + 1 , x , lefthalf , righthalf , orifunc ) ;
    break ;
        }
    }
    }
    for( g = 0 ; g < orifunc.size() ; g++ ){
    for( i = 0 ; i < orifunc.size() ; i++){
        if( orifunc[i] == '{' ){
           lefthalf = i ;
           j = i + 1 ;
           while( orifunc[j] !='}' ){
            j++ ;
            righthalf = j ;
           }
     orifunc = transfer( i + 1 , x , lefthalf , righthalf , orifunc ) ;
     break ;
        }//if find"("
    }
    }
    double answer = solve( orifunc , x ) ;
    return answer ;

    }
double lastsolve( string orifunc , double x ) //在mainsolve的基础上计算绝对值
{
    int i , j , k , leftabs , rightabs ;
    double absmid , answer;
    string absfunction;
    for(k = 0; k < orifunc.size(); k++) {
        for(i = 0; i < orifunc.size(); i++) {
            if(orifunc[i] == '|') {
                leftabs = i ;
                j = i + 1 ;
                while( orifunc[j] != '|' ) {
                    absfunction.push_back( orifunc[j] ) ;
                    j++ ;
                    rightabs = j ;
                }
                absmid = mainsolve( absfunction , x ) ;
                orifunc = abstransfer( absmid , orifunc , leftabs , rightabs ) ;
                absfunction.clear() ;
                break ;
            }//if find"|"
        }
    }
    answer = mainsolve( orifunc , x );
    return answer;
}
string abstransfer( double absmid , string orifunc , int leftabs , int rightabs )//计算绝对值并将结果替换为string
{
    char value[6] ;
    double absvalue ;
    absvalue = abs( absmid ) ;//计算括号内absmid数值的绝对值，并保存在double型absvalue中
    sprintf( value , "%f" , absvalue ) ;//将double型absvalue转换为char型value。但此时"|"未从orifunc中清除
    orifunc = orifunc.insert( rightabs + 1 , value ) ;
    orifunc = orifunc.erase( leftabs , rightabs - leftabs + 1 ) ;
    return orifunc ;
}
double binarysolve( string orifunc , double x , double y )//计算二元函数值
{
    int i ;
    double answer ;
    char transfery[6] , transfere[12] , transferp[12] ;
    sprintf( transfery , "%f" , y ) ;//将double型数字转换为char型数字，储存在transferx中
    for(i = 0 ; orifunc[i] != '\0'; i++){
        if(orifunc[i] == 'y'){
            orifunc.insert( i + 1 , transfery ) ;
            orifunc.erase( i , 1 ) ;
        }//将orifunc中的y替换为储存在transfery中的char型数字
    }
    answer = lastsolve( orifunc , x ) ;
    return answer ;
}

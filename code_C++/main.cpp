#include"headers.h"


using namespace std;
int main()
{
    system("color F0");
    Point P;
    ofstream fout;
    string path = "C:\\Users\\HP\\Desktop\\output.txt";
    fout.open(path,ios::app);
    double test , sim , Answer;
    int i ;
    int a ;
    SYSTEMTIME time;
    GetLocalTime(&time);//local time
    //GetSystemTime(&ct);//GMT time
    fout << "\n\t————————使用时间为："
         << time.wYear << "年"
         << setfill('0') << setw(2)<< time.wMonth << "月"
         << setfill('0') << setw(2)<< time.wDay << "日  "
         << setfill('0') << setw(2) << time.wHour << "时"
         << setfill('0') << setw(2) << time.wMinute << "分"
         << setfill('0') << setw(2) << time.wSecond << "秒————————\n\n" ;
    int flag_letter = 0 ,flag_point;
    char push;
    bool check1 = true , check2 = true ;
    string option , orifunc;
    string   m , n ,m1 ,n1  ;
    double trim , trin , trim1 , trin1  ;
     cout << "\n\n\n"
         << "                  ------------------------------------------------------------------------\n"
         << "                  |                                                                      |\n"
         << "                  |                             定积分计算包                             |\n"
         << "                  |                                                                      |\n"
         << "                  |    --------------------------------------------------------------    |\n"
         << "                  |                                                                      |\n"
         << "                  |                       恭喜你发现了一个宝藏程序！                     |\n"
         << "                  |                                                                      |\n"
         << "                  |                       还在为求解定积分而苦恼吗？                     |\n"
         << "                  |                                                                      |\n"
         << "                  |                从此不必忧愁，本程序将带你畅游积分的海洋！            |\n"
         << "                  |                                                                      |\n"
         << "                  |                     请输入任意键开始你的积分之旅！                   |\n"
         << "                  |                                                                      |\n"
         << "                  ------------------------------------------------------------------------\n\n";
         getch();
         system("cls");
    while( check1 ){
        check2 = true;
        GetLocalTime(&time);
    cout << "\n\n\n"
         << "                  ------------------------------------------------------------------------\n"
         << "                  |                                                                      |\n"
         << "                  |                       "<< time.wYear << "年" << setfill('0') << setw(2)<< time.wMonth << "月" << setfill('0') << setw(2)<< time.wDay << "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2)<< time.wMinute << "分                       |\n"
         << "                  |                                                                      |\n"
         << "                  |    --------------------------------------------------------------    |\n"
         << "                  |                                                                      |\n"
         << "                  |                       欢迎使用定积分计算包！                         |\n"
         << "                  |                                                                      |\n"
         << "                  |                      请选择你想实现的功能：                          |\n"
         << "                  |                                                                      |\n"
         << "                  |                        1.计算一元函数定积分                          |\n"
         << "                  |                        2.计算二元函数定积分                          |\n"
         << "                  |                        3.退出系统                                    |\n"
         << "                  |                                                                      |\n"
         << "                  ------------------------------------------------------------------------\n\n"
         << "                                         请在此输入序号进行选择：";
    option.clear();
    cin >> push ;
    option.push_back(push);
    system("cls");
    //一元定积分：
    if( option[0] == '1'){
        while( check2 ){
            GetLocalTime(&time);
            cout << "\n\n\n                                          "<< time.wYear << "年" << setfill('0') << setw(2)<< time.wMonth << "月" << setfill('0') << setw(2)<< time.wDay << "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                 << "                  ------------------------------------------------------------------------\n"
                 << "                  |                                                                      |\n"
                 << "                  |                      输入规则如下，请按规则输入！                    |\n"
                 << "                  |                                                                      |\n"
                 << "                  |        1.只能实现+、-、*、/、^、()、[]、{}、||、log(,)、sin()、      |\n"
                 << "                  |                  cos()、tan()、asin()、acos()、atan()、运算          |\n"
                 << "                  |        2.log(,)函数使用规则为：log(底数,真数)                        |\n"
                 << "                  |        3.同级括号、绝对值号不能嵌套，括号必须成对出现                |\n"
                 << "                  |        4.所有符号必须用英文输入                                      |\n"
                 << "                  |        5.一元函数请用x表示自变量，二元函数请用x、y表示自变量         |\n"
                 << "                  |        6.不能计算无穷积分                                            |\n"
                 << "                  |                                                                      |\n"
                 << "                  ------------------------------------------------------------------------\n\n"
                 << "                           请在此输入一元函数：";
            orifunc.clear();
            cin >> orifunc;
            fout << "\t\t【计算一元函数定积分】\n\n"
                 << "\t\t函数表达式：" << orifunc <<"\n";
            flag_letter = 0 ;
            for( i = 0 ; i < orifunc.size() ; i ++ ){
                if ( orifunc[i] == 'y' )
                    flag_letter ++ ;
            }
            //在一元时错误输入二元：
            if ( flag_letter != 0 ){
                system("cls");
                GetLocalTime(&time);
                cout << "\n\n\n                                          "<< time.wYear << "年" << setfill('0') << setw(2)<< time.wMonth << "月" << setfill('0') << setw(2)<< time.wDay << "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                     << "                  ------------------------------------------------------------------------\n"
                     << "                  |                                                                      |\n"
                     << "                  |                                Warning!                              |\n"
                     << "                  |                                                                      |\n"
                     << "                  |                      您在一元函数中输入了二元函数！                  |\n"
                     << "                  |                                                                      |\n"
                     << "                  |                       1.重新输入一元函数                             |\n"
                     << "                  |                       2.回到首页重新选择二元函数                     |\n"
                     << "                  |                       3.退出系统                                     |\n"
                     << "                  |                                                                      |\n"
                     << "                  |                                                                      |\n"
                     << "                  ------------------------------------------------------------------------\n\n"
                     << "                                         请在此输入序号进行选择：";
                fout << "\n\t\t您在一元函数中输入了二元函数！\n\n"
                     << "\t\t\t——————本次运算结束！——————\n\n";
                cin >> push ;
                while( option.size()>1 )
                    option.pop_back();
                option.push_back(push);
                flag_letter = 0;
                if( option[1] == '1' );
                else if( option[1] == '2' )
                    check2 = false;
                else if( option[1] == '3' ){
                    check1 = false;
                    check2 = false;
                }
                system("cls");
            }
            //正确输入一元函数：
            else if( flag_letter == 0){
                cout << "\n                           请输入积分下限：";
                cin >> m ;
                cout << "\n                           请输入积分上限：";
                cin >> n ;
                fout << "\t\t积分下限：" << m << "\n"
                     << "\t\t积分上限：" << n << "\n";
                trim = solve( m , 1 );
                trin = solve( n , 1 );
                flag_point = P.point ( orifunc , trim , trin );
                //输入的一元函数无瑕点：
                if( flag_point == 0 ){
                    GetLocalTime(&time);
                    system("cls");
                    cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << setfill('0') << setw(2)<< time.wDay << "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                函数表达式为：" << orifunc << endl
                         << "                                积分下限为：  " << m << endl
                         << "                                积分上限为：  " << n << endl
                         << "                                定积分类型为：一元正常积分                                \n\n";
                    fout << "\t\t\t定积分类型为：一元正常积分\n\n";
                    cout << "                  ------------------------------------------------------------------------\n"
                         << "                  |                                                                      |\n"
                         << "                  |                    请选择你想实现的算法：                            |\n"
                         << "                  |                                                                      |\n"
                         << "                  |                      1.定义法                                        |\n"
                         << "                  |                      2.梯形法                                        |\n"
                         << "                  |                      3.辛普森算法                                    |\n"
                         << "                  |                      4.蒙特卡洛投点法                                |\n"
                         << "                  |                      5.蒙特卡洛平均值法                              |\n"
                         << "                  |                      6.退出系统                                      |\n"
                         << "                  |                                                                      |\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                     请在此输入序号进行选择：";
                    cin >> push ;
                    while( option.size()>1 )
                         option.pop_back();
                    option.push_back(push);
                    system("cls");
                    //选用1.定义法求解一元正常积分
                    if( option[1] == '1'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << setfill('0') << setw(2)<< time.wMonth << "月" << setfill('0') << setw(2)<< time.wDay << "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为：" << orifunc << endl
                             << "                                积分下限为：  " << m << endl
                             << "                                积分上限为：  " << n << endl
                             << "                                定积分类型为：一元正常积分                                \n\n";
                        Answer = Definition( orifunc , trim , trin);
                        cout << "                                通过定义法求得积分值为：" << Answer;
                        fout << "\t\t\t用定义法求得一元积分值为：" << Answer <<"\n\n"
                             << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                             << "                  ------------------------------------------------------------------------\n"
                             << "                  |                                                                      |\n"
                             << "                  |                        请选择你想进行的操作：                        |\n"
                             << "                  |                                                                      |\n"
                             << "                  |                          1.回到首页                                  |\n"
                             << "                  |                          2.退出系统                                  |\n"
                             << "                  |                                                                      |\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                          请在此输入序号进行选择：";
                        cin >> push ;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            system("cls");
                        }
                    }
                    //选用2.梯形法求解
                    else if( option[1] == '2'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为：" << orifunc << endl
                             << "                                积分下限为：  " << m << endl
                             << "                                积分上限为：  " << n << endl
                             << "                                定积分类型为：一元正常积分                                \n\n";
                        Answer = Trapezoid( orifunc , trim , trin);
                        cout << "                                通过梯形法求得积分值为：" << Answer;
                        fout << "\t\t\t用梯形法求得一元积分值为：" << Answer <<"\n\n"
                             << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                             << "                  ------------------------------------------------------------------------\n"
                             << "                  |                                                                      |\n"
                             << "                  |                        请选择你想进行的操作：                        |\n"
                             << "                  |                                                                      |\n"
                             << "                  |                          1.回到首页                                  |\n"
                             << "                  |                          2.退出系统                                  |\n"
                             << "                  |                                                                      |\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                          请在此输入序号进行选择：";
                        cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            system("cls");
                        }
                    }
                    //选用3.辛普森算法求解
                    else if( option[1] == '3'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << setfill('0') << setw(2)<< time.wDay << "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为：" << orifunc << endl
                             << "                                积分下限为：  " << m << endl
                             << "                                积分上限为：  " << n << endl
                             << "                                定积分类型为：一元正常积分                                \n\n";

                        Answer = Simpson( orifunc , trim , trin);
                        cout << "                                通过辛普森算法求得积分值为：" << Answer;
                        fout << "\t\t\t用辛普森算法求得一元积分值为：" << Answer <<"\n\n"
                             << "\t\t\t——————本次运算结束！——————\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                             << "                  ------------------------------------------------------------------------\n"
                             << "                  |                                                                      |\n"
                             << "                  |                        请选择你想进行的操作：                        |\n"
                             << "                  |                                                                      |\n"
                             << "                  |                          1.回到首页                                  |\n"
                             << "                  |                          2.退出系统                                  |\n"
                             << "                  |                                                                      |\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                          请在此输入序号进行选择：";
                       cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            system("cls");
                        }
                    }
                    //选用4.蒙特卡洛投点法
                    else if( option[1] == '4'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为：" << orifunc << endl
                             << "                                积分下限为：  " << m << endl
                             << "                                积分上限为：  " << n << endl
                             << "                                定积分类型为：一元正常积分                                \n\n";
                        Answer = Montecarlo( orifunc , trim , trin);
                        cout << "                                通过蒙特卡洛投点法求得积分值为：" << Answer;
                        fout << "\t\t\t用蒙特卡洛投点法求得一元积分值为：" << Answer <<"\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                             << "                  ------------------------------------------------------------------------\n"
                             << "                  |                                                                      |\n"
                             << "                  |                        请选择你想进行的操作：                        |\n"
                             << "                  |                                                                      |\n"
                             << "                  |                          1.回到首页                                  |\n"
                             << "                  |                          2.退出系统                                  |\n"
                             << "                  |                                                                      |\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                          请在此输入序号进行选择：";
                        cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            system("cls");
                        }
                    }
                    //选用5.蒙特卡洛平均值法求解
                    else if( option[1] == '5'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为：" << orifunc << endl
                             << "                                积分下限为：  " << m << endl
                             << "                                积分上限为：  " << n << endl
                             << "                                定积分类型为：一元正常积分                                \n\n";
                        Answer = montecarlo( orifunc , trim , trin);
                        cout << "                                通过蒙特卡洛平均值法求得积分值为：" << Answer;
                        fout << "\t\t\t用蒙特卡洛平均值法求得一元积分值为：" << Answer <<"\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                             << "                  ------------------------------------------------------------------------\n"
                             << "                  |                                                                      |\n"
                             << "                  |                        请选择你想进行的操作：                        |\n"
                             << "                  |                                                                      |\n"
                             << "                  |                          1.回到首页                                  |\n"
                             << "                  |                          2.退出系统                                  |\n"
                             << "                  |                                                                      |\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                          请在此输入序号进行选择：";
                       cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            system("cls");
                        }
                    }
                    //6.退出系统
                    else if( option[1] == '6' ){
                            check1 = false;
                            check2 = false;
                            system("cls");
                        }
                }
                //一元瑕积分，且瑕积分发散
                else if( flag_point == 1 ){
                    system("cls");
                    GetLocalTime(&time);
                    cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                函数表达式为：" << orifunc << endl
                         << "                                积分下限为：  " << m << endl
                         << "                                积分上限为：  " << n << endl
                         << "                                定积分类型为：一元瑕积分，且瑕积分发散，积分值为无穷\n";
                    fout << "\t\t定积分类型为：一元瑕积分，且瑕积分发散，积分值为无穷\n";
                    if( P.storepoint.size() == 1 ){
                        cout <<"                                瑕点在" << P.storepoint[0] << "附近\n\n" ;
                        fout <<"\t\t瑕点在" << P.storepoint[0] << "附近\n\n" ;
                    }
                    else if( P.storepoint.size() >= 1 ){
                        for( i = 0 ; i < P.storepoint.size() ; i ++ )
                        cout << "                                第" << i+1 <<"个瑕点在" << P.storepoint[i] << "附近\n" ;
                        fout << "\t\t第" << i+1 <<"个瑕点在" << P.storepoint[i] << "附近\n" ;
                    }
                    fout << "\t\t\t——————本次运算结束！——————\n\n";
                    cout << "\n\n"
                         << "                  ------------------------------------------------------------------------\n"
                         << "                  |                                                                      |\n"
                         << "                  |                        请选择你想进行的操作：                        |\n"
                         << "                  |                                                                      |\n"
                         << "                  |                          1.回到首页                                  |\n"
                         << "                  |                          2.退出系统                                  |\n"
                         << "                  |                                                                      |\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                          请在此输入序号进行选择：";
                        cin >> push ;
                        while( option.size()>1 )
                         option.pop_back();
                        option.push_back(push);
                        if( option[1] == '1'){
                            check2 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                        else if ( option[1] == '2' ){
                            check1 = false;
                            check2 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                }
                //一元瑕积分，且瑕积分收敛：
                else if( flag_point == 2 ){
                    system("cls");
                    GetLocalTime(&time);
                    cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                函数表达式为：" << orifunc << endl
                         << "                                积分下限为：  " << m << endl
                         << "                                积分上限为：  " << n << endl
                         << "                                定积分类型为：一元瑕积分，且瑕积分收敛\n";
                    fout << "\t\t定积分类型为：一元瑕积分，且瑕积分收敛\n";
                            if( P.storepoint.size() == 1 ){
                                cout <<"                                瑕点在" << P.storepoint[0] << "附近\n\n" ;
                                fout <<"\t\t瑕点在" << P.storepoint[0] << "附近\n\n" ;
                            }
                            else if( P.storepoint.size() >= 1 ){
                                for( i = 0 ; i < P.storepoint.size() ; i ++ )
                                    cout << "                                第" << i+1 <<"个瑕点在" << P.storepoint[i] << "附近\n" ;
                                fout << "\t\t第" << i+1 <<"个瑕点在" << P.storepoint[i] << "附近\n\n" ;
                            }
                    cout << "                  ------------------------------------------------------------------------\n"
                         << "                  |                                                                      |\n"
                         << "                  |                    请选择你想实现的算法：                            |\n"
                         << "                  |                                                                      |\n"
                         << "                  |                      1.定义法                                        |\n"
                         << "                  |                      2.梯形法                                        |\n"
                         << "                  |                      3.辛普森算法                                    |\n"
                         << "                  |                      4.蒙特卡洛投点法                                |\n"
                         << "                  |                      5.蒙特卡洛平均值法                              |\n"
                         << "                  |                      6.退出系统                                      |\n"
                         << "                  |                                                                      |\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                     请在此输入序号进行选择：";
                    cin >> push ;
                     while( option.size()>1 )
                         option.pop_back();
                        option.push_back(push);
                    system("cls");
                    //选用1.定义法求解一元瑕积分
                        if( option[1] == '1'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为：" << orifunc << endl
                             << "                                积分下限为：  " << m << endl
                             << "                                积分上限为：  " << n << endl
                             << "                                定积分类型为：一元瑕积分，且瑕积分收敛\n";
                        double answer = P.impro_Definition( orifunc , trim , trin);
                        cout << "                                通过定义法求得积分值为：" << answer;
                        fout << "\t\t\t用定义法求得一元积分值为：" << answer <<"\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                         << "                  ------------------------------------------------------------------------\n"
                         << "                  |                                                                      |\n"
                         << "                  |                        请选择你想进行的操作：                        |\n"
                         << "                  |                                                                      |\n"
                         << "                  |                          1.回到首页                                  |\n"
                         << "                  |                          2.退出系统                                  |\n"
                         << "                  |                                                                      |\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                          请在此输入序号进行选择：";
                        cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                    }
                    //选用2.梯形法求解一元瑕积分
                        if( option[1] == '2'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为：" << orifunc << endl
                             << "                                积分下限为：  " << m << endl
                             << "                                积分上限为：  " << n << endl
                             << "                                定积分类型为：一元瑕积分，且瑕积分收敛\n";
                        Answer = P.impro_Trapezoid( orifunc , trim , trin);
                        cout << "                                通过梯形法求得积分值为：" << Answer;
                        fout << "\t\t\t用梯形法求得一元积分值为：" << Answer <<"\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                         << "                  ------------------------------------------------------------------------\n"
                         << "                  |                                                                      |\n"
                         << "                  |                        请选择你想进行的操作：                        |\n"
                         << "                  |                                                                      |\n"
                         << "                  |                          1.回到首页                                  |\n"
                         << "                  |                          2.退出系统                                  |\n"
                         << "                  |                                                                      |\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                          请在此输入序号进行选择：";
                        cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                    }
                    //选用3.辛普森算法求解一元瑕积分
                        if( option[1] == '3'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为：" << orifunc << endl
                             << "                                积分下限为：  " << m << endl
                             << "                                积分上限为：  " << n << endl
                             << "                                定积分类型为：一元瑕积分，且瑕积分收敛\n";
                        Answer = P.impro_Simpson( orifunc , trim , trin);
                        cout << "                                通过辛普森算法求得积分值为：" << Answer;
                        fout << "\t\t\t用辛普森算法求得一元积分值为：" << Answer <<"\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                         << "                  ------------------------------------------------------------------------\n"
                         << "                  |                                                                      |\n"
                         << "                  |                        请选择你想进行的操作：                        |\n"
                         << "                  |                                                                      |\n"
                         << "                  |                          1.回到首页                                  |\n"
                         << "                  |                          2.退出系统                                  |\n"
                         << "                  |                                                                      |\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                          请在此输入序号进行选择：";
                        cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                    }
                    //选用4.蒙特卡洛投点法求解一元瑕积分
                        if( option[1] == '4'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为：" << orifunc << endl
                             << "                                积分下限为：  " << m << endl
                             << "                                积分上限为：  " << n << endl
                             << "                                定积分类型为：一元瑕积分，且瑕积分收敛\n";
                        Answer = P.impro_Montecarlo( orifunc , trim , trin);//******************************************************************************************
                        cout << "                                通过蒙特卡洛投点法求得积分值为：" << Answer;
                        fout << "\t\t\t用蒙特卡洛投点法求得一元积分值为：" << Answer <<"\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                         << "                  ------------------------------------------------------------------------\n"
                         << "                  |                                                                      |\n"
                         << "                  |                        请选择你想进行的操作：                        |\n"
                         << "                  |                                                                      |\n"
                         << "                  |                          1.回到首页                                  |\n"
                         << "                  |                          2.退出系统                                  |\n"
                         << "                  |                                                                      |\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                          请在此输入序号进行选择：";
                        cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                    }
                    //选用5.蒙特卡洛平均值法求解一元瑕积分
                        if( option[1] == '5'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为：" << orifunc << endl
                             << "                                积分下限为：  " << m << endl
                             << "                                积分上限为：  " << n << endl
                             << "                                定积分类型为：一元瑕积分，且瑕积分收敛\n";
                        Answer = P.impro_Definition( orifunc , trim , trin);//******************************************************************************************
                        cout << "                                通过蒙特卡洛平均值法求得积分值为：" << Answer;
                        fout << "\t\t\t用蒙特卡洛平均值法求得一元积分值为：" << Answer <<"\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                         << "                  ------------------------------------------------------------------------\n"
                         << "                  |                                                                      |\n"
                         << "                  |                        请选择你想进行的操作：                        |\n"
                         << "                  |                                                                      |\n"
                         << "                  |                          1.回到首页                                  |\n"
                         << "                  |                          2.退出系统                                  |\n"
                         << "                  |                                                                      |\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                          请在此输入序号进行选择：";
                        cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                    }
                    //6.退出系统
                    else if( option[1] == '6' ){
                            check1 = false;
                            P.storepoint.clear();
                            system("cls");
                        }
                }
            }//flag_letter==0
        }//while check2
    }//if 一元定积分

    //二元定积分：
    else if( option[0] == '2'){
        while( check2 ){
            GetLocalTime(&time);
            cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                 << "                  ------------------------------------------------------------------------\n"
                 << "                  |                                                                      |\n"
                 << "                  |                      输入规则如下，请按规则输入！                    |\n"
                 << "                  |                                                                      |\n"
                 << "                  |        1.只能实现+、-、*、/、^、()、[]、{}、||、log(,)、sin()、      |\n"
                 << "                  |                  cos()、tan()、asin()、acos()、atan()、运算          |\n"
                 << "                  |        2.log(,)函数使用规则为：log(底数,真数)                        |\n"
                 << "                  |        3.同级括号、绝对值号不能嵌套，括号必须成对出现                |\n"
                 << "                  |        4.所有符号必须用英文输入                                      |\n"
                 << "                  |        5.一元函数请用x表示自变量，二元函数请用x、y表示自变量         |\n"
                 << "                  |        6.不能计算无穷积分                                            |\n"
                 << "                  |                                                                      |\n"
                 << "                  ------------------------------------------------------------------------\n\n"
                 << "                           请在此输入二元函数：";
            orifunc.clear();
            cin >> orifunc;
            fout << "\t\t【计算二元函数定积分】\n\n"
                 << "\t\t函数表达式：" << orifunc <<"\n";
                cout << "\n                           请输入自变量x的积分下限：";
                cin >> m ;
                cout << "\n                           请输入自变量x的积分上限：";
                cin >> n ;
                cout << "\n                           请输入自变量y的积分下限：";
                cin >> m1 ;
                cout << "\n                           请输入自变量y的积分上限：";
                cin >> n1 ;
                fout << "\t\tx的积分下限：" << m << "\n"
                     << "\t\tx的积分上限：" << n << "\n"
                     << "\t\ty的积分下限：" << m1 << "\n"
                     << "\t\ty的积分上限：" << n1 << "\n";
                trim = solve( m , 1 );
                trin = solve( n , 1 );
                trim1 = solve( m1 , 1 );
                trin1 = solve( n1 , 1 );
                GetLocalTime(&time);
                system("cls");
                    cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                函数表达式为： " << orifunc << endl
                         << "                                x的积分下限为：" << m << endl
                         << "                                x的积分上限为：" << n << endl
                         << "                                y的积分下限为：" << m1 << endl
                         << "                                y的积分上限为：" << n1 << endl
                         << "                                定积分类型为： 二元积分\n\n";
                    fout << "\t\t\t定积分类型为：二元正常积分\n\n";
                    cout << "                  ------------------------------------------------------------------------\n"
                         << "                  |                                                                      |\n"
                         << "                  |                    请选择你想实现的算法：                            |\n"
                         << "                  |                                                                      |\n"
                         << "                  |                      1.定义法                                        |\n"
                         << "                  |                      2.梯形法                                        |\n"
                         << "                  |                      3.辛普森算法                                    |\n"
                         << "                  |                      4.蒙特卡洛投点法                                |\n"
                         << "                  |                      5.蒙特卡洛平均值法                              |\n"
                         << "                  |                      6.退出系统                                      |\n"
                         << "                  |                                                                      |\n"
                         << "                  ------------------------------------------------------------------------\n\n"
                         << "                                     请在此输入序号进行选择：";
                    cin >> push ;
                     while( option.size()>1 )
                         option.pop_back();
                    option.push_back(push);
                    system("cls");
                    //选用1.定义法求解二元积分
                    if( option[1] == '1'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为： " << orifunc << endl
                             << "                                x的积分下限为：" << m << endl
                             << "                                x的积分上限为：" << n << endl
                             << "                                y的积分下限为：" << m1 << endl
                             << "                                y的积分上限为：" << n1 << endl
                             << "                                定积分类型为： 二元积分                                \n\n";
                        Answer = Definition_binary( orifunc , trim , trin , trim1 , trin1 );
                        cout << "                                通过定义法求得积分值为：" << Answer;
                        fout << "\t\t\t用定义法求得二元积分值为：" << Answer <<"\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                             << "                  ------------------------------------------------------------------------\n"
                             << "                  |                                                                      |\n"
                             << "                  |                        请选择你想进行的操作：                        |\n"
                             << "                  |                                                                      |\n"
                             << "                  |                          1.回到首页                                  |\n"
                             << "                  |                          2.退出系统                                  |\n"
                             << "                  |                                                                      |\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                          请在此输入序号进行选择：";
                        cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            system("cls");
                        }
                    }
                    //选用2.梯形法求解二元积分*********************************************************还没写出来
                    else if( option[1] == '2'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为： " << orifunc << endl
                             << "                                x的积分下限为：" << m << endl
                             << "                                x的积分上限为：" << n << endl
                             << "                                y的积分下限为：" << m1 << endl
                             << "                                y的积分上限为：" << n1 << endl
                             << "                                定积分类型为： 二元积分                                \n\n";
                        Answer = Trapezoid_binary( orifunc , trim , trin , trim1 , trin1 );
                        cout << "                                通过梯形法求得积分值为：" << Answer;
                        fout << "\t\t\t用梯形法求得二元积分值为：" << Answer <<"\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                             << "                  ------------------------------------------------------------------------\n"
                             << "                  |                                                                      |\n"
                             << "                  |                        请选择你想进行的操作：                        |\n"
                             << "                  |                                                                      |\n"
                             << "                  |                          1.回到首页                                  |\n"
                             << "                  |                          2.退出系统                                  |\n"
                             << "                  |                                                                      |\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                          请在此输入序号进行选择：";
                        cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            system("cls");
                        }
                    }
                    //选用3.辛普森算法求解二元积分
                    else if( option[1] == '3'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为： " << orifunc << endl
                             << "                                x的积分下限为：" << m << endl
                             << "                                x的积分上限为：" << n << endl
                             << "                                y的积分下限为：" << m1 << endl
                             << "                                y的积分上限为：" << n1 << endl
                             << "                                定积分类型为： 二元积分                                \n\n";
                        sim = exact_Simpson_binary( orifunc , trim , trin , trim1 , trin1 , 0.00001);
                        cout << "                                通过辛普森算法求得积分值为："<< sim ;
                        fout << "\t\t\t用辛普森算法求得二元积分值为：" << Answer <<"\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                             << "                  ------------------------------------------------------------------------\n"
                             << "                  |                                                                      |\n"
                             << "                  |                        请选择你想进行的操作：                        |\n"
                             << "                  |                                                                      |\n"
                             << "                  |                          1.回到首页                                  |\n"
                             << "                  |                          2.退出系统                                  |\n"
                             << "                  |                                                                      |\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                          请在此输入序号进行选择：";
                        cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            system("cls");
                        }
                    }
                    //选用4.蒙特卡洛投点法求解二元积分
                    else if( option[1] == '4'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为： " << orifunc << endl
                             << "                                x的积分下限为：" << m << endl
                             << "                                x的积分上限为：" << n << endl
                             << "                                y的积分下限为：" << m1 << endl
                             << "                                y的积分上限为：" << n1 << endl
                             << "                                定积分类型为： 二元积分                                \n\n";
                        Answer = Montecarlo_binary( orifunc , trim , trin , trim1 , trin1 );
                        cout << "                                通过蒙特卡洛投点法求得积分值为：" << Answer;
                        fout << "\t\t\t用蒙特卡洛投点法求得二元积分值为：" << Answer <<"\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                             << "                  ------------------------------------------------------------------------\n"
                             << "                  |                                                                      |\n"
                             << "                  |                        请选择你想进行的操作：                        |\n"
                             << "                  |                                                                      |\n"
                             << "                  |                          1.回到首页                                  |\n"
                             << "                  |                          2.退出系统                                  |\n"
                             << "                  |                                                                      |\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                          请在此输入序号进行选择：";
                        cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            system("cls");
                        }
                    }
                    //选用5.蒙特卡洛平均值法求解
                    else if( option[1] == '5'){
                        GetLocalTime(&time);
                        cout << "\n\n\n                                          "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分\n\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                函数表达式为： " << orifunc << endl
                             << "                                x的积分下限为：" << m << endl
                             << "                                x的积分上限为：" << n << endl
                             << "                                y的积分下限为：" << m1 << endl
                             << "                                y的积分上限为：" << n1 << endl
                             << "                                定积分类型为： 二元积分                                \n\n";
                        Answer = montecarlo_binary( orifunc , trim , trin , trim1 , trin1 );
                        cout << "                                通过蒙特卡洛投点法求得积分值为：" << Answer;
                        fout << "\t\t\t用蒙特卡洛投点法求得二元积分值为：" << Answer <<"\n\n";
                        fout << "\t\t\t——————本次运算结束！——————\n\n";
                        cout << "\n\n"
                             << "                  ------------------------------------------------------------------------\n"
                             << "                  |                                                                      |\n"
                             << "                  |                        请选择你想进行的操作：                        |\n"
                             << "                  |                                                                      |\n"
                             << "                  |                          1.回到首页                                  |\n"
                             << "                  |                          2.退出系统                                  |\n"
                             << "                  |                                                                      |\n"
                             << "                  ------------------------------------------------------------------------\n\n"
                             << "                                          请在此输入序号进行选择：";
                        cin >> push;
                        while( option.size()>2 )
                          option.pop_back();
                        option.push_back(push);
                        if( option[2] == '1'){
                            check2 = false;
                            system("cls");
                        }
                        else if ( option[2] == '2' ){
                            check1 = false;
                            check2 = false;
                            system("cls");
                        }
                    }
                    //6.退出系统
                    else if( option[1] == '6' ){
                            check1 = false;
                            check2 = false;
                            system("cls");
                        }
    }//while check2
    }//else if 二元定积分
    else if( option[0] == '3'){
        check1 = false;
        system("cls");
    }//else if 退出系统

    }//while check1


    GetLocalTime(&time);
    cout << "\n\n\n"
         << "                  ------------------------------------------------------------------------\n"
         << "                  |                                                                      |\n"
         << "                  |                       "<< time.wYear << "年" << time.wMonth << setfill('0') << setw(2)<< "月" << time.wDay << setfill('0') << setw(2)<< "日  "<< setfill('0') << setw(2) << time.wHour << "时" << setfill('0') << setw(2) << time.wMinute << "分                        |\n"
         << "                  |                                                                      |\n"
         << "                  |    --------------------------------------------------------------    |\n"
         << "                  |                                                                      |\n"
         << "                  |                            谢谢您的使用！                            |\n"
         << "                  |                                                                      |\n"
         << "                  |           如对本程序功能有修改意见或建议，欢迎致电13954250216        |\n"
         << "                  |                                                                      |\n"
         << "                  |                 指导教师：刘小惠                                     |\n"
         << "                  |                 开发人员：朱晓涵、李佳佳、白雨薇、汤鑫彬             |\n"
         << "                  |                 版本号：2.4.7.191217_demo                            |\n"
         << "                  |                                                                      |\n"
         << "                  ------------------------------------------------------------------------\n\n";
         fout << "\t\t\t                 **********************      \n"
              //<< "\t\t\t*                                                                    |\n"
              << "\t\t\t                       谢谢您的使用！\n"
              //<< "\t\t\t*                                                                    |\n"
              << "\t\t\t                 **********************      \n"
              << "\n\t————————结束时间为："
              << time.wYear << "年"
              << setfill('0') << setw(2)<< time.wMonth << "月"
              << setfill('0') << setw(2)<< time.wDay << "日  "
              << setfill('0') << setw(2) << time.wHour << "时"
              << setfill('0') << setw(2) << time.wMinute << "分"
              << setfill('0') << setw(2) << time.wSecond << "秒————————\n\n\n\n\n\n" ;
        getch();

    fout.close();
    return 0 ;
}




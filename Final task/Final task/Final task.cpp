#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include<algorithm>

using namespace std;

class Fielder  //野手成績用のクラス
{
    string name{}; //選手名
    double battingaverage ; //打率
    int homerun ;  //本塁打
    int rbi ;  //打点
    int steal ; //盗塁
};

class Pitcher //投手成績用のクラス
{
    string name{};  //選手名
    int win;   //勝利
    double era;   //防御率
    int strikeout;   //奪三振
    int hp;   //ホールドポイント
    int save;   //セーブ
};


void  fielderstatistics()  //野手成績を表示する関数
{
    cout << "見たい成績を以下から選択し,入力してください。その後,Enterキーを押してください。\n"  //入力画面
         <<"打率,本塁打,打点,盗塁,全て" << endl;
    string str;
    cin >> str;

    if (str == "打率")  //打率が入力された場合の処理
    {
        vector<Fielder> yashu; //野手ファイルから読み込んだデータの格納先
        ifstream datefile("fielder.txt"); //野手ファイルの読み込み
        regex rx(R"(\s)"); //空白を探すための正規表現
        string str;

        while (getline(datefile, str)) //1行ずつ読み込む
        {
            vector<string> v; //分割されたデータの格納先
            auto ite = sregex_token_iterator(str.begin(), str.end(), rx, -1); //読み込んだ行の分割
            auto end = sregex_token_iterator(); //行の最後まで分割を行う
            while (ite != end) //終了するまで繰り返し
            {
                v.push_back(*ite++); //分割されたデータを格納
            }
            cout << "選手名:" << v[0] << "\t打率:" << v[1] << endl;  //選手名と打率を出力
        }
    }

    if (str == "本塁打")  //本塁打が入力された場合の処理
    {
        vector<Fielder> yashu;
        ifstream datefile("fielder.txt");
        regex rx(R"(\s)");
        string str;
       
        while (getline(datefile, str))
        {
            vector<string> v;

            auto ite = sregex_token_iterator(str.begin(), str.end(), rx, -1);
            auto end = sregex_token_iterator();
            while (ite != end)
            {
                v.push_back(*ite++);
            }
            cout << "選手名:" << v[0] << "\t本塁打:" << v[2] << endl; //選手名と本塁打を出力
        }
    }

    if (str == "打点") //打点が入力された場合の処理
    {
        vector<Fielder> yashu;
        ifstream datefile("fielder.txt");
        regex rx(R"(\s)");
        string str;
   
        while (getline(datefile, str))
        {
            vector<string> v;
            auto ite = sregex_token_iterator(str.begin(), str.end(), rx, -1);
            auto end = sregex_token_iterator();
            while (ite != end)
            {
                v.push_back(*ite++);
            }
            cout << "選手名:" << v[0] << "\t打点:" << v[3] << endl; //選手名と打点を出力
        }
    }

    if (str == "盗塁") //盗塁が入力された場合の処理
    {
        vector<Fielder> yashu;
        ifstream datefile("fielder.txt");
        regex rx(R"(\s)");
        string str;
       
        while (getline(datefile, str))
        {
            vector<string> v;
            auto ite = sregex_token_iterator(str.begin(), str.end(), rx, -1);
            auto end = sregex_token_iterator();
            while (ite != end)
            {
                v.push_back(*ite++);
            }
            cout << "選手名:" << v[0] << "\t盗塁:" << v[4] << endl; //選手名と盗塁を出力
        }
    }

    if (str == "全て") //全てと入力された場合の処理
    { 
        vector<Fielder> yashu;
        ifstream datefile("fielder.txt");
        regex rx(R"(\s)");
        string str;
       
        while (getline(datefile, str))
        {
            vector<string> v;
            auto ite = sregex_token_iterator(str.begin(), str.end(), rx, -1);
            auto end = sregex_token_iterator();
            while (ite != end)
            {
                v.push_back(*ite++);
            }
            cout << "選手名:" << v[0] <<  "\t打率:" << v[1] << "\t本塁打:" << v[2] << "\t打点:" << v[3] << "\t盗塁:" << v[4] << endl; //野手ファイル内の全てのデータを出力
        }
    }

    if (str != "打率" && str != "本塁打" && str != "打点" && str != "盗塁" && str != "全て") //打率,本塁打,打点,盗塁,全て以外が入力された場合の処理
    {
        try
        {
            if (str != "打率" && str != "本塁打" && str != "打点" && str != "盗塁" && str != "全て")
                throw 0;
        }
        catch (int x)
        {
            cout << "入力が適切ではありません。「打率」,「本塁打」,「打点」,「盗塁」,[全て」のいずれかを入力してください。";
        }
    }
}

    void  pitcherststistics()  //投手成績を表示する関数
{
    cout << "見たい成績を以下から選択し,入力してください。その後,Enterキーを押してください。\n" //入力画面
         << "勝利,防御率,奪三振,ホールドポイント,セーブ,全て" << endl;
    string str;
    cin >> str;

    if (str == "勝利") //勝利が入力された場合の処理
    {
        vector<Pitcher> toushu; //投手ファイルから読み込んだデータの格納先
        ifstream datefile("pitcher.txt"); //投手ファイルの読み込み
        regex rx(R"(\s)"); //空白を読み込む正規表現
        string str;
      
        while (getline(datefile, str))  //1行ずつ読み込む
        {
            vector<string> v; //分割されたデータの格納先
            auto ite = sregex_token_iterator(str.begin(), str.end(), rx, -1); //読み込んだ行の分割
            auto end = sregex_token_iterator(); //行の最後まで分割を行う
            while (ite != end) //終了するまで繰り返し
            {
                v.push_back(*ite++);  //分割されたデータを格納
            }
            cout << "選手名:\t" << v[0] << "\t勝利:" << v[1] << endl; //選手名と勝利を表示
        }
    }

    if (str == "防御率") //防御率が入力された場合の処理
    {
        vector<Pitcher> toushu;
        ifstream datefile("pitcher.txt");
        regex rx(R"(\s)");
        string str;
    
        while (getline(datefile, str))
        {
            vector<string> v;
            auto ite = sregex_token_iterator(str.begin(), str.end(), rx, -1);
            auto end = sregex_token_iterator();
            while (ite != end)
            {
                v.push_back(*ite++);
            }
            cout << "選手名:" << v[0] << "\t防御率:" << v[2] << endl; //選手名と防御率を出力
        }
    }

    if (str == "奪三振") //奪三振が入力された場合の処理
    {
        vector<Pitcher> toushu;
        ifstream datefile("pitcher.txt");
        regex rx(R"(\s)");
        string str;
   
        while (getline(datefile, str))
        {
            vector<string> v;
            auto ite = sregex_token_iterator(str.begin(), str.end(), rx, -1);
            auto end = sregex_token_iterator();
            while (ite != end)
            {
                v.push_back(*ite++);
            }
            cout << "選手名:" << v[0] << "\t奪三振数:" << v[3] << endl; //選手名と奪三振を出力
        }
    }

    if (str == "ホールドポイント") //ホールドポイントが入力された場合の処理
    {
        vector<Pitcher> toushu;
        ifstream datefile("pitcher.txt");
        regex rx(R"(\s)");
        string str;
   
        while (getline(datefile, str))
        {
            vector<string> v;
            auto ite = sregex_token_iterator(str.begin(), str.end(), rx, -1);
            auto end = sregex_token_iterator();
            while (ite != end)
            {
                v.push_back(*ite++);
            }
            cout << "選手名:" << v[0] << "\tホールドポイント:" << v[4] << endl; //選手名とホールドポイントを出力
        }
    }

    if (str == "セーブ") //セーブと入力された場合の処理
    {
        vector<Pitcher> yashu;
        ifstream datefile("pitcher.txt");
        regex rx(R"(\s)");
        string str;
 
        while (getline(datefile, str))
        {
            vector<string> v;
            auto ite = sregex_token_iterator(str.begin(), str.end(), rx, -1);
            auto end = sregex_token_iterator();
            while (ite != end)
            {
                v.push_back(*ite++);
            }
            cout << "選手名:" << v[0] << "\tセーブ:" << v[5] << endl; //選手名とセーブを出力
        }
    }

    if (str == "全て") //全てと入力された場合の処理
    {
        vector<Pitcher> yashu;
        ifstream datefile("pitcher.txt");
        regex rx(R"(\s)");
        string str;
 
        while (getline(datefile, str))
        {
            vector<string> v;
            auto ite = sregex_token_iterator(str.begin(), str.end(), rx, -1);
            auto end = sregex_token_iterator();
            while (ite != end)
            {
                v.push_back(*ite++);
            }
            cout << "選手名:" << v[0] << "\t勝利:" << v[1] << "\t防御率:" << v[2] << "\t奪三振:" << v[3] << "\tホールドポイント:" << v[4] << "\tセーブ" << v[5] << endl; //投手ファイル内の全てのデータを表示
        }
    }

    if (str != "勝利" && str != "防御率" && str != "奪三振" && str != "ホールドポイント" && str != "セーブ" && str != "全て") //勝利,防御率,奪三振,ホールドポイント,セーブ,全て以外が入力された場合の処理
    {
        try
        {
            if ((str != "勝利" && str != "防御率" && str != "奪三振" && str != "ホールドポイント" && str != "セーブ" && str != "全て"))
                throw 0;
        }
        catch (int x)
        {
            cout << "入力が適切ではありません。「勝利」,「防御率」,「奪三振」,「ホールドポイント」,[セーブ」,[全て]のいずれかを入力してください。";
        }
    }
}

int main()
{
    cout << "～ 一目で分かる! 東京オリンピック野球日本代表 2021年シーズン成績 ～\n" << endl;  //題名
    cout << "投手成績を見たい場合は投手,野手成績を見たい場合は野手と入力し,Enterキーを押してください。"<< endl;  //入力画面
    string str;
    cin >> str;

    if (str != "投手" && str != "野手")  //投手と野手以外の入力があった場合の処理
    {
        try
        {
            if (str != "投手" || str != "野手")
                throw 0;
        }
        catch (int x)
        {
            cout << "入力が適切ではありません。「投手」,「野手」のいずれかを入力してください。";
        }
    }

    if (str == "投手") //投手と入力された場合の処理
    {
        pitcherststistics();  //投手成績を表示する関数
    }

    if (str == "野手") //野手と入力された場合の処理
    {
        fielderstatistics();  //野手成績を表示する関数
    }
}
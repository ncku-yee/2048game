#include"game.h"
#include<iomanip>
using namespace std;
//將map和check_map歸零
Game::Game()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {    
            map[i][j] = 0;
            check_map[i][j] = 0;
        }
}
//隨機找2個位置給值
void Game::init_map()
{
    srand(time(NULL));
    int posx = rand()%4;    
    int posy = rand()%4;
    map[posx][posy] = 2;        //找出第一個位置給2
    posx = rand()%4;
    posy = rand()%4;
    while(map[posx][posy] != 0)         //若random的位置不為0，則重新random
    {
        posx = rand()%4;
        posy = rand()%4;
    }
    map[posx][posy] = 2;
    copy_map();                 //複製一份map給check_map
    return;
}
//印出2048的map
void Game::print_map()
{
    cout << "|----|----|----|----|" << endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << "|";
            if(map[i][j] == 0)
                cout << setw(4) << ".";
            else
                cout << setw(4) << map[i][j];
        }
        cout << "|" << endl ;
        cout << "|----|----|----|----|" << endl;
    }
    return;
}
//複製map的值給check_map
void Game:: copy_map()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            check_map[i][j] = map[i][j];
    return;
}
//map向上移動
void Game::moveup()
{
    copy_map();                 //複製一份map給check_map作為前後對比
    for(int i = 0; i < 4; i++)      //每個column運算
    {
        for(int j = 1; j < 4; j++)          //從row的第2個元素開始遞增
        {
            for(int k = 0; k <= j; k++)     //檢查元素的上面
            {
                if(map[k][i] == 0)          //若元素的上面為0則移動該元素至上面，原位置歸0
                {
                    map[k][i] = map[j][i];
                    map[j][i] = 0;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(map[i][j] != check_map[i][j])        //若map與check_map的元素有不同，代表map有向上移動過
            {
                add_up();
                pop_num();
                return;
            }
    if(add_up() == true)            //若add_top()為true，代表map是可以移動的，則執行pop_num()(反之代表map無法相加)
    {
        pop_num();
        return;
    }
    return;
}
//map向下移動
void Game::movedown()
{
    copy_map();                 //複製一份map給check_map作為前後對比
    for(int i = 0; i < 4; i++)      //每個column運算
    {
        for(int j = 2; j >= 0; j--)         //從row的第3個元素開始遞減
        {
            for(int k = 3; k >= j; k--)     //檢查元素的下面
            {
                if(map[k][i] == 0)          //若元素的右手邊下面為0則移動該元素至下面，原位置歸0
                {    
                    map[k][i] = map[j][i];
                    map[j][i] = 0;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(map[i][j] != check_map[i][j])        //若map與check_map的元素有不同，代表map有向下移動過
            {
                add_down();
                pop_num();
                return;
            }
    if(add_down() == true)          //若add_down()為true，代表map是可以移動的，則執行pop_num()(反之代表map無法相加)
    {
        pop_num();
        return;
    }
    return;
}
//map向左移動
void Game::moveleft()
{
    copy_map();                 //複製一份map給check_map作為前後對比
    for(int i = 0; i < 4; i++)      //每個row運算
    {
        for(int j = 1; j < 4; j++)          //從column的第2個元素開始遞增
        {
            for(int k = 0; k <= j; k++)     //檢查元素的左手邊
            {
                if(map[i][k] == 0)          //若元素的左手邊為0則移動該元素至左邊，原位置歸0
                {
                    map[i][k] = map[i][j];
                    map[i][j] = 0;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(map[i][j] != check_map[i][j])        //若map與check_map的元素有不同，代表map有向左移動過
            {
                add_left();
                pop_num();
                return;
            }
    if(add_left() == true)          //若add_left()為true，代表map是可以移動的，則執行pop_num()(反之代表map無法相加)
    {
        pop_num();
        return;
    }
    return;
}
//map向右移動
void Game::moveright()
{
    copy_map();                 //複製一份map給check_map作為前後對比
    for(int i = 0; i < 4; i++)      //每個row運算
    {
        for(int j = 2; j >= 0; j--)         //從column的第3個元素開始遞減
        {
            for(int k = 3; k >= j; k--)     //檢查元素的右手邊
            {
                if(map[i][k] == 0)          //若元素的右手邊為0則移動該元素至右邊，原位置歸0
                {
                    map[i][k] = map[i][j];
                    map[i][j] = 0;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(map[i][j] != check_map[i][j])        //若map與check_map的元素有不同，代表map有向右移動過
            {
                add_right();
                pop_num();
                return;
            }
    if(add_right() == true)             //若add_right()為true，代表map是可以移動的，則執行pop_num()(反之代表map無法相加)
    {
        pop_num();
        return;
    }
    return;
}
//在map空白處pop一個2
void Game::pop_num()
{
    srand(time(NULL));
    int posx = rand()%4;
    int posy = rand()%4;
    while(map[posx][posy] != 0)         //遇到map該處不為0則重新random位置
    {
        posx = rand()%4;
        posy = rand()%4;
    }
    map[posx][posy] = 2;
    return;   
}
//向上的加法(回傳true代表map有更改過、回傳false代表map並無更改過)
bool Game::add_up()
{
    copy_map();                 //複製一份map給check_map作為前後對比
    for(int i = 0; i < 4; i++)          //每個column做運算
    {
        for(int j = 0; j < 3; j++)          //從每個coloumn的上面加起
        {
            if(map[j][i] == map[j+1][i])        //若發現該元素與下面的元素相同則相加，並將下面的元素歸0
            {
                map[j][i] += map[j][i];
                map[j+1][i] = 0;
                if(j == 2)                  //最多只會加到row的第3個元素
                    break;
                for(int k = (j + 1); k < 3; k++)    //加完後的下面元素必須補進
                {
                    map[k][i] = map[k+1][i];
                    map[k+1][i] = 0;
                }
            }
        }
    }
    for(int i = 0; i < 4; i++)          //判斷經過向右加法後是否與先前的check_map有差異(任何一個有差異回傳true)
        for(int j = 0; j < 4; j++)
            if(map[i][j] != check_map[i][j])
                return true;
    return false;
}
//向下的加法(回傳true代表map有更改過、回傳false代表map並無更改過)
bool Game::add_down()
{
    copy_map();                 //複製一份map給check_map作為前後對比
    for(int i = 0; i < 4; i++)          //每個column做運算
    {
        for(int j = 3; j >= 0; j--)         //從每個coloumn的下面加起 
        {
            if(map[j][i] == map[j-1][i])        //若發現該元素與上面的元素相同則相加，並將上面的元素歸0
            {
                map[j][i] += map[j][i];
                map[j-1][i] = 0;
                if(j == 1)                  //最多只會加到row的第2個元素
                    break;
                for(int k = (j - 1); k > 0; k--)    //加完後的上面元素必須補進
                {
                    map[k][i] = map[k-1][i];
                    map[k-1][i] = 0;
                }
            }
        }
    }
    for(int i = 0; i < 4; i++)          //判斷經過向右加法後是否與先前的check_map有差異(任何一個有差異回傳true)
        for(int j = 0; j < 4; j++)
            if(map[i][j] != check_map[i][j])
                return true;
    return false;
}
//向左的加法(回傳true代表map有更改過、回傳false代表map並無更改過)
bool Game::add_left()
{
    copy_map();                 //複製一份map給check_map作為前後對比
    for(int i = 0; i < 4; i++)          //每個row做運算
    {
        for(int j = 0; j < 3; j++)          //從每個row的左手邊加起 
        {
            if(map[i][j] == map[i][j+1])        //若發現該元素與右邊的元素相同則相加，並將右手邊的元素歸0
            {
                map[i][j] += map[i][j];
                map[i][j+1] = 0;
                if(j == 2)                  //最多只會加到column的第3個元素
                    break;
                for(int k = (j + 1); k < 3; k++)    //加完後的右邊元素必須補進
                {
                    map[i][k] = map[i][k+1];
                    map[i][k+1] = 0;
                }
            }
        }
    }
    for(int i = 0; i < 4; i++)          //判斷經過向右加法後是否與先前的check_map有差異(任何一個有差異回傳true)
        for(int j = 0; j < 4; j++)
            if(map[i][j] != check_map[i][j])
                return true;
    return false;
}
//向右的加法(回傳true代表map有更改過、回傳false代表map並無更改過)
bool Game::add_right()
{
    copy_map();                 //複製一份map給check_map作為前後對比
    for(int i = 0; i < 4; i++)          //每個row做運算
    {
        for(int j = 3; j >= 0; j--)         //從每個row的右手邊加起
        {
            if(map[i][j] == map[i][j-1])        //若發現該元素與左邊的元素相同則相加，並將左手邊的元素歸0
            {
                map[i][j] += map[i][j];
                map[i][j-1] = 0;
                if(j == 1)                  //最多只會加到column的第2個元素
                    break;
                for(int k = (j - 1); k > 0; k--)    //加完後的左邊元素必須補進
                {
                    map[i][k] = map[i][k-1];
                    map[i][k-1] = 0;
                }
            }
        }
    }
    for(int i = 0; i < 4; i++)          //判斷經過向右加法後是否與先前的check_map有差異(任何一個有差異回傳true)
        for(int j = 0; j < 4; j++)
            if(map[i][j] != check_map[i][j])
                return true;
    return false;
}
//判斷map是否還可以移動
bool Game::gameover()
{
    for(int i = 0; i < 4; i++)          //判斷map是否有0
        for(int j = 0; j < 4; j++)
            if(map[i][j] == 0)
                return false;
    for(int i = 0; i < 4; i++)          //判斷每個row的相鄰元素是否相同(若有相同代表遊戲尚未結束)
        for(int j = 0; j < 3; j++)
        {
            if(map[i][j] == map[i][j+1])
                return false;
        }
    for(int i = 0; i < 4; i++)          //判斷每個column的相鄰元素是否相同(若有相同代表遊戲尚未結束)
        for(int j = 0; j < 3; j++)
        {
            if(map[j][i] == map[j+1][i])
                return false;
        }
    return true;                        //上述判斷皆通過代表遊戲結束
}
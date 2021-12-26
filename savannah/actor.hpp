#pragma once
#include"init.hpp"
#include<random>
#include <cmath>

//生物クラス
class Creatures {
protected:
    double spf = 0.0;
    double age = 0.0;
    int oneYear = 24;
public:
    //計測した1フレームあたりの秒数を設定する
    void setSpf(const double miSpf);

};
//生物クラス実装
void Creatures::setSpf(const double miSpf) {
    spf = miSpf / 1000.0;
}


//植物クラス
class Plant : public Creatures {
private:
    double x = windowWidth / 2.0;
    double y = windowHeight / 2.0;
    double age = 0;
    double lifespan = 5.0;
public:
    void lifeActivity(const double miSpf, bool& isDie);
    void born(const double x, const double y);
};

//植物クラス実装
void Plant::lifeActivity(const double miSpf, bool& isDie) {
    setSpf(miSpf);
    age += spf;
    isDie = (age > oneYear * lifespan);
}
void Plant::born(const double bornX, const double bornY) {
    x = bornX;
    y = bornY;
}

//動物クラス
class Animal : public Creatures{
private:
    double distance=100.0;
protected:
    double x = windowWidth/2.0;
    double y = windowHeight/2.0;
    double distinationX = windowWidth / 2.0;
    double distinationY = windowHeight / 2.0;
public:
    //新しいX座標を設定
    int moveX();
    //新しいY座標を設定
    int moveY();
    //目的地にいるかどうかの判定
    bool isDistination();
    //目的地の設定
    void setDistination();
    //目的地との距離
    void calculateDistance(const double x, const double y, const double dsX, const double dsY);
};


//草食動物クラス
class Herbivore : public Animal {
private:
    double lifespan=20.0;
public:
    //生命活動を管理
    void lifeActivity(const double miSpf, bool& isDie);
    //行動
    void behavior();
};


//動物クラス実装
int Animal::moveX() {
    if (distance == 0.0) {
        setDistination();
        calculateDistance(x, y, distinationX, distinationY);
    }
    double dx = (distinationX - x) / distance;
    x += dx;
    return int(x);
}
int Animal::moveY() {
    if (distance == 0.0) {
        setDistination();
        calculateDistance(x, y, distinationX, distinationY);
    }
    double dy = (distinationY - y) / distance;
    y += dy;
    return int(y);
}
bool Animal::isDistination() {
    if ((x - distinationX) < 1 && (y - distinationY) < 1) return true;
    else return false;
}
void Animal::calculateDistance(const double x, const double y, const double dsX, const double dsY) {
    distance=sqrt(pow(x - dsX, 2) + pow(y - dsY, 2));
}
void Animal::setDistination() {
    constexpr int MIN = 0;
    constexpr int wMAX = windowWidth;
    constexpr int hMAX = windowHeight;
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> wDistr(MIN, wMAX);
    std::uniform_int_distribution<int> hDistr(MIN, hMAX);
    distinationX = wDistr(eng);
    distinationY = hDistr(eng);
}



//草食動物実装
void Herbivore::lifeActivity(const double miSpf,bool& isDie) {
    setSpf(miSpf);
    age += spf;
    isDie = (age > oneYear * lifespan);
    if (isDistination()) setDistination();
    calculateDistance(x,y,distinationX,distinationY);
}
void Herbivore::behavior() {
    if (isDistination()) setDistination();
    calculateDistance(x, y, distinationX, distinationY);
    Draw::circleDraw(moveX(), moveY(), herbivoreE);
}
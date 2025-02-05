﻿#ifndef SAVANNAH_HERNIVORE_H
#define SAVANNAH_HERNIVORE_H
#include"animal.h"
#include"plant.h"
#include <vector>

namespace Savannah {
    enum class HerbivoreStateE :int {
        herbivoreWanderE
        , herbivoreForageE
        , herbivoreBreedE
        , herbivoreDieE
    };

    //草食動物クラス
    class Herbivore : public Animal {
    private:
        //食事
        void eat(std::vector<Plant>& plant, const size_t s);
        //草食動物の近くにある植物を探す
        void isCloseToPlants(const std::vector<Plant>& plant, size_t& s, bool& is_can_eat);
        //繁殖
        void herbivoreBreed(std::vector<Herbivore>& herbivore, const size_t hs);
        //子供が生まれる
        void born(const Vec2& born_coord, std::vector<Herbivore>& herbivore, const size_t s);
        //ステートの値を渡す
        int getHerbivoreState();
        //ステートの変更
        void setHerbivoreState(enum HerbivoreStateE new_state);
    public:
        HerbivoreStateE herbivore_state = HerbivoreStateE::herbivoreWanderE;
        explicit Herbivore(Rand*, Time*);

        //行動
        void behavior(std::vector<Herbivore>& herbivore, std::vector<Plant>& plant, const size_t i);
        //描画
        void draw(int camera_x, const int camera_y, const double camera_exrate)const;
    };
}

#endif // !SAVANNAH_HERNIVORE_H
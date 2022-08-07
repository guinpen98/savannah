﻿#ifndef SAVANNAH_PLANT_HPP
#define SAVANNAH_PLANT_HPP

#include"creatures.hpp"
#include<vector>

namespace Savannah {
    //植物クラス
    class Plant : public Creatures {
    private:
        double breed = 0.0;
        //繁殖判定
        bool isBreed();
    public:
        //コンストラクタ
        explicit Plant() {
            one_year = 24;
            lifespan = 5.0;
        }
        //生命活動
        void lifeActivity(const double mi_spf, bool& is_die, bool& is_breed);
        //他の植物と被っているかの判定
        bool isCover(const Vec2& sub_coord)const;

        void draw(int camera_x, const int camera_y, const double camera_exrate)const;
    };
}


#endif // !SAVANNAH_PLANT_HPP
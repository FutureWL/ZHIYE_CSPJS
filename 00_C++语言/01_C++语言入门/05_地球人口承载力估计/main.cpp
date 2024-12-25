#include <iostream>

// 地球的陆地面积，单位：平方千米
const double EARTH_LAND_AREA = 148940000.0;
// 平均每人所需的土地面积，单位：平方千米
const double LAND_PER_PERSON = 0.002;
// 每平方千米土地的粮食产量，单位：千克
const double FOOD_PRODUCTION_PER_AREA = 2000.0;
// 每人每年所需的粮食量，单位：千克
const double FOOD_PER_PERSON_PER_YEAR = 300.0;

int main() {
    // 根据土地资源计算可承载的人口数量
    double population_capacity_land = EARTH_LAND_AREA / LAND_PER_PERSON;
    // 根据粮食产量计算可承载的人口数量
    double population_capacity_food = (EARTH_LAND_AREA * FOOD_PRODUCTION_PER_AREA) / FOOD_PER_PERSON_PER_YEAR;

    // 取两者中的较小值作为地球人口承载力估计值
    double population_capacity = (population_capacity_land < population_capacity_food) ? population_capacity_land : population_capacity_food;

    std::cout << "地球人口承载力估计值: " << population_capacity << " 人" << std::endl;

    return 0;
}
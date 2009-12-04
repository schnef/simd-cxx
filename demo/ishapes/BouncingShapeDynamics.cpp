/* 
 * File:   BouncingShapeDynamics.cpp
 * Author: corsaro
 * 
 * Created on July 12, 2009, 10:03 PM
 */

#include "BouncingShapeDynamics.hpp"
#include <math.h>
#include <stdlib.h>

#include <iostream>
static const float PI = 3.1415926535F;

BouncingShapeDynamics::BouncingShapeDynamics(int x0, int y0,
                                             const QRect& shapeBounds,
                                             const QRect& constraint,
                                             float angle,
                                             float speed,
                                             const ShapeType& shape,
                                             simd::DataWriter<ShapeType>& shapeWriter)
    :   ShapeDynamics(x0, y0, constraint),
        shapeBounds_(shapeBounds),
        alpha_(angle),
        angle_(angle),
        speed_(speed),
        shape_(shape),
        shapeWriter_(shapeWriter)
{ }


BouncingShapeDynamics::~BouncingShapeDynamics()
{ }

bool
BouncingShapeDynamics::flip() {
    bool doflip = false;
    if (rand() <= RAND_MAX/2)
        doflip = true;
    
    return doflip;
}

void
BouncingShapeDynamics::simulate() {
    /*
    std::cout << "[angle = " << angle_ 
              << ", alpha = " << alpha_
              << ", speed = " << speed_
              << ", x = " << pos_.x()
              << ", y = " << pos_.y() 
              << "]"  << std::endl;
    std::cout << "Constr["
              << constraint_.x() << ", "
              << constraint_.y() << ", "
              << constraint_.width() << ", "
              << constraint_.height() << "]"  << std::endl;

    std::cout << "Bounds["
              << shapeBounds_.x() << ", "
              << shapeBounds_.y() << ", "
              << shapeBounds_.width() << ", "
              << shapeBounds_.height() << "]" << std::endl;
    */
    pos_.rx() = roundf(pos_.rx() + speed_*cosf(angle_));
    pos_.ry() = roundf(pos_.ry() + speed_*sinf(angle_));

    if (pos_.x() <= 0) {
        angle_ = this->flip() ? -alpha_ : alpha_;
        pos_.rx() = 0;
    }
    else if (pos_.x() >= (constraint_.width() - (shapeBounds_.width()))) {
        // std::cout << "CONSTR_II" << std::endl;
        angle_ = this->flip() ? (PI + alpha_) : (PI - alpha_);
        pos_.rx() = constraint_.width() - shapeBounds_.width();
    }
    else if (pos_.y() <= 0) {
        // std::cout << "CONSTR_III" << std::endl;
        angle_ = this->flip() ? alpha_ : PI - alpha_;
        pos_.ry() = 0;
    }
    else if (pos_.y() >= (constraint_.height() - shapeBounds_.height())) {
        // std::cout << "CONSTR_IV" << std::endl;
        angle_ = this->flip() ? (PI+alpha_) : -alpha_;
        pos_.ry() = constraint_.height() - shapeBounds_.height();
    }

    // std::cout << "DDSWriter" << std::endl;
    shape_.x = pos_.x()/2.08333F;
    shape_.y = pos_.y()/2.22223F;
    shapeWriter_->write(shape_);
    
    //std::cout << "x = " << pos_.x() << " - y = " << pos_.y() << std::endl;
}
/* 
 * File:   BouncingShapeDynamics.hpp
 * Author: corsaro
 *
 * Created on July 12, 2009, 10:03 PM
 */

#ifndef _BOUNCINGSHAPEDYNAMICS_HPP
#define	_BOUNCINGSHAPEDYNAMICS_HPP

#include <ShapeDynamics.hpp>
#include <QRect>

#include <simd/writer.hpp>

// -- Shaped Include
#include <gen/ccpp_ishape.h>
#include <topic-traits.hpp>

class BouncingShapeDynamics : public ShapeDynamics {
public:
    BouncingShapeDynamics(int x0, int y0,
                          const QRect& shapeBounds,
                          const QRect& constraints,
                          float speed,
                          float angle,
                          const ShapeType& shape,
                          simd::DataWriter<ShapeType>& shapeWriter);

    virtual ~BouncingShapeDynamics();

public:
    virtual void simulate();
    
private:
    BouncingShapeDynamics(const BouncingShapeDynamics& orig);
    BouncingShapeDynamics& operator=(const BouncingShapeDynamics&);

private:
    bool flip();
    
private:
    QRect shapeBounds_;
    float alpha_;
    float angle_;
    float speed_;
    ShapeType shape_;
    simd::DataWriter<ShapeType> & shapeWriter_;
};

#endif	/* _BOUNCINGSHAPEDYNAMICS_HPP */


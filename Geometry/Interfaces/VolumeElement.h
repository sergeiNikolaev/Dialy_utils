/**
 *  interface to geometry volume element
 */

/* include files */
#pragma once

#include "Geometry/SimplePrimitives/Point3.h"


namespace Geometry {


/**
 *  interface for represent any volume element in space
 */
class VolumeElement {

public:
    /* check if point is inside */
    virtual bool contains(Point3d &point, bool inclusive) const = 0;
};


} //namespace Geometry

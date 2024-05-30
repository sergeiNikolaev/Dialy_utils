/**
 * This file describes genral library definitions
 */

/* include files */
#pragma once

/*
 *  definition for dynamic libraries interfaces
 */
#define EPSILON_VALUE 1e-10



namespace Geometry {


/**
 *  enumeration to represent different types of intersections
 */    
enum struct IntersectionType {
    separated = 1,
    intersection = 2,
    within = 3           // within means the object is within the object
};


} // namesapce Geometry


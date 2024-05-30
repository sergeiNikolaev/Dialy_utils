/**
 *  interface to mesh
 */

/* include files */
#pragma once

#include <vector>
#include "Geometry/SimplePrimitives/Point3.h"
#include "Geometry/SimplePrimitives/Point2.h"



namespace Geometry {


/**
 *  class for represent different object topology
 */
template<typename T> class SimpleMesh {

public:
    /* topology types */
    typedef enum topology_type {
        TRIANGLE_TOPOLOGY = 3,
        SQUARE_TOPOLOGY = 4,
        TETRAHEDRON_TOPOLOGY = 4,
        CUBE_TOPOLOGY = 6
    } TopologyType;

protected:
    static const name_max_size = 256;                /**< model name maximum size */
    wchar_t name[name_max_size];                    /**< model name */

    std::vector<Point3<T>> vertices;                /**< model vertices */
    std::vector<Point3<T>> normals;                /**< model normals */
    std::vector<Point2<T>> textureCoordinates;        /**< model texture coordinates */
    TopologyType topologyType;                        /**< type of model topology */
    std::vector<unsigned int> indexes;                /**< model indexes */

public:
    /* constructor */
    SimpleMesh() : topologyType(TRIANGLE_TOPOLOGY) { }

    /* get model name */
    inline wchar_t& GetName(void) { return name; }

    /* get model vertices */
    inline std::vector<Point3<T>>& GetVertices(void) { return vertices; }

    /* get model normals */
    inline std::vector<Point3<T>>& GetNormals(void) { return normals; }

    /* get model texture coordinates */
    inline std::vector<Point2<T>>& GetTextureCoordinates(void) { return textureCoordinates; }

    /* get model topology */
    inline TopologyType& GetTopologyType(void) { return topologyType; }

    /* get size of vertexes in topology element */
    inline unsigned int& GetTopologyElementSize(void) { return static_cast<unsigned int>(topologyType); }

    /* get model indexes */
    inline unsigned int& GetIndexes(void) { return indexes; }

    /* destructor */
    ~SimpleMesh() { }
};


/**
 *    type definitions for geometry mesh
 */
typedef SimpleMesh<float> SimpleMeshf;
typedef SimpleMesh<double> SimpleMeshd;


} // namespace Geometry


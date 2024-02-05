#include "mathObj.hpp"

class Camera {
public:
    ImageSize size;
    point3 center;
    vec3 viewport_u;
    vec3 viewport_v;
    vec3 offset = vec3(1., 0., 0.);
    Camera(ImageSize s, vec3 u, vec3 v) : center{vec3(0, 0, 0)}, size{s}, viewport_u{u}, viewport_v{v} {}
    ~Camera() {}

    vec3 getPixelPosition(int i, int j) {
        vec3 u = double(2*i-size.height)/(2*size.height) * viewport_u;
        vec3 v = double(2*j-size.width)/(2*size.width) * viewport_v;
        return u+v+offset;
    }
    void setPosition(point3 to) {
        center = to;
    }

    void move(vec3 delta) {
        center += delta;
    }
};

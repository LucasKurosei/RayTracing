#include <iostream>
#include "mathObj.hpp"
#include "camera.hpp"
#include "color.hpp"

using namespace std;

bool hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}

color ray_color(const ray& r) {
	if (hit_sphere(point3(0,0,-1), 0.5, r))
        return color(1, 0, 0);
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main() {
	ImageSize imgSize = {400, 200};
	Camera camera = Camera(imgSize, vec3(1., 0, 0), vec3(0, 1., 0));
	cout << camera.viewport_u << " " << camera.viewport_v << endl;
	cout << "P3\n" << imgSize.height << " " << imgSize.width << "\n255\n";
	for (int i = 0; i<1; i++) {
		clog << "\rScanlines remaining: " << imgSize.height - i << ' ' << flush;
		for (int j = 0; j<imgSize.width; j++) {
			cout << camera.viewport_u << " " << camera.getPixelPosition(i, j) << endl;

			vec3(1,3, 5) - camera.center;
			// write_color(cout, pixel_color);
		}
	}
	clog << "\nDone.\n";
	/* vec3 viewport_u = vec3(1., 0, 0);
	for (int i = 0; i<1; i++) {
		clog << "\rScanlines remaining: " << imgSize.height - i << ' ' << flush;
		for (int j = 0; j<imgSize.width; j++) {
			vec3 u = double(2*i-camera.size.height)/(2*camera.size.height) * viewport_u - vec3(5, 23,1);
			cout << viewport_u << " " << u << endl;
		}
	} */
	return 0;
}
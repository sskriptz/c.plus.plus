#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Vec3 {
    float x, y, z;
};

struct Sphere {
    Vec3 center;
    float radius;
};

struct Ray {
    Vec3 origin;
    Vec3 direction;
};

Vec3 add(Vec3 a, Vec3 b) {
    Vec3 sum;
    sum.x = a.x + b.x;
    sum.y = a.y + b.y;
    sum.z = a.z + b.z;
    return sum;
};

Vec3 subtract(Vec3 a, Vec3 b) {
    Vec3 difference;
    difference.x = a.x - b.x;
    difference.y = a.y - b.y;
    difference.z = a.z - b.z;
    return difference;
};

float calculate_length(Vec3 v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

Vec3 normalize(Vec3 v) {
    Vec3 normalized_vector;
    float length = calculate_length(v);
    normalized_vector.x = v.x / length;
    normalized_vector.y = v.y / length;
    normalized_vector.z = v.z / length;
    return normalized_vector;
}

Vec3 scale(Vec3 v, float s) {
    Vec3 scaled_vector;
    scaled_vector.x = v.x * s;
    scaled_vector.y = v.y * s;
    scaled_vector.z = v.z * s;
    return scaled_vector;
}

float dot_product(Vec3 a, Vec3 b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

float distance(Vec3 a, Vec3 b) {
    Vec3 new_v = subtract(b, a);
    return calculate_length(new_v);
}

Vec3 pointOnRay(Ray ray, float t) {
    Vec3 temp1 = scale(ray.direction, t);
    Vec3 temp2 = add(ray.origin, temp1);
    return temp2;
};

void printVector(Vec3 v) {
    cout << "(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;
}

bool calculateIntersections(Vec3 ray_origin, Vec3 ray_direction, Vec3 sphereCenter, float sphereRadius, float &t1, float &t2) {
    // Compute vector from sphere center to ray origin
    Vec3 L = subtract(ray_origin, sphereCenter);

    // Compute quadratic coefficients
    float a = dot_product(ray_direction, ray_direction);
    float b = 2 * dot_product(ray_direction, L);
    float c = dot_product(L, L) - sphereRadius * sphereRadius;

    // Get the discriminant
    float discriminant = b * b -  4 * a * c;

    // Check if there is no intersection
    if (discriminant < 0) {
        return false;
    }

    // Compute two t values so we know at what quantity extended from the origin through the direction vector, the ray hits the surface of the sphere
    float sqrtD = sqrt(discriminant);
    t1 = (-b - sqrtD) / (2 * a);
    t2 = (-b + sqrtD) / (2 * a);

    if (t1 > t2) {
        float temp = t1;
        t1 = t2;
        t2 = temp;
    }

    // Check if intersection is entirely behind the ray
    if (t2 < 0) {
        return false; // both points behind the ray
    }

    // clamp t1 to 0 if ray starts inside the sphere
    if (t1 < 0) {
        t1 = 0;
    }

    return true;
}

int main() {
    
    cout << "C++ RAYTRACING" << endl;

    float user_x, user_y, user_z;
    cout << "Enter the ray origin (x y z): ";
    cin >> user_x >> user_y >> user_z;

    float direction_x, direction_y, direction_z;
    cout << "Enter the values for the direction vector (x y z): ";
    cin >> direction_x >> direction_y >> direction_z;

    float sphere_x, sphere_y, sphere_z;
    cout << "Enter coordinates for the center of the sphere (x y z): ";
    cin >> sphere_x >> sphere_y >> sphere_z;

    float sphere_radius;
    cout << "Enter sphere radius: ";
    cin >> sphere_radius;

    Vec3 origin = {user_x, user_y, user_z};

    Ray user_ray;
    user_ray.origin = origin;
    user_ray.direction = normalize({direction_x, direction_y, direction_z});

    Sphere sphere;
    sphere.center = {sphere_x, sphere_y, sphere_z};
    sphere.radius = sphere_radius;


    float t1, t2;
    if (calculateIntersections(user_ray.origin, user_ray.direction, sphere.center, sphere.radius, t1, t2)) {
        Vec3 entryPoint = pointOnRay(user_ray, t1);
        Vec3 exitPoint  = pointOnRay(user_ray, t2);
        cout << "Ray enters the sphere at: "; printVector(entryPoint);
        cout << "Ray exits the sphere at: "; printVector(exitPoint);
        cout << "Distance inside the sphere: " << t2 - t1 << endl;
    } else {
        cout << "Ray misses the sphere!" << endl;
    }

    return 0;
}

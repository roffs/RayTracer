#include <gtest/gtest.h>

#include "Plane.h"
#include "Tuple.h"
#include "Ray.h"

TEST(Plane_test, normal_of_a_plane_is_constant_everywhere) {
    Plane plane;

    Tuple n1 = plane.normalAt(Tuple::Point(0.0f, 0.0f, 0.0f));
    Tuple n2 = plane.normalAt(Tuple::Point(10.0f, 0.0f, -10.0f));
    Tuple n3 = plane.normalAt(Tuple::Point(-5.0f, 0.0f, 150.0f));

    ASSERT_TRUE(n1 == Tuple::Vector(0.0f, 1.0f, 0.0f));
    ASSERT_TRUE(n2 == Tuple::Vector(0.0f, 1.0f, 0.0f));
    ASSERT_TRUE(n3 == Tuple::Vector(0.0f, 1.0f, 0.0f));
}

TEST(Plante_test, intersect_with_a_ray_parallel_to_the_plane) {
    Plane plane;
    Ray ray(Tuple::Point(0.0f, 10.0f, 0.0f), Tuple::Vector(0.0f, 0.0f, 1.0f));
    
    std::vector<Intersection> i = plane.intersects(ray);

    ASSERT_EQ(i.size(), 0);
}

TEST(Plante_test, intersect_with_a_ray_coplanar_to_the_plane) {
    Plane plane;
    Ray ray(Tuple::Point(0.0f, 0.0f, 0.0f), Tuple::Vector(0.0f, 0.0f, 1.0f));
    
    std::vector<Intersection> i = plane.intersects(ray);

    ASSERT_EQ(i.size(), 0);
}

TEST(Plante_test, ray_intersects_plan_from_above) {
    Plane plane;
    Ray ray(Tuple::Point(0.0f, 1.0f, 0.0f), Tuple::Vector(0.0f, -1.0f, 0.0f));
    
    std::vector<Intersection> i = plane.intersects(ray);

    ASSERT_EQ(i.size(), 1);
    ASSERT_EQ(i[0].t, 1.0f);
    ASSERT_TRUE(i[0].object == &plane);
}

TEST(Plante_test, ray_intersects_plan_from_below) {
    Plane plane;
    Ray ray(Tuple::Point(0.0f, -1.0f, 0.0f), Tuple::Vector(0.0f, 1.0f, 0.0f));
    
    std::vector<Intersection> i = plane.intersects(ray);

    ASSERT_EQ(i.size(), 1);
    ASSERT_EQ(i[0].t, 1.0f);
    ASSERT_TRUE(i[0].object == &plane);
}
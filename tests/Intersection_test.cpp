#include <gtest/gtest.h>
#include <limits>

#include "Intersection.h"
#include "Object.h"
#include "Sphere.h"
#include "Tuple.h"

TEST(Intersection_test, intersection_encapsulates_object_and_t) {
    Sphere sphere;

    float t(3.5f);

    Intersection intersection(sphere, t);

    ASSERT_TRUE(intersection.t == t);
    ASSERT_TRUE(intersection.object == &sphere);
}


TEST(Intersection_test, aggregating_intersections) {
    Sphere sphere;

    float t1(1.0f);
    float t2(2.0f);

    Intersection intersection1(sphere, t1);
    Intersection intersection2(sphere, t2);

    std::vector<Intersection> intersections {intersection1, intersection2};

    ASSERT_EQ(intersections[0].t, t1);
    ASSERT_EQ(intersections[1].t, t2);
}

TEST(Intersection_test, hit_returns_first_object_to_be_hitten_by_the_ray) {
    Sphere sphere; 

    Intersection i1(sphere, 1.0f);
    Intersection i2(sphere, 2.0f);
    std::vector<Intersection> intersections {i1, i2};

    Intersection i = hit(intersections);
    ASSERT_TRUE(i == i1);
}

TEST(Intersection_test, hit_returns_first_positive_object_to_be_hitten_by_the_ray) {
    Sphere sphere; 

    Intersection i1(sphere, -1.0f);
    Intersection i2(sphere, 1.0f);
    std::vector<Intersection> intersections {i1, i2};

    Intersection i = hit(intersections);
    ASSERT_TRUE(i == i2);
}

TEST(Intersection_test, when_all_intersections_have_negative_t_returns_infinity) {
    Sphere sphere; 

    Intersection i1(sphere, -1.0f);
    Intersection i2(sphere, -2.0f);
    std::vector<Intersection> intersections {i1, i2};

    Intersection i = hit(intersections);
    ASSERT_TRUE(i.t == std::numeric_limits<float>::infinity());
}

TEST(Intersection_test, returns_lowest_nonnegative_intersection) {
    Sphere sphere; 

    Intersection i1(sphere, 5.0f);
    Intersection i2(sphere, 7.0f);
    Intersection i3(sphere, -3.0f);
    Intersection i4(sphere, 2.0f);
    std::vector<Intersection> intersections {i1, i2, i3, i4};

    Intersection i = hit(intersections);
    ASSERT_TRUE(i == i4);
}

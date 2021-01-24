#include <gtest/gtest.h>

#include "Surface.h"
#include "Sphere.h"
#include "Tuple.h"

TEST(Surface_test, surface_id_gets_incremented_by_each_one_created) {

    Sphere sphere1;
    Sphere sphere2;

    ASSERT_TRUE(sphere1.id + 1 == sphere2.id);
}
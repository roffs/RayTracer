#include <gtest/gtest.h>

#include "Object.h"
#include "Sphere.h"
#include "Tuple.h"

TEST(Object_test, object_id_gets_incremented_by_each_one_created) {

    Sphere sphere1;
    Sphere sphere2;

    ASSERT_TRUE(sphere1.id + 1 == sphere2.id);
}
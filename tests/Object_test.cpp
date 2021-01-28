#include <gtest/gtest.h>

#include "Object.h"
#include "Sphere.h"
#include "Tuple.h"

TEST(Object_test, object_id_gets_incremented_by_each_one_created) {

    Object* sphere1 = new Sphere();
    Object* sphere2 = new Sphere();

    ASSERT_TRUE(sphere1->id + 1 == sphere2->id);
}

TEST(Object_test, created_object_has_default_material) {

    Object* sphere1 = new Sphere();
    
    ASSERT_TRUE(sphere1->material == Material());
}
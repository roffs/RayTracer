#include <gtest/gtest.h>

#include "World.h"
#include "Light.h"
#include "Sphere.h"
#include "Transformations.h"

TEST(World_test, constructor_creates_world_with_no_objects_or_lights) {
    World world;

    ASSERT_EQ(world.objects.size(), 0);
    ASSERT_EQ(world.lights.size(), 0);
}

TEST(World_test, default_world_creates_world_with_specified_objects_and_lights) {
    Tuple lightPosition = Tuple::Point(-10.0f, 10.0f, -10.0f);
    Color lightColor(1.0f, 1.0f, 1.0f);

    Color expectedColor(0.8f, 1.0f, 0.6f);

    World world = defaultWorld();

    ASSERT_TRUE(world.objects[0]->material.color == expectedColor);
    ASSERT_EQ(world.objects[0]->material.diffuse, 0.7f);
    ASSERT_EQ(world.objects[0]->material.specular, 0.2f);

    ASSERT_TRUE(world.objects[1]->transform == scaling(0.5f, 0.5f, 0.5f));

    ASSERT_TRUE(world.lights[0]->position == lightPosition);
    ASSERT_TRUE(world.lights[0]->intensity == lightColor);
}
#include <gtest/gtest.h>
#include <cmath>

#include "Material.h"
#include "Color.h"
#include "Light.h"

TEST(Material_test, creates_default_material) {
    Material material;

    Color expected(1.0f, 1.0f, 1.0f);

    ASSERT_TRUE(material.color == expected);
    ASSERT_EQ(material.ambient, 0.1f);
    ASSERT_EQ(material.diffuse, 0.9f);
    ASSERT_EQ(material.specular, 0.9f);
    ASSERT_EQ(material.shininess, 200.0f);
}

TEST(Material_test, material_may_have_color_reassigned) {
    Material material;

    Color newColor(0.5f, 0.2f, 1.0f);

    material.color = newColor;

    ASSERT_TRUE(material.color == newColor);
    ASSERT_EQ(material.ambient, 0.1f);
    ASSERT_EQ(material.diffuse, 0.9f);
    ASSERT_EQ(material.specular, 0.9f);
    ASSERT_EQ(material.shininess, 200.0f);
}

TEST(Material_test, two_materials_are_equal_if_they_have_the_same_properties) {
    Material material1;
    Material material2;
    Material material3;

    material3.diffuse = 0.3f;

    ASSERT_TRUE(material1 == material2);
    ASSERT_FALSE(material1 == material3);
    
    ASSERT_TRUE(material1 != material3);
    ASSERT_FALSE(material1 != material2);
}

TEST(Lighting_test, lighting_with_the_eye_between_the_light_and_the_object) {
    Material material;
    Tuple position = Tuple::Point(0.0f, 0.0f, 0.0f);

    Tuple eyeDirection = Tuple::Vector(0.0f, 0.0f, -1.0f);
    Tuple normal = Tuple::Vector(0.0f, 0.0f, -1.0f);

    Tuple lightPosition = Tuple::Point(0.0f, 0.0f, -10.0f);
    Color lightColor(1.0f, 1.0f, 1.0f);
    Light light(lightPosition, lightColor);

    Color result = lighting(material, light, position, eyeDirection, normal);

    Color expected(1.9f, 1.9f, 1.9f);
    ASSERT_TRUE(result == expected);
}

TEST(Lighting_test, lighting_with_the_eye_between_the_light_and_the_object_with_eye_offset_45_degree) {
    Material material;
    Tuple position = Tuple::Point(0.0f, 0.0f, 0.0f);

    Tuple eyeDirection = Tuple::Vector(0.0f, sqrt(2.0f)/2.0f, sqrt(2.0f)/2.0f);
    Tuple normal = Tuple::Vector(0.0f, 0.0f, -1.0f);

    Tuple lightPosition = Tuple::Point(0.0f, 0.0f, -10.0f);
    Color lightColor(1.0f, 1.0f, 1.0f);
    Light light(lightPosition, lightColor);

    Color result = lighting(material, light, position, eyeDirection, normal);
    
    Color expected(1.0f, 1.0f, 1.0f);
    ASSERT_TRUE(result == expected);
}

TEST(Lighting_test, lighting_with_the_eye_between_the_light_and_the_object_with_light_offset_45_degree) {
    Material material;
    Tuple position = Tuple::Point(0.0f, 0.0f, 0.0f);

    Tuple eyeDirection = Tuple::Vector(0.0f, 0.0f, -1.0f);
    Tuple normal = Tuple::Vector(0.0f, 0.0f, -1.0f);

    Tuple lightPosition = Tuple::Point(0.0f, 10.0f, -10.0f);
    Color lightColor(1.0f, 1.0f, 1.0f);
    Light light(lightPosition, lightColor);

    Color result = lighting(material, light, position, eyeDirection, normal);
    Color expected(0.7364f, 0.7364f, 0.7364f);
    ASSERT_TRUE(result == expected);
}

TEST(Lighting_test, lighting_with_the_eye_in_the_path_of_the_reflection_vector) {
    Material material;
    Tuple position = Tuple::Point(0.0f, 0.0f, 0.0f);

    Tuple eyeDirection = Tuple::Vector(0.0f, -sqrt(2.0f)/2.0f, -sqrt(2.0f)/2.0f);
    Tuple normal = Tuple::Vector(0.0f, 0.0f, -1.0f);

    Tuple lightPosition = Tuple::Point(0.0f, 10.0f, -10.0f);
    Color lightColor(1.0f, 1.0f, 1.0f);
    Light light(lightPosition, lightColor);

    Color result = lighting(material, light, position, eyeDirection, normal);

    Color expected(1.6364f, 1.6364f, 1.6364f);
    ASSERT_TRUE(result == expected);
}

TEST(Lighting_test, lighting_with_the_light_behind_the_object) {
    Material material;
    Tuple position = Tuple::Point(0.0f, 0.0f, 0.0f);

    Tuple eyeDirection = Tuple::Vector(0.0f, 0.0f, -1.0f);
    Tuple normal = Tuple::Vector(0.0f, 0.0f, -1.0f);

    Tuple lightPosition = Tuple::Point(0.0f, 0.0f, 10.0f);
    Color lightColor(1.0f, 1.0f, 1.0f);
    Light light(lightPosition, lightColor);

    Color result = lighting(material, light, position, eyeDirection, normal);

    Color expected(0.1f, 0.1f, 0.1f);
    ASSERT_TRUE(result == expected);
}
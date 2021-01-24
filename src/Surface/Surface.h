#pragma once

class Surface {
public:
    int id;
    static int currentId; 
    Surface();

    bool operator==(Surface const& other);
};
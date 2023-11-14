#ifndef ASTEROIDBELTGEN
#define ASTEROIDBELTGEN

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>

using namespace godot;

class AsteroidBeltGenerator : public Node3D
{
    GDCLASS(AsteroidBeltGenerator, Node3D);

protected: static void _bind_methods();

public:
    Ref<PackedScene> asteroid_scene;
    int quantity = 10;
    float max_radius = 100;
    float min_radius = 50;
    float max_height = 10;
    float min_height = -10;
    bool generate = false;
    bool clear_all = false;

    void set_quantity(int _quantity);
    int get_quantity();

    void set_asteroid_scene(Ref<PackedScene> scene);
    Ref<PackedScene> get_asteroid_scene();
    void set_max_radius(float _radius);
    float get_max_radius();
    void set_min_radius(float _radius);
    float get_min_radius();
    void set_max_height(float _height);
    float get_max_height();       
    void set_min_height(float _height);
    void set_generate(bool _generate);
    bool get_generate();
    void set_clear_all(bool _clear);
    bool get_clear_all();
    float get_min_height();
    void generate_asteroids();

    AsteroidBeltGenerator();
    ~AsteroidBeltGenerator();
};

#endif
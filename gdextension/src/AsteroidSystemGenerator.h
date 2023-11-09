#ifndef ASTEROIDSYSTEMGENERATOR_H
#define ASTEROIDSYSTEMGENERATOR_H 

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/rid.hpp>
#include <godot_cpp/templates/vector.hpp>

namespace godot {

class AsteroidSystemGenerator : public Node3D{
    GDCLASS(AsteroidSystemGenerator,Node3D);


    public:
        //the amountof asteroid to generate
        int asteroid_quantity;
        //the radius of the ring
        int radius;
        //the height range of the ring from
        double ring_height;
        //the 
        double ring_thickness;

        Vector<RID> asteroids;

        AsteroidSystemGenerator();
        ~AsteroidSystemGenerator();
        void generate_asteroids();
        void set_radius();
        int get_radius();
        void set_asteroid_count(int q);
        int get_asteroid_count();



    protected:
        static void _bind_methods();


};
}

#endif
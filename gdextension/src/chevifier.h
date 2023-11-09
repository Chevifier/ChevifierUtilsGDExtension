#ifndef CHEVIFIER_H
#define CHEVIFIER_H

#include <godot_cpp/classes/node3d.hpp>

using namespace godot;

class Chevifier : public Node3D {
    GDCLASS(Chevifier,Node3D);

    public: void _start_test();

    protected: static void _bind_methods();
};

#endif
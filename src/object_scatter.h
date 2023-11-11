#ifndef OBJECTSCATTER
#define OBJECTSCATTER

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>

using namespace godot;

class ObjectScatter : public Node3D {
    GDCLASS(ObjectScatter,Node3D);

    protected:
        static void _bind_methods();
    public:
        Ref<PackedScene> object;
        int object_count;
        Vector3 distance;
        bool scatter;
    public:
        void scatter_objects();
        void set_scatter_objects(bool _scatter);
        bool get_scatter_objects();

        void set_object(Ref<PackedScene> _object);
        Ref<PackedScene> get_object();

        void set_count(int count);
        int get_count();

        void set_distance(Vector3 dis);
        Vector3 get_distance();


        ObjectScatter();
        ~ObjectScatter();
};
#endif
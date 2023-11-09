#ifndef OBJECTSCATTER
#define OBJECTSCATTER


#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>

using namespace godot;

class ObjectScatter : public Node3D {
    GDCLASS(ObjectScatter,Node3D);

    protected:
        static void _bind_methods();
    private:
        NodePath object_path;
        int object_count =0;
        Vector3 distance;
    public:
        void scatter_objects();

        void set_object(NodePath _object);
        NodePath get_object();

        void set_count(int count);
        int get_count();

        void set_distance(Vector3 dis);
        Vector3 get_distance();


        ObjectScatter();
        ~ObjectScatter();







};

#endif
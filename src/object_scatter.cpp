#include "object_scatter.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void ObjectScatter::_bind_methods(){
    ClassDB::bind_method(D_METHOD("scatter_objects"), &ObjectScatter::scatter_objects);
    ClassDB::bind_method(D_METHOD("get_object"), &ObjectScatter::get_object);
    ClassDB::bind_method(D_METHOD("set_object"), &ObjectScatter::set_object);
    ClassDB::bind_method(D_METHOD("get_count"), &ObjectScatter::get_count);
    ClassDB::bind_method(D_METHOD("set_count"), &ObjectScatter::set_count);
    ClassDB::bind_method(D_METHOD("get_distance"), &ObjectScatter::get_distance);
    ClassDB::bind_method(D_METHOD("set_distance"), &ObjectScatter::set_distance);
    ClassDB::bind_method(D_METHOD("set_scatter_objects"), &ObjectScatter::set_scatter_objects);
    ClassDB::bind_method(D_METHOD("get_scatter_objects"), &ObjectScatter::get_scatter_objects);
    
    ClassDB::add_property("ObjectScatter",PropertyInfo(Variant::OBJECT,"Object",PROPERTY_HINT_RESOURCE_TYPE,"PackedScene"),"set_object","get_object");
    ClassDB::add_property("ObjectScatter",PropertyInfo(Variant::INT,"Count",PROPERTY_HINT_NONE),"set_count","get_count");
    ClassDB::add_property("ObjectScatter",PropertyInfo(Variant::VECTOR3,"Distance",PROPERTY_HINT_NONE),"set_distance","get_distance");
    ClassDB::add_property("ObjectScatter",PropertyInfo(Variant::BOOL,"Scatter_Object",PROPERTY_HINT_NONE),"set_scatter_objects","get_scatter_objects");
}

ObjectScatter::ObjectScatter(){
    object_count = 1;
    distance = Vector3(10,10,10);
    scatter = false;
}

ObjectScatter::~ObjectScatter(){}

void ObjectScatter::set_object(Ref<PackedScene> _object){
    object = _object;
}

Ref<PackedScene> ObjectScatter::get_object(){
    return object;
}

void ObjectScatter::set_count(int count){
    object_count = count;
}

int ObjectScatter::get_count(){
    return object_count;
}

void ObjectScatter::set_distance(Vector3 dis){
    distance = dis;
}

Vector3 ObjectScatter::get_distance(){
    return distance;
}

void ObjectScatter::scatter_objects(){
   for(int i = 0; i < object_count; i++){
    Node *scene;
    Node *temp = object->instantiate();
    Node3D *node = Object::cast_to<Node3D>(temp);
    if (!node) {
        // Not a 3d scene, clean up after yourself
        temp->queue_free();
        UtilityFunctions::print("Not a 3D Scene! returning...");
        return;
    }
    // It is a 3d scene, assign it to the scene
    scene = node;
    float x = UtilityFunctions::randf() * distance.x;
    float y = UtilityFunctions::randf() * distance.y;
    float z = UtilityFunctions::randf() * distance.z;
    Vector3 pos = Vector3(x,y,z);
    add_child(scene);
    Object::cast_to<Node3D>(scene)->set_position(pos);
    scene->set_owner(get_parent());
   }

}

void ObjectScatter::set_scatter_objects(bool _scatter){
    //scatter the objects then return
    scatter_objects();
    scatter = false;
}

bool ObjectScatter::get_scatter_objects(){
    return scatter;
}


#include "object_scatter.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/variant/utility_functions.hpp>

void ObjectScatter::_bind_methods(){
    ClassDB::bind_method(D_METHOD("scatter_objects"), &ObjectScatter::scatter_objects);
    ClassDB::bind_method(D_METHOD("get_object"), &ObjectScatter::get_object);
    ClassDB::bind_method(D_METHOD("set_object"), &ObjectScatter::set_object);
    ClassDB::bind_method(D_METHOD("get_count"), &ObjectScatter::get_count);
    ClassDB::bind_method(D_METHOD("set_count"), &ObjectScatter::set_count);
    ClassDB::bind_method(D_METHOD("get_distance"), &ObjectScatter::get_distance);
    ClassDB::bind_method(D_METHOD("set_distance"), &ObjectScatter::set_distance);
    

    ClassDB::add_property("ObjectScatter",PropertyInfo(Variant::NODE_PATH,"Object",PROPERTY_HINT_NONE),"set_object","get_object");
    ClassDB::add_property("ObjectScatter",PropertyInfo(Variant::INT,"Count",PROPERTY_HINT_NONE),"set_count","get_count");
    ClassDB::add_property("ObjectScatter",PropertyInfo(Variant::VECTOR3,"Distance",PROPERTY_HINT_NONE),"set_distance","get_distance");

}
ObjectScatter::ObjectScatter(){
    object_count = 1;
    object_path = "";
    distance = Vector3(10,10,10);
    

}

ObjectScatter::~ObjectScatter(){}

void ObjectScatter::set_object(NodePath _object){
    object_path = _object;
}

NodePath ObjectScatter::get_object(){
    return object_path;
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

}


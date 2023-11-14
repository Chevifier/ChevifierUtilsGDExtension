
#include "AstroidBeltGenerator.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void AsteroidBeltGenerator::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_asteroid_scene"), &AsteroidBeltGenerator::set_asteroid_scene);
    ClassDB::bind_method(D_METHOD("get_asteroid_scene"), &AsteroidBeltGenerator::get_asteroid_scene);

    ClassDB::bind_method(D_METHOD("set_quantity"), &AsteroidBeltGenerator::set_quantity);
    ClassDB::bind_method(D_METHOD("get_quantity"), &AsteroidBeltGenerator::get_quantity);

    ClassDB::bind_method(D_METHOD("set_min_radius"), &AsteroidBeltGenerator::set_min_radius);
    ClassDB::bind_method(D_METHOD("get_min_radius"), &AsteroidBeltGenerator::get_min_radius);

    ClassDB::bind_method(D_METHOD("set_max_radius"), &AsteroidBeltGenerator::set_max_radius);
    ClassDB::bind_method(D_METHOD("get_max_radius"), &AsteroidBeltGenerator::get_max_radius);

    ClassDB::bind_method(D_METHOD("set_min_height"), &AsteroidBeltGenerator::set_min_height);
    ClassDB::bind_method(D_METHOD("get_min_height"), &AsteroidBeltGenerator::get_min_height);

    ClassDB::bind_method(D_METHOD("set_max_height"), &AsteroidBeltGenerator::set_max_height);
    ClassDB::bind_method(D_METHOD("get_max_height"), &AsteroidBeltGenerator::get_max_height);

    ClassDB::bind_method(D_METHOD("set_generate"), &AsteroidBeltGenerator::set_generate);
    ClassDB::bind_method(D_METHOD("get_generate"), &AsteroidBeltGenerator::get_generate);

    ClassDB::bind_method(D_METHOD("set_clear_all"), &AsteroidBeltGenerator::set_clear_all);
    ClassDB::bind_method(D_METHOD("get_clear_all"), &AsteroidBeltGenerator::get_clear_all);

    ClassDB::bind_method(D_METHOD("generate_asteroids"), &AsteroidBeltGenerator::generate_asteroids);
    // GlassDB::bind_method(D_METHOD("get_val"),&AsteroidBeltGenerator::get_min_radius);
    ClassDB::add_property("AsteroidBeltGenerator",PropertyInfo(Variant::OBJECT,"Asteroid",PROPERTY_HINT_RESOURCE_TYPE,"PackedScene"),"set_asteroid_scene","get_asteroid_scene");
    ClassDB::add_property("AsteroidBeltGenerator",PropertyInfo(Variant::INT,"quantity",PROPERTY_HINT_NONE),"set_quantity","get_quantity");
    ClassDB::add_property("AsteroidBeltGenerator",PropertyInfo(Variant::FLOAT,"min_radius",PROPERTY_HINT_NONE),"set_min_radius","get_min_radius");
    ClassDB::add_property("AsteroidBeltGenerator",PropertyInfo(Variant::FLOAT,"max_radius",PROPERTY_HINT_NONE),"set_max_radius","get_max_radius");
    ClassDB::add_property("AsteroidBeltGenerator",PropertyInfo(Variant::FLOAT,"min_height",PROPERTY_HINT_NONE),"set_min_height","get_min_height");
    ClassDB::add_property("AsteroidBeltGenerator",PropertyInfo(Variant::FLOAT,"max_height",PROPERTY_HINT_NONE),"set_max_height","get_max_height");
    ClassDB::add_property("AsteroidBeltGenerator",PropertyInfo(Variant::BOOL,"generate",PROPERTY_HINT_NONE),"set_generate","get_generate");
    ClassDB::add_property("AsteroidBeltGenerator",PropertyInfo(Variant::BOOL,"clear_all",PROPERTY_HINT_NONE),"set_clear_all","get_clear_all");
}

AsteroidBeltGenerator::AsteroidBeltGenerator(){}

AsteroidBeltGenerator::~AsteroidBeltGenerator(){}


void AsteroidBeltGenerator::set_min_radius(float _radius){
    min_radius = _radius;
}
float AsteroidBeltGenerator::get_min_radius(){
    return min_radius;
}
void AsteroidBeltGenerator::set_max_radius(float _radius){
    max_radius = _radius;
}
float AsteroidBeltGenerator::get_max_radius(){
    return max_radius;
}
void AsteroidBeltGenerator::set_max_height(float _height){
    max_height = _height;
}
float AsteroidBeltGenerator::get_max_height(){
    return max_height;
}
void AsteroidBeltGenerator::set_min_height(float _height){
    min_height = _height;
}
float AsteroidBeltGenerator::get_min_height(){
    return min_height;
}
void AsteroidBeltGenerator::set_quantity(int _quantity){
    quantity = _quantity;
}
int AsteroidBeltGenerator::get_quantity(){
    return quantity;
} 

void AsteroidBeltGenerator::set_asteroid_scene(Ref<PackedScene> scene){
    asteroid_scene = scene;
}

Ref<PackedScene> AsteroidBeltGenerator::get_asteroid_scene(){
    return asteroid_scene;
}

void AsteroidBeltGenerator::set_generate(bool _generate){
    generate_asteroids();
    generate = false;
}

bool AsteroidBeltGenerator::get_generate(){
    return generate;
}

void AsteroidBeltGenerator::set_clear_all(bool _clear){
    TypedArray<Node> children = get_children();
    for(int i = 0; i<children.size();i++){
        Variant c = children[i];
        Node *nc = cast_to<Node>(c);
        nc->queue_free();
    }
    clear_all = false;
}

bool AsteroidBeltGenerator::get_clear_all(){
    return clear_all;
}
void AsteroidBeltGenerator::generate_asteroids(){
    //check if scene is 3D
    Node *temp = asteroid_scene->instantiate();
    Node3D *node = Object::cast_to<Node3D>(temp);
    if (!node) {
        // Not a 3d scene, clean up after yourself
        temp->queue_free();
        UtilityFunctions::print("Not a 3D Scene! returning...");
        return;
    }else{
        temp->queue_free();
    }
    ////////////////////////////
    for(int i = 0; i < quantity; i++){
        float angle = UtilityFunctions::randf() * Math_TAU;
        float radius = UtilityFunctions::randf_range(min_radius,max_radius);
        float x = UtilityFunctions::sin(angle) * radius;
        float y = UtilityFunctions::randf_range(min_height,max_height);
        float z = UtilityFunctions::cos(angle) * radius;
        Vector3 position = Vector3(x,y,z);

        Node *scene = asteroid_scene->instantiate();
        // It is a 3d scene, assign it to the scene
        add_child(scene);
        Object::cast_to<Node3D>(scene)->set_position(position);
        scene->set_owner(get_parent());
    }

}
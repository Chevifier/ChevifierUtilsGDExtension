#include "chevifier.h"

//convenience function such as print and cos sin etc
#include <godot_cpp/variant/utility_functions.hpp>

void Chevifier::_start_test(){
    UtilityFunctions::print("Hello World from Chevifier");

}

void Chevifier::_bind_methods(){
    ClassDB::bind_method(D_METHOD("start_test"), &Chevifier::_start_test);
}
#include "LooperAudioStream.h"

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void LooperAudioStream::_bind_methods(){
    //Add methods for the public access class 
    ClassDB::bind_method(D_METHOD("set_loop_amount"), &LooperAudioStream::set_loop_amount);
    ClassDB::bind_method(D_METHOD("get_loop_amount"), &LooperAudioStream::get_loop_amount);

    ClassDB::bind_method(D_METHOD("set_loop_start"), &LooperAudioStream::set_loop_start);
    ClassDB::bind_method(D_METHOD("get_loop_start"), &LooperAudioStream::get_loop_start);

    ClassDB::bind_method(D_METHOD("set_loop_end"), &LooperAudioStream::set_loop_end);
    ClassDB::bind_method(D_METHOD("get_loop_end"), &LooperAudioStream::get_loop_end);

    ClassDB::bind_method(D_METHOD("set_looping"), &LooperAudioStream::set_looping);
    ClassDB::bind_method(D_METHOD("get_looping"), &LooperAudioStream::get_looping);
    
    ClassDB::bind_method(D_METHOD("reset_loop"),&LooperAudioStream::reset_loop);


    ClassDB::bind_method(D_METHOD("get_audio_length_in_minutes"), &LooperAudioStream::get_audio_length_in_minutes);

    //Add properties for the editor window
    ClassDB::add_property("LooperAudioStream", PropertyInfo(Variant::INT,"loop_amount", PROPERTY_HINT_NONE,
        "How many times to loop"), "set_loop_amount", "get_loop_amount");

    ClassDB::add_property("LooperAudioStream", PropertyInfo(Variant::FLOAT, "loop_start",PROPERTY_HINT_NONE,
        "Starting point of the loop"),"set_loop_start","get_loop_start");

    ClassDB::add_property("LooperAudioStream", PropertyInfo(Variant::FLOAT, "loop_end",PROPERTY_HINT_NONE,
        "Starting point of the loop"),"set_loop_end","get_loop_end");
    
    ClassDB::add_property("LooperAudioStream", PropertyInfo(Variant::BOOL, "looping",PROPERTY_HINT_NONE,
        "set if the audio should loop"),"set_looping","get_looping");
    //Create a signal and set variables it passes can add more Properties with "," seperation
    ADD_SIGNAL(MethodInfo("loop_occured", PropertyInfo(Variant::INT,"loop_idx")));

};

LooperAudioStream::LooperAudioStream(){
    loop_start = 0.0;
    loop_end = 0.0;
    loop_amount = 0;
    current_loop = 0;
    looping = false;
};

LooperAudioStream::~LooperAudioStream(){

}

String LooperAudioStream::get_audio_length_in_minutes(){
    
    double length = 130; //TO-DO get stream length
    int minutes = UtilityFunctions::floor(length/60);
    int seconds = length - (minutes * 60);
    return UtilityFunctions::var_to_str(minutes) + ":" + UtilityFunctions::var_to_str(seconds);
    
}

void LooperAudioStream::_process(float delta){
    if(looping == false){
        return;
    };

    if (current_loop < loop_amount){

        if (get_playback_position() >= loop_end){
            emit_signal("loop_occured",current_loop);
            seek(loop_start);
            current_loop++;
        }; 

    }

    if (is_playing() == false){
        if(current_loop != 0) current_loop = 0;
    }
};

void LooperAudioStream::set_loop_amount(int loops){
    loop_amount = loops;
}
int LooperAudioStream::get_loop_amount(){
    return loop_amount;
}

void LooperAudioStream::set_loop_start(float _loop_start){
    loop_start = _loop_start;
}
float LooperAudioStream::get_loop_start(){
    return loop_start;
}

void LooperAudioStream::set_loop_end(float _loop_end){
    loop_end = _loop_end;
}
float LooperAudioStream::get_loop_end(){
    return loop_end;
}

void LooperAudioStream::set_looping(bool is_looping){
    looping = is_looping;
}
bool LooperAudioStream::get_looping(){
    return looping;
}

void LooperAudioStream::reset_loop(){
    current_loop = 0;
    stop();

}

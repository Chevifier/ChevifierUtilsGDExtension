#include "register_types.h"

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

//include the header files here 
#include "chevifier.h"
#include "LooperAudioStream.h"
#include "object_scatter.h"
#include "AstroidBeltGenerator.h"

using namespace godot;

void initialize_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	//Register classes here
	ClassDB::register_class<Chevifier>();
	ClassDB::register_class<LooperAudioStream>();
	ClassDB::register_class<ObjectScatter>();
	ClassDB::register_class<AsteroidBeltGenerator>();
}

void uninitialize_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

//C code to initialize 
extern "C" {
// Initialization. library_init required in gdextension file
GDExtensionBool GDE_EXPORT library_init(GDExtensionInterfaceGetProcAddress p_interface, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

	init_obj.register_initializer(initialize_module);
	init_obj.register_terminator(uninitialize_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}

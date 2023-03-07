#ifndef LOOPERAUDIOSTREAM
#define LOOPERAUDIOSTREAM

#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/classes/audio_stream.hpp>

using namespace godot;

class LooperAudioStream : public AudioStreamPlayer {
    GDCLASS(LooperAudioStream,AudioStreamPlayer);


    protected:
        static void _bind_methods();
    private:
        float loop_start;
        float loop_end;
        int loop_amount;
        bool looping;
        int current_loop;
    public:
        LooperAudioStream();
        ~LooperAudioStream();
        void _process(float delta);
        void set_loop_amount(int loops);
        int get_loop_amount();
        void set_loop_start(const float _loop_start);
        float get_loop_start();
        void set_loop_end(const float _loop_end);
        float get_loop_end();
        void set_looping(bool is_looping);
        bool get_looping();
        void reset_loop();
        String get_audio_length_in_minutes();


};

#endif